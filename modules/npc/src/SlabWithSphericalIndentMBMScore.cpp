/**
 *  \file SlabWithSphericalIndentMBMScore.cpp
 *  \brief A Harmonic Score on the z distance above a surface with a spherical indent
 *
 *  Copyright 2007-2018 IMP Inventors. All rights reserved.
 */

#include <IMP/npc/SlabWithSphericalIndentMBMScore.h>
#include <IMP/core/XYZ.h>
#include <IMP/UnaryFunction.h>
#include <cmath>
//#include <boost/lambda/lambda.hpp>

IMPNPC_BEGIN_NAMESPACE

SlabWithSphericalIndentMBMScore::SlabWithSphericalIndentMBMScore(double x0, double k) : x0_(x0), k_(k) {}

// return score for a given particle pair
double SlabWithSphericalIndentMBMScore::evaluate_index(Model *m,
                                       const ParticleIndexPair &pip,
                                       DerivativeAccumulator *da) const {

    // turn on logging for this method
    //IMP_OBJECT_LOG;

    // check that the first particle is the spherical indent
    IMP_USAGE_CHECK(SlabWithSphericalIndent::get_is_setup(m, pip[0]) , "First particle passed is not of type SlabWithSphericalIndent");

    //
    // assume they have coordinates
    SlabWithSphericalIndent d1(m, pip[0]);
    core::XYZ d2(m, pip[1]);

    double x = d2.get_coordinate(0);
    double y = d2.get_coordinate(1);
    double z = d2.get_coordinate(2);

    // check if optimized.
    //if (!d2.get_coordinates_are_optimized()) {
    //    return false;
    //}
    // could write a sub routine here but let's code it directly
    //double score=get_surface_distance()
    double score = 0.0;
    double dv;

    // get the surface distance.
    double R = d1.get_sphere_radius();
    double h = d1.get_sphere_depth();

    // compute the base circle radius
    double a_sqrd = h*(2.0*R-h);

    // compute score for being in the indent (dome) region
    if ((x*x+y*y) < a_sqrd) {
        // Target z = height of dome surface (dome opens at z=0, bulges up; sphere center at z = -(R-h)).
        double z_target = (h - R) + std::sqrt(R * R - x * x - y * y);
        // Old convention (sphere center at z = R-h, target = upper hemisphere; at (0,0) target = 2R-h):
        // double z_target = std::sqrt(R*R - x*x - y*y) + (R-h);
        score = 0.5 * k_ * square(z - z_target);
        if (da) {
            dv = -k_ * (z - z_target);
            algebra::Vector3D udelta = algebra::Vector3D(0.0, 0.0, 1.0);
            d2.add_to_derivatives(udelta * dv, *da);
        }
    }
    // compute score for being outside the indent
    else {

        score = 0.5 * k_ * square(z - x0_);
        //IMP_LOG_PROGRESS("PLANE SCORE: " << score << "\n");
        // do derivatives
        if (da) {
            dv = -k_ * (z - x0_);
            algebra::Vector3D udelta = algebra::Vector3D(0.0, 0.0, 1.0);
            d2.add_to_derivatives(udelta * dv, *da);
        }
    }

    //IMP_LOG_PROGRESS("OUTPUT SCORE: " << score << "\n"); 
    return score;
}


/*
Double SlabWithSphericalIndentMBMScore::get_surface_distance(algebra::Vector3D* coord) const {

    double ret;
    // for now just do distance in to restrain the z-distance from the surface
    double z = coord[2];

    ret = ()

}
*/

ModelObjectsTemp SlabWithSphericalIndentMBMScore::do_get_inputs(
        Model *m, const ParticleIndexes &pis) const {
    return IMP::get_particles(m, pis);
}

IMPNPC_END_NAMESPACE

