#!/usr/bin/env python
"""
Test and visualize slab-with-spherical-indent restraints:
  - SphericalIndentMembraneSurfaceLocationRestraint
  - SphericalIndentSurfaceDepthPairScore
  - SlabWithSphericalIndentMBMScore

Plot: three subplots, each Score vs. scan variable.

Scan mode:
  - X-scan (default): particle at (x, 0, 0); x-axis = x. Set X_MIN, X_MAX, N_POINTS.
  - Z-scan (commented out): particle at (0, 0, z); x-axis = distance from surface.
    Uncomment the "Z-scan" block in main() and comment the "X-scan" block to switch back.

================================================================================
WHAT IS "THE SURFACE"?
================================================================================
The geometry is a flat slab (like a tabletop) with a circular dome on it.

  - OUTSIDE THE DOME (in the xy-plane): "The surface" is the flat plane at z = 0.
    Particles are supposed to sit on this plane there.

  - INSIDE THE DOME: "The surface" is the curved top of the sphere (the dome).
    The opening of the dome is the circle at z = 0 where the sphere meets the
    plane. The dome goes UP from z = 0 into positive z. So the rim is at z = 0
    and the apex (top) of the dome is at z = depth (e.g. 50 when depth=50).

In this script we only move a particle along the symmetry axis (x=0, y=0),
i.e. straight through the center of the dome. On that line, the surface is
a single point: the apex of the dome at z = depth. So:

  - "Distance from surface" = z - depth
  - 0 = on the apex of the dome
  - >0 = above the apex
  - <0 = below the apex (toward the opening at z=0 and into the slab)

So the X-axis is that signed distance; the Y-axis is the score from each
restraint when we place one particle at (0, 0, z) and vary z.
"""

import IMP
import IMP.algebra
import IMP.core
import IMP.npc
import IMP.container
import numpy as np

# Geometry (match test_membrane_restraints): radius R, depth H of spherical cap
R, H = 100.0, 50.0
# On the symmetry axis (0,0), the apex of the dome is at z = H
Z_SURFACE_AXIS = H  # 50

# ---- X-scan (y=0, z=0): particle at (x, 0, 0) ----
X_MIN, X_MAX = -120.0, 120.0
N_POINTS = 240

# ---- Z-scan (commented out; uncomment to scan along z at (0,0,z)) ----
# Z_MIN, Z_MAX = -10.0, 60.0
# N_POINTS = 120


def distance_from_surface(z):
    """Signed distance from surface at (0,0): 0 on surface, >0 above, <0 below."""
    return z - Z_SURFACE_AXIS


def run_surface_location_restraint(m, scan_values, scan_axis="x", sigma=2.0):
    """Run restraint; scan_axis 'x' => (x,0,0), 'z' => (0,0,z)."""
    radius, depth, length = R, H, 200.0
    r = IMP.npc.SphericalIndentMembraneSurfaceLocationRestraint(
        m, radius, depth, length, sigma
    )
    p = IMP.Particle(m)
    IMP.core.XYZ.setup_particle(p, IMP.algebra.Vector3D(0.0, 0.0, 0.0))
    r.set_particles([p])
    scores = []
    for v in scan_values:
        if scan_axis == "x":
            IMP.core.XYZ(p).set_coordinates(IMP.algebra.Vector3D(v, 0.0, 0.0))
        else:
            IMP.core.XYZ(p).set_coordinates(IMP.algebra.Vector3D(0.0, 0.0, v))
        scores.append(r.unprotected_evaluate(None))
    return np.array(scores)


def run_surface_depth_pair_score(m, membrane_p, scan_values, scan_axis="x", k=4.0):
    """Run EV pair score; scan_axis 'x' => (x,0,0), 'z' => (0,0,z)."""
    mlsc = IMP.container.ListSingletonContainer(m, [membrane_p])
    sdc = IMP.npc.SphericalIndentSurfaceDepthPairScore(k)
    p = IMP.Particle(m)
    IMP.core.XYZ.setup_particle(p, IMP.algebra.Vector3D(0.0, 0.0, 0.0))
    bpc = IMP.container.AllBipartitePairContainer(mlsc, [p])
    pr = IMP.container.PairsRestraint(sdc, bpc, "indent EV")
    scores = []
    for v in scan_values:
        if scan_axis == "x":
            IMP.core.XYZ(p).set_coordinates(IMP.algebra.Vector3D(v, 0.0, 0.0))
        else:
            IMP.core.XYZ(p).set_coordinates(IMP.algebra.Vector3D(0.0, 0.0, v))
        scores.append(pr.unprotected_evaluate(None))
    return np.array(scores)


def run_mbm_score(m, membrane_p, scan_values, scan_axis="x", x0=0.0, k=4.0):
    """Run MBM pair score; scan_axis 'x' => (x,0,0), 'z' => (0,0,z)."""
    mlsc = IMP.container.ListSingletonContainer(m, [membrane_p])
    sps = IMP.npc.SlabWithSphericalIndentMBMScore(x0, k)
    p = IMP.Particle(m)
    IMP.core.XYZ.setup_particle(p, IMP.algebra.Vector3D(0.0, 0.0, 0.0))
    bpc = IMP.container.AllBipartitePairContainer(mlsc, [p])
    pr = IMP.container.PairsRestraint(sps, bpc, "indent MBM")
    scores = []
    for v in scan_values:
        if scan_axis == "x":
            IMP.core.XYZ(p).set_coordinates(IMP.algebra.Vector3D(v, 0.0, 0.0))
        else:
            IMP.core.XYZ(p).set_coordinates(IMP.algebra.Vector3D(0.0, 0.0, v))
        scores.append(pr.unprotected_evaluate(None))
    return np.array(scores)


def main():
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
    except ImportError:
        print("matplotlib not found; install it to generate the plot.")
        print("Data are still computed and printed below.")
        plt = None

    # ---- X-scan (y=0, z=0) ----
    x_values = np.linspace(X_MIN, X_MAX, N_POINTS)
    abscissa = x_values
    x_label = "x (y=0, z=0)"

    m1 = IMP.Model()
    scores_loc = run_surface_location_restraint(m1, x_values, scan_axis="x")

    m2 = IMP.Model()
    membrane = IMP.npc.SlabWithSphericalIndent.setup_particle(
        m2, IMP.Particle(m2), R, H
    )
    scores_ev = run_surface_depth_pair_score(m2, membrane, x_values, scan_axis="x")
    scores_mbm = run_mbm_score(m2, membrane, x_values, scan_axis="x", x0=0.0)

    # Reference point: center (x=0)
    i_center = np.argmin(np.abs(x_values))
    x_at_center = x_values[i_center]
    print("At x = 0 (center, y=0, z=0):")
    print(f"  x = {x_at_center:.4f}")
    print(f"  SphericalIndentMembraneSurfaceLocationRestraint: {scores_loc[i_center]:.4f}")
    print(f"  SphericalIndentSurfaceDepthPairScore (EV):       {scores_ev[i_center]:.4f}")
    print(f"  SlabWithSphericalIndentMBMScore:                {scores_mbm[i_center]:.4f}")
    print()

    # ---- Z-scan (commented out; uncomment to use z-scan instead of x-scan) ----
    # z_values = np.linspace(Z_MIN, Z_MAX, N_POINTS)
    # dist = distance_from_surface(z_values)
    # abscissa = dist
    # x_label = "Distance from surface (axis 0,0)"
    # m1 = IMP.Model()
    # scores_loc = run_surface_location_restraint(m1, z_values, scan_axis="z")
    # m2 = IMP.Model()
    # membrane = IMP.npc.SlabWithSphericalIndent.setup_particle(m2, IMP.Particle(m2), R, H)
    # scores_ev = run_surface_depth_pair_score(m2, membrane, z_values, scan_axis="z")
    # scores_mbm = run_mbm_score(m2, membrane, z_values, scan_axis="z", x0=0.0)
    # i_surface = np.argmin(np.abs(dist))
    # print("At distance from surface = 0 (particle on surface):")
    # print(f"  z = {z_values[i_surface]:.4f}, dist = {dist[i_surface]:.4f}")
    # print(f"  SphericalIndentMembraneSurfaceLocationRestraint: {scores_loc[i_surface]:.4f}")
    # print(f"  SphericalIndentSurfaceDepthPairScore (EV):       {scores_ev[i_surface]:.4f}")
    # print(f"  SlabWithSphericalIndentMBMScore:                {scores_mbm[i_surface]:.4f}")
    # print()

    if plt is not None:
        fig, axes = plt.subplots(3, 1, figsize=(10, 6), sharex=True)

        colors = ["#007AFF", "#FF9500", "#28CD41"]

        ax0 = axes[0]
        ax0.plot(abscissa, scores_loc, color=colors[0], linewidth=3)
        ax0.axvline(0.0, color="#555555", linestyle="--", linewidth=2)
        ax0.set_ylabel("Score", fontsize=14, fontweight='bold')
        ax0.set_title("SphericalIndentMembraneSurfaceLocationRestraint", fontsize=16, pad=10)
        ax0.grid(True, axis='y', alpha=0.2)

        ax1 = axes[1]
        ax1.plot(abscissa, scores_ev, color=colors[1], linewidth=3)
        ax1.axvline(0.0, color="#555555", linestyle="--", linewidth=2)
        ax1.set_ylabel("Score", fontsize=14, fontweight='bold')
        ax1.set_title("SphericalIndentSurfaceDepthPairScore (EV)", fontsize=16, pad=10)
        ax1.grid(True, axis='y', alpha=0.2)

        ax2 = axes[2]
        ax2.plot(abscissa, scores_mbm, color=colors[2], linewidth=3)
        ax2.axvline(0.0, color="#555555", linestyle="--", linewidth=2)
        ax2.set_xlabel(x_label, fontsize=14, fontweight='bold')
        ax2.set_ylabel("Score", fontsize=14, fontweight='bold')
        ax2.set_title("SlabWithSphericalIndentMBMScore", fontsize=16, pad=10)
        ax2.grid(True, axis='y', alpha=0.2)

        fig.tight_layout(h_pad=1.5)
        out = "indent_restraints_plot.png"
        fig.savefig(out, dpi=300, transparent=True)
        print("Plot saved to", out)

    # Print a few sample values
    print("Sample: abscissa, score_loc, score_ev, score_mbm")
    for i in [0, N_POINTS // 4, N_POINTS // 2, 3 * N_POINTS // 4, N_POINTS - 1]:
        print(
            f"  {abscissa[i]:.1f}, "
            f"{scores_loc[i]:.2f}, {scores_ev[i]:.2f}, {scores_mbm[i]:.2f}"
        )


if __name__ == "__main__":
    main()
