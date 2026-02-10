/**
 *  \file SphericalIndentProteinLocalizationRestraint.cpp  \brief Connectivity restraint.
 *
 *  Restrict max distance between at least one pair of particles of any
 *  two distinct types.
 *
 *  Copyright 2007-2023 IMP Inventors. All rights reserved.
 *
 */

#include <cmath>
#include <algorithm>
#include <IMP/Model.h>
#include <IMP/Particle.h>
#include <IMP/SingletonModifier.h>
#include <IMP/core/XYZ.h>
#include <IMP/core/XYZR.h>
#include <IMP/internal/container_helpers.h>
#include <IMP/internal/StaticListContainer.h>
#include <IMP/npc/SphericalIndentProteinLocalizationRestraint.h>

IMPNPC_BEGIN_NAMESPACE

namespace {
IMP::internal::StaticListContainer<SingletonContainer> *get_spherical_indent_list(
    SingletonContainer *sc) {
  IMP::internal::StaticListContainer<SingletonContainer> *ret =
      dynamic_cast<
          IMP::internal::StaticListContainer<SingletonContainer> *>(
          sc);
  if (!ret) {
    IMP_THROW("Can only use the set and add methods when no container"
                  << " was passed on construction of "
                     "SphericalIndentMembraneSurfaceLocationRestraint.",
              ValueException);
  }
  return ret;
}
}

/*#####################################################
# Restraints setup - MembraneSurfaceLocationRestraint
#####################################################*/
SphericalIndentMembraneSurfaceLocationRestraint::SphericalIndentMembraneSurfaceLocationRestraint(
    Model *m,
    SingletonContainerAdaptor sc,
    double radius, double depth, double length, double sigma)
  : Restraint(m, "SphericalIndentMembraneSurfaceLocationRestraint %1%")
  , radius_(radius)
  , depth_(depth)
  , length_(length)
  , sigma_(sigma)
{
  sc_ = sc;
}

SphericalIndentMembraneSurfaceLocationRestraint::SphericalIndentMembraneSurfaceLocationRestraint(Model *m,
    double radius, double depth, double length, double sigma)
  : Restraint(m, "SphericalIndentMembraneSurfaceLocationRestraint %1%")
  , radius_(radius)
  , depth_(depth)
  , length_(length)
  , sigma_(sigma)
{
}

void SphericalIndentMembraneSurfaceLocationRestraint::set_particles(const ParticlesTemp &ps) {
  if (!sc_ && !ps.empty()) {
    sc_ = new IMP::internal::StaticListContainer<SingletonContainer>(
        ps[0]->get_model(), "Surface location list");
  }
  get_spherical_indent_list(sc_)->set(IMP::internal::get_index(ps));
}

void SphericalIndentMembraneSurfaceLocationRestraint::add_particles(const ParticlesTemp &ps) {
  if (!sc_ && !ps.empty()) {
    sc_ = new IMP::internal::StaticListContainer<SingletonContainer>(
        ps[0]->get_model(), "Surface location list");
  }
  get_spherical_indent_list(sc_)->add(IMP::internal::get_index(ps));
}

void SphericalIndentMembraneSurfaceLocationRestraint::add_particle(Particle *p) {
  if (!sc_) {
    sc_ = new IMP::internal::StaticListContainer<SingletonContainer>(
        p->get_model(), "Surface location list");
  }
  get_spherical_indent_list(sc_)->add(IMP::internal::get_index(p));
}

double
SphericalIndentMembraneSurfaceLocationRestraint::unprotected_evaluate(DerivativeAccumulator *accum) const
{
  IMP_CHECK_OBJECT(sc_.get());
  double v = 0;
  double center_z = -(radius_ - depth_);
  double a_sqrd = depth_ * (2 * radius_ - depth_);

  IMP::ParticlesTemp all_particles = sc_->get();
  for (unsigned int i = 0; i < all_particles.size(); ++i )
  {
    core::XYZ i_current = core::XYZ(all_particles[i]);
    double x = i_current.get_coordinate(0);
    double y = i_current.get_coordinate(1);
    double z = i_current.get_coordinate(2);
    double d2 = x*x + y*y;

    if (d2 < a_sqrd) {
        // inside the indent
        double dz = z - center_z;
        double dist = std::sqrt(d2 + dz*dz);
        double diff = dist - radius_;
        v += diff * diff;

        if (accum) {
            double coeff = 2 * diff / (dist * sigma_);
            all_particles[i]->get_model()->add_to_coordinate_derivatives(
                IMP::internal::get_index(all_particles[i]),
                algebra::Vector3D(coeff * x, coeff * y,
                                  coeff * dz),
                *accum);
        }
    } else {
        // flat portion
        v += z*z;
        if (accum) {
            all_particles[i]->get_model()->add_to_coordinate_derivatives(
                IMP::internal::get_index(all_particles[i]),
                algebra::Vector3D(0, 0, 2 * z / sigma_),
                *accum);
        }
    }
  }

  return v / sigma_;
}


ModelObjectsTemp SphericalIndentMembraneSurfaceLocationRestraint::do_get_inputs() const {
  if (!sc_) return ModelObjectsTemp();
  return IMP::get_particles(get_model(), sc_->get_all_possible_indexes());
}

RestraintInfo *SphericalIndentMembraneSurfaceLocationRestraint::get_static_info() const {
  IMP_NEW(RestraintInfo, ri, ());
  ri->add_string("type", "SphericalIndentMembraneSurfaceLocationRestraint");
  ri->add_float("radius", radius_);
  ri->add_float("depth", depth_);
  ri->add_float("sigma", sigma_);
  return ri.release();
}

IMP_OBJECT_SERIALIZE_IMPL(IMP::npc::SphericalIndentMembraneSurfaceLocationRestraint);

IMPNPC_END_NAMESPACE