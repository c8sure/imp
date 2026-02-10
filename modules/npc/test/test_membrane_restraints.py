import IMP
import IMP.test
import IMP.algebra
import IMP.core
import IMP.npc
import IMP.container
import pickle


def setup_system_toroid():
    m = IMP.Model()
    membrane = IMP.npc.SlabWithToroidalPore.setup_particle(m, IMP.Particle(m), 200.0, 50.0)
    p = IMP.core.XYZR.setup_particle(
        IMP.Particle(m),
        IMP.algebra.Sphere3D(IMP.algebra.Vector3D(0.0,80.0,50.0), 0.4))
    return m, membrane, p

def setup_system_indent():
    m = IMP.Model()
    membrane = IMP.npc.SlabWithSphericalIndent.setup_particle(m, IMP.Particle(m), 100.0, 50.0)
    p = IMP.core.XYZR.setup_particle(
        IMP.Particle(m),
        IMP.algebra.Sphere3D(IMP.algebra.Vector3D(100.0,100.0,20.0), 0.4))
    return m, membrane, p


class Tests(IMP.test.TestCase):

    def test_setup_toroidal_membrane(self):
        """Test SlabWithToroidalPore"""
        m,membrane,p=setup_system_toroid()
        ratio=membrane.get_minor_radius_h2v_aspect_ratio()
        thickness=membrane.get_thickness()
        radius=membrane.get_pore_radius()
        self.assertAlmostEqual(ratio, 1.0, delta=1e-4)
        self.assertAlmostEqual(thickness, 200.0, delta=1e-4)
        self.assertAlmostEqual(radius, 50.0, delta=1e-4)

    def test_toroidal_membrane_EV(self):
        """Test ToroidalPoreSurfaceDepthPairScore"""
        m,membrane,p=setup_system_toroid()
        mlsc = IMP.container.ListSingletonContainer(m, [membrane])
        sdc = IMP.npc.ToroidalPoreSurfaceDepthPairScore(4.0)
        bpc = IMP.container.AllBipartitePairContainer(mlsc, [p])
        sdpr = IMP.container.PairsRestraint(sdc, bpc, "membrane ev score")
        self.assertAlmostEqual(sdpr.unprotected_evaluate(None), 5000.0, delta=1e-4)

    def test_toroidal_membrane_MBM(self):
        """Test SlabWithToroidalPoreMBMScore"""
        m,membrane,p=setup_system_toroid()
        p.set_coordinates([100.0,100.0,-112.0])
        sps = IMP.npc.SlabWithToroidalPoreMBMScore(10.0, 0.0, 4.0)
        mlsc = IMP.container.ListSingletonContainer(m, [membrane])
        bpc = IMP.container.AllBipartitePairContainer(mlsc, [p])
        prs = IMP.container.PairsRestraint(sps, bpc, "membrane mbm restraint")
        self.assertAlmostEqual(prs.unprotected_evaluate(None), 8.0, delta=1e-4)

    def test_setup_indent_membrane(self):
        """Test SlabWithSphericalIndent"""
        m,membrane,p=setup_system_indent()
        r=membrane.get_sphere_radius()
        h=membrane.get_sphere_depth()
        self.assertAlmostEqual(r, 100.0, delta=1e-4)
        self.assertAlmostEqual(h, 50.0, delta=1e-4)

    def test_indent_membrane_EV(self):
        """Test SphericalIndentSurfaceDepthPairScore"""
        m,membrane,p=setup_system_indent()
        mlsc = IMP.container.ListSingletonContainer(m, [membrane])
        sdc = IMP.npc.SphericalIndentSurfaceDepthPairScore(4.0)
        bpc = IMP.container.AllBipartitePairContainer(mlsc, [p])
        sdpr = IMP.container.PairsRestraint(sdc, bpc, "membrane indent ev score")
        self.assertAlmostEqual(sdpr.unprotected_evaluate(None), 800.0, delta=1e-4)

    def test_indent_membrane_MBM(self):
        """Test SlabWithToroidalPoreMBMScore"""
        m,membrane,p=setup_system_indent()
        p.set_coordinates([100.0,100.0,-12.0])
        sps = IMP.npc.SlabWithSphericalIndentMBMScore(0.0, 4.0)
        mlsc = IMP.container.ListSingletonContainer(m, [membrane])
        bpc = IMP.container.AllBipartitePairContainer(mlsc, [p])
        prs = IMP.container.PairsRestraint(sps, bpc, "membrane mbm restraint")
        self.assertAlmostEqual(prs.unprotected_evaluate(None), 288.0, delta=1e-4)

    def test_spherical_indent_surface_location_restraint(self):
        """Test SphericalIndentMembraneSurfaceLocationRestraint"""
        m = IMP.Model()
        # Same geometry as setup_system_indent: radius=100, depth=50
        radius, depth, length, sigma = 100.0, 50.0, 200.0, 2.0
        r = IMP.npc.SphericalIndentMembraneSurfaceLocationRestraint(
            m, radius, depth, length, sigma)
        # One particle at origin: inside indent footprint, 50 units below
        # sphere center (center_z=50), dist=50, diff=50-100=-50, v=2500, return 2500/sigma=1250
        p = IMP.Particle(m)
        IMP.core.XYZ.setup_particle(p, IMP.algebra.Vector3D(0.0, 0.0, 0.0))
        r.set_particles([p])
        self.assertAlmostEqual(r.unprotected_evaluate(None), 1250.0, delta=1e-4)
        # Particle on flat part at z=0: no penalty
        p2 = IMP.Particle(m)
        IMP.core.XYZ.setup_particle(p2, IMP.algebra.Vector3D(100.0, 100.0, 0.0))
        r.set_particles([p, p2])
        self.assertAlmostEqual(r.unprotected_evaluate(None), 1250.0, delta=1e-4)

if __name__ == '__main__':
    IMP.test.main()
