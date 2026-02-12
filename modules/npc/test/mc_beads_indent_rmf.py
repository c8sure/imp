#!/usr/bin/env python
"""
Monte Carlo with 10 beads and slab-with-spherical-indent membrane restraints.
Uses PMI (IMP.pmi) for topology, DOF, Monte Carlo, and RMF output.

  1. Place 10 beads at random in a box around the dome (PMI topology).
  2. Set up the three membrane restraints (surface location, EV, MBM).
  3. Run 1000 Monte Carlo steps via IMP.pmi.macros.ReplicaExchange.
  4. Save frames to RMF in rmfs/ (membrane geometry included).

Usage:
  python mc_beads_indent_rmf.py [--steps N] [--out-dir DIR] [--no-rmf]

Requires: IMP, IMP.pmi, IMP.rmf, RMF. Without RMF use --no-rmf (MC only, no movie).

ChimeraX: open rmfs/0.rmf3, then "rmf readtraj #X", then "coordset slider #X" to play.
"""
import argparse
import random
import IMP
import IMP.algebra
import IMP.core
import IMP.npc
import IMP.container
import IMP.atom

try:
    import RMF
    import IMP.rmf
    HAS_RMF = True
except ImportError:
    HAS_RMF = False
HAS_IMP_ATOM = hasattr(IMP, 'atom')

if HAS_RMF:
    import IMP.pmi
    import IMP.pmi.topology
    import IMP.pmi.tools
    import IMP.pmi.dof
    import IMP.pmi.macros

#--------------------------------------------------------------------------
class System_builder:
    def __init__(self, ntype, copy_numbers, chain_ids, sequences_type, colors):
        self.ntype = ntype # number of particle types
        self.copy_numbers = copy_numbers # copy number for each particle type
        self.chain_ids = chain_ids # chain id for each copy of each particle type
        self.colors = colors # color for each particle type
        self.seq_type = sequences_type # sequence for each particle type
        
    def build_system(self):
        mdl = IMP.Model()
        system = IMP.pmi.topology.System(mdl)
        state = system.create_state()
        # create a list of the particles
        parts = []
        
        for i in range(self.ntype):
            name = f"prot_{i+1}"
            particle = state.create_molecule(name=name, sequence=self.seq_type[i], chain_id=self.chain_ids[i])
            color = self.colors[i]
            particle.add_representation(resolutions=[len(self.seq_type[i])], color=color)
            parts.append(particle)
            for j in range(self.copy_numbers[i]-1):
                cloned_particle = particle.create_clone(chain_id=self.chain_ids[j+1])
                parts.append(cloned_particle)

        return mdl, system, parts
#--------------------------------------------------------------------------
# Class for the scoring function, at this point just some excluded volume
#--------------------------------------------------------------------------
class scoring_function():
    def __init__(self, system, model, hierarchy, output_objects, parts, ntype, copy_numbers):
        self.output_objects = output_objects
        self.system = system
        self.parts = parts
        self.ntype = ntype
        self.copy_numbers = copy_numbers
        self.m = model
        self.hier = hierarchy

    def add_excluded_volume_restraint(self):
        evr = IMP.pmi.restraints.stereochemistry.ExcludedVolumeSphere(
            included_objects = self.parts,
            resolution = 1)
        evr.add_to_model()
        self.output_objects.append(evr)
        print("added excluded volume restraint", evr)
        
        return evr, self.output_objects
    
    def add_pair_distance_restraint(self, aa_distance=40.0, ab_distance=30.0, bc_distance=25.0):
        """Add distance restraints between different particle types with specified thresholds
        
        Args:
            aa_distance: Maximum distance for A-A interactions (default 40.0 Å)
            ab_distance: Maximum distance for A-B interactions (default 30.0 Å) 
            bc_distance: Maximum distance for B-C interactions (default 25.0 Å)
        """
        pairs = []
        
        # A-A type interactions (prot_1 with prot_1)
        print("Adding A-A interactions...")
        for i in range(self.copy_numbers[0]):
            for j in range(i + 1, self.copy_numbers[0]):
                tuple1 = (1, 1, "prot_1", i)
                tuple2 = (1, 1, "prot_1", j)
                
                dr = IMP.pmi.restraints.basic.DistanceRestraint(
                    self.hier, 
                    tuple1, 
                    tuple2, 
                    distancemin=0.0,
                    distancemax=aa_distance,
                    kappa=10.0,
                    resolution=1.0,
                    label=f"dist_AA_prot_1_{i}_{j}"
                )
                dr.add_to_model()
                self.output_objects.append(dr)
                pairs.append(("A-A", i, j))
                print(f"Added A-A distance restraint: prot_1 copy {i} - copy {j}, max distance: {aa_distance} Å")
        
        # A-B type interactions (prot_1 with prot_2)
        print("Adding A-B interactions...")
        for i in range(self.copy_numbers[0]):  # A particles (prot_1)
            for j in range(self.copy_numbers[1]):  # B particles (prot_2)
                tuple1 = (1, 1, "prot_1", i)
                tuple2 = (1, 1, "prot_2", j)
                
                dr = IMP.pmi.restraints.basic.DistanceRestraint(
                    self.hier,
                    tuple1,
                    tuple2,
                    distancemin=0.0,
                    distancemax=ab_distance,
                    kappa=10.0,
                    resolution=1.0,
                    label=f"dist_AB_prot_1_{i}_prot_2_{j}"
                )
                dr.add_to_model()
                self.output_objects.append(dr)
                pairs.append(("A-B", i, j))
                print(f"Added A-B distance restraint: prot_1 copy {i} - prot_2 copy {j}, max distance: {ab_distance} Å")
        
        # B-C type interactions (prot_2 with prot_3)
        print("Adding B-C interactions...")
        for i in range(self.copy_numbers[1]):  # B particles (prot_2)
            for j in range(self.copy_numbers[2]):  # C particles (prot_3)
                tuple1 = (1, 1, "prot_2", i)
                tuple2 = (1, 1, "prot_3", j)
                
                dr = IMP.pmi.restraints.basic.DistanceRestraint(
                    self.hier,
                    tuple1,
                    tuple2,
                    distancemin=0.0,
                    distancemax=bc_distance,
                    kappa=10.0,
                    resolution=1.0,
                    label=f"dist_BC_prot_2_{i}_prot_3_{j}"
                )
                dr.add_to_model()
                self.output_objects.append(dr)
                pairs.append(("B-C", i, j))
                print(f"Added B-C distance restraint: prot_2 copy {i} - prot_3 copy {j}, max distance: {bc_distance} Å")
        
        # Summary
        aa_count = len([p for p in pairs if p[0] == "A-A"])
        ab_count = len([p for p in pairs if p[0] == "A-B"])
        bc_count = len([p for p in pairs if p[0] == "B-C"])
        
        print(f"\nSummary of distance restraints added:")
        print(f"A-A restraints: {aa_count} (max distance: {aa_distance} Å)")
        print(f"A-B restraints: {ab_count} (max distance: {ab_distance} Å)")
        print(f"B-C restraints: {bc_count} (max distance: {bc_distance} Å)")
        print(f"Total restraints: {len(pairs)}")
        
        return pairs


# Geometry (match plot_indent_restraints / test_membrane_restraints)
R, H = 100.0, 50.0
LENGTH = 200.0
SIGMA_LOC = 2.0
K_EV = 4.0
K_MBM = 4.0
X0_MBM = 0.0
N_BEADS = 10
BEAD_RADIUS = 5.0
# Box for random initial placement: around the indent (dome center ~0,0, apex at z=H)
BOX_XY = 55.0   # x,y in [-BOX_XY, BOX_XY]
BOX_Z_LO, BOX_Z_HI = 0.0, 55.0  # z range
MC_MAX_TRANSLATION = 5.0
MC_KT = 1.0


def random_vector_in_box():
    return IMP.algebra.Vector3D(
        random.uniform(-BOX_XY, BOX_XY),
        random.uniform(-BOX_XY, BOX_XY),
        random.uniform(BOX_Z_LO, BOX_Z_HI),
    )


def main():
    ap = argparse.ArgumentParser(
        description="MC beads + indent restraints (PMI); output RMF to rmfs/")
    ap.add_argument("--steps", type=int, default=1000, help="Monte Carlo steps")
    ap.add_argument("--out-dir", default="./", help="Output directory (default: .)")
    ap.add_argument("--no-rmf", action="store_true",
                    help="Do not write RMF (run MC only, no IMP.pmi)")
    args = ap.parse_args()
    write_rmf = HAS_RMF and not args.no_rmf

    m = IMP.Model()
    random.seed(42)

    if write_rmf:
        # ---- PMI: 10 beads via topology ----
        system = IMP.pmi.topology.System(m)
        state = system.create_state()
        mol = state.create_molecule("beads", "A" * N_BEADS, "A")  # 10 alanines, chain A
        mol.add_representation(resolutions=[1])  # one bead per residue
        hierarchy = system.build()
        beads = [h.get_particle() for h in IMP.atom.get_leaves(hierarchy)]
        # Place beads at random in box and set radius
        for p in beads:
            pos = random_vector_in_box()
            IMP.core.XYZ(p).set_coordinates(pos)
            if IMP.core.XYZR.get_is_setup(p):
                IMP.core.XYZR(p).set_radius(BEAD_RADIUS)
            else:
                IMP.core.XYZR.setup_particle(p, IMP.algebra.Sphere3D(pos, BEAD_RADIUS))
            IMP.core.XYZ(p).set_coordinates_are_optimized(True)
        print(f"Placed {N_BEADS} beads (PMI) in box x,y in [±{BOX_XY}], z in [{BOX_Z_LO},{BOX_Z_HI}]")

        # ---- Membrane ----
        membrane_p = IMP.Particle(m)
        IMP.npc.SlabWithSphericalIndent.setup_particle(m, membrane_p, R, H)

        # ---- Restraints (all three). PMI RMF writer expects RestraintSets ----
        loc_restraint = IMP.npc.SphericalIndentMembraneSurfaceLocationRestraint(
            m, R, H, LENGTH, SIGMA_LOC)
        loc_restraint.set_particles(beads)

        mlsc = IMP.container.ListSingletonContainer(m, [membrane_p])
        plsc = IMP.container.ListSingletonContainer(m, beads)
        ev_score = IMP.npc.SphericalIndentSurfaceDepthPairScore(K_EV)
        ev_bpc = IMP.container.AllBipartitePairContainer(mlsc, plsc)
        ev_restraint = IMP.container.PairsRestraint(ev_score, ev_bpc, "indent EV")
        mbm_score = IMP.npc.SlabWithSphericalIndentMBMScore(X0_MBM, K_MBM)
        mbm_bpc = IMP.container.AllBipartitePairContainer(mlsc, plsc)
        mbm_restraint = IMP.container.PairsRestraint(mbm_score, mbm_bpc, "indent MBM")

        indent_rs = IMP.RestraintSet(m, "indent_restraints")
        indent_rs.add_restraint(loc_restraint)
        indent_rs.add_restraint(ev_restraint)
        indent_rs.add_restraint(mbm_restraint)
        IMP.pmi.tools.add_restraint_to_model(m, indent_rs, add_to_rmf=True)

        score_0 = IMP.pmi.tools.get_restraint_set(m).evaluate(False)
        print(f"Initial score: {score_0:.2f}")

        # ---- PMI DOF: flexible beads ----
        dof = IMP.pmi.dof.DegreesOfFreedom(m)
        dof.create_flexible_beads(mol, max_trans=MC_MAX_TRANSLATION, resolution=1)

        # ---- PMI ReplicaExchange: MC + RMF ----
        rex = IMP.pmi.macros.ReplicaExchange(
            m,
            root_hier=hierarchy,
            monte_carlo_sample_objects=dof.get_movers(),
            output_objects=[],
            number_of_frames=args.steps,
            monte_carlo_temperature=MC_KT,
            monte_carlo_steps=1,
            number_of_best_scoring_models=0,
            global_output_directory=args.out_dir,
            rmf_dir="rmfs/",
            write_initial_rmf=True,
        )
        geom = IMP.npc.SlabWithSphericalIndentGeometry(R, LENGTH, H)
        rex.add_geometries([geom])
        rex.execute_macro()
        score_final = IMP.pmi.tools.get_restraint_set(m).evaluate(False)
        print(f"Final score: {score_final:.2f}")
        print(f"RMF frames written to {args.out_dir}rmfs/0.rmf3")
        print("ChimeraX: open that file, then 'rmf readtraj #1.1', 'coordset slider #1.1' to play.")
    else:
        # ---- Fallback: no RMF / no PMI – simple MC with manual beads ----
        beads = []
        for i in range(N_BEADS):
            p = IMP.Particle(m)
            pos = random_vector_in_box()
            IMP.core.XYZR.setup_particle(p, IMP.algebra.Sphere3D(pos, BEAD_RADIUS))
            IMP.core.XYZ(p).set_coordinates_are_optimized(True)
            if HAS_IMP_ATOM:
                IMP.atom.Mass.setup_particle(p, 1.0)
            beads.append(p)
        print(f"Placed {N_BEADS} beads in box (no RMF).")

        membrane_p = IMP.Particle(m)
        IMP.npc.SlabWithSphericalIndent.setup_particle(m, membrane_p, R, H)
        loc_restraint = IMP.npc.SphericalIndentMembraneSurfaceLocationRestraint(
            m, R, H, LENGTH, SIGMA_LOC)
        loc_restraint.set_particles(beads)
        mlsc = IMP.container.ListSingletonContainer(m, [membrane_p])
        plsc = IMP.container.ListSingletonContainer(m, beads)
        ev_restraint = IMP.container.PairsRestraint(
            IMP.npc.SphericalIndentSurfaceDepthPairScore(K_EV),
            IMP.container.AllBipartitePairContainer(mlsc, plsc), "indent EV")
        mbm_restraint = IMP.container.PairsRestraint(
            IMP.npc.SlabWithSphericalIndentMBMScore(X0_MBM, K_MBM),
            IMP.container.AllBipartitePairContainer(mlsc, plsc), "indent MBM")
        sf = IMP.core.RestraintsScoringFunction([loc_restraint, ev_restraint, mbm_restraint])
        movers = [IMP.core.BallMover(m, [beads[i].get_index()], MC_MAX_TRANSLATION)
                  for i in range(N_BEADS)]
        mc = IMP.core.MonteCarlo(m)
        mc.set_scoring_function(sf)
        mc.add_mover(IMP.core.SerialMover(movers))
        mc.set_kt(MC_KT)
        mc.optimize(args.steps)
        print(f"Final score: {sf.evaluate(False):.2f}")


if __name__ == "__main__":
    main()
