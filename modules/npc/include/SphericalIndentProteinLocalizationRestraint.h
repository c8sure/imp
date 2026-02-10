/**
 *  \file IMP/npc/SphericalIndentProteinLocalizationRestraint.h
 *  \brief protein localization restraints
 *
 *  Restrict max distance between at least one pair of particles of any
 *  two distinct types. It also handles multiple copies of the same particles.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef IMPNPC_SPHERICAL_INDENT_PROTEIN_LOCALIZATION_RESTRAINT_H
#define IMPNPC_SPHERICAL_INDENT_PROTEIN_LOCALIZATION_RESTRAINT_H

#include <IMP/Pointer.h>
#include <IMP/Restraint.h>
#include <IMP/npc/npc_config.h>
#include <IMP/SingletonContainer.h>
#include <cereal/access.hpp>
#include <cereal/types/base_class.hpp>

IMPNPC_BEGIN_NAMESPACE

//! Try to keep particles localized on a membrane surface
/** The membrane is defined in this case to be a slab with a spherical indent in the xy
    plane with center at the origin. The opening of the indent is at z=0.
  */
class IMPNPCEXPORT SphericalIndentMembraneSurfaceLocationRestraint : public Restraint
{
  IMP::PointerMember<IMP::SingletonContainer> sc_;
  double radius_;
  double depth_;
  double length_;
  double sigma_;

  friend class cereal::access;
  template<class Archive> void serialize(Archive &ar) {
    ar(cereal::base_class<Restraint>(this), sc_, radius_, depth_, length_, sigma_);
  }
  IMP_OBJECT_SERIALIZE_DECL(SphericalIndentMembraneSurfaceLocationRestraint);

public:
  SphericalIndentMembraneSurfaceLocationRestraint(Model *m, SingletonContainerAdaptor sc,
      double radius, double depth, double length, double sigma=2);
  SphericalIndentMembraneSurfaceLocationRestraint(Model *m,
      double radius, double depth, double length, double sigma=2);
  SphericalIndentMembraneSurfaceLocationRestraint() {}

#ifndef IMP_DOXYGEN
  void add_particle(Particle *p);
  void add_particles(const ParticlesTemp &ps);
  void set_particles(const ParticlesTemp &ps);
#endif

  double unprotected_evaluate(
                  IMP::DerivativeAccumulator *accum) const override;
  ModelObjectsTemp do_get_inputs() const override;

  //! \return Information for writing to RMF files
  RestraintInfo *get_static_info() const override;

  IMP_OBJECT_METHODS(SphericalIndentMembraneSurfaceLocationRestraint);;
};





IMPNPC_END_NAMESPACE

#endif /* IMPNPC_SPHERICAL_INDENT_PROTEIN_LOCALIZATION_RESTRAINT_H */