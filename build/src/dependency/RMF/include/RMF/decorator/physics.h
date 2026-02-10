/**
 *  \file RMF/decorator/physics.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_PHYSICS_DECORATORS_H
#define RMF_PHYSICS_DECORATORS_H

#include <RMF/Decorator.h>
#include <RMF/FileHandle.h>
#include <RMF/NodeHandle.h>
#include <RMF/Vector.h>
#include <RMF/config.h>
#include <RMF/constants.h>
#include <RMF/infrastructure_macros.h>
#include <RMF/internal/paths.h>

#include <array>
#include <boost/lexical_cast.hpp>

#include "alias.h"

RMF_ENABLE_WARNINGS
namespace RMF {
namespace decorator {

/** See also Particle and ParticleFactory.
 */
class ParticleConst : public Decorator {
  friend class ParticleFactory;

 protected:
  FloatKey mass_;
  Vector3Key coordinates_;
  FloatKey radius_;
  ParticleConst(NodeConstHandle nh, FloatKey mass, Vector3Key coordinates,
                FloatKey radius)
      : Decorator(nh),
        mass_(mass),
        coordinates_(coordinates),
        radius_(radius) {}

 public:
  Float get_mass() const {
    try {
      return get_node().get_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_mass() const {
    try {
      return get_node().get_frame_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_mass() const {
    try {
      return get_node().get_static_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }

  Vector3 get_coordinates() const {
    try {
      return get_node().get_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_frame_coordinates() const {
    try {
      return get_node().get_frame_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_static_coordinates() const {
    try {
      return get_node().get_static_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_radius() const {
    try {
      return get_node().get_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_radius() const {
    try {
      return get_node().get_frame_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_radius() const {
    try {
      return get_node().get_static_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ParticleConst"; }
  RMF_SHOWABLE(ParticleConst, "Particle: " << get_node());
};
/** See also ParticleFactory.
 */
class Particle : public ParticleConst {
  friend class ParticleFactory;
  Particle(NodeHandle nh, FloatKey mass, Vector3Key coordinates,
           FloatKey radius)
      : ParticleConst(nh, mass, coordinates, radius) {}

 public:
  void set_mass(Float v) {
    try {
      get_node().set_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_mass(Float v) {
    try {
      get_node().set_frame_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_mass(Float v) {
    try {
      get_node().set_static_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_coordinates(Vector3 v) {
    try {
      get_node().set_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_coordinates(Vector3 v) {
    try {
      get_node().set_frame_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_coordinates(Vector3 v) {
    try {
      get_node().set_static_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_radius(Float v) {
    try {
      get_node().set_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_radius(Float v) {
    try {
      get_node().set_frame_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_radius(Float v) {
    try {
      get_node().set_static_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Particle"; }
};

/** Create decorators of type Particle.
 */
class ParticleFactory : public Factory {
  Category cat_;
  FloatKey mass_;
  Vector3Key coordinates_;
  FloatKey radius_;

 public:
  ParticleFactory(FileConstHandle fh)
      : cat_(fh.get_category("physics")),
        mass_(fh.get_key<FloatTag>(cat_, "mass")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")) {}
  ParticleFactory(FileHandle fh)
      : cat_(fh.get_category("physics")),
        mass_(fh.get_key<FloatTag>(cat_, "mass")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")) {}
  /** Get a ParticleConst for nh.*/
  ParticleConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Particle");
    return ParticleConst(nh, mass_, coordinates_, radius_);
  }
  /** Get a Particle for nh.*/
  Particle get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Particle");
    return Particle(nh, mass_, coordinates_, radius_);
  }
  /** Check whether nh has all the attributes required to be a
      ParticleConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(mass_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(mass_).get_is_null() &&
           !nh.get_static_value(coordinates_).get_is_null() &&
           !nh.get_static_value(radius_).get_is_null();
  }
  RMF_SHOWABLE(ParticleFactory, "ParticleFactory");
};
#ifndef RMF_DOXYGEN
struct ParticleConstFactory : public ParticleFactory {
  ParticleConstFactory(FileConstHandle fh) : ParticleFactory(fh) {}
  ParticleConstFactory(FileHandle fh) : ParticleFactory(fh) {}
};
#endif

/** See also IntermediateParticle and IntermediateParticleFactory.
 */
class IntermediateParticleConst : public Decorator {
  friend class IntermediateParticleFactory;

 protected:
  FloatKey radius_;
  Vector3Key coordinates_;
  IntermediateParticleConst(NodeConstHandle nh, FloatKey radius,
                            Vector3Key coordinates)
      : Decorator(nh), radius_(radius), coordinates_(coordinates) {}

 public:
  Float get_radius() const {
    try {
      return get_node().get_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_radius() const {
    try {
      return get_node().get_frame_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_radius() const {
    try {
      return get_node().get_static_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }

  Vector3 get_coordinates() const {
    try {
      return get_node().get_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_frame_coordinates() const {
    try {
      return get_node().get_frame_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_static_coordinates() const {
    try {
      return get_node().get_static_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "IntermediateParticleConst";
  }
  RMF_SHOWABLE(IntermediateParticleConst,
               "IntermediateParticle: " << get_node());
};
/** See also IntermediateParticleFactory.
 */
class IntermediateParticle : public IntermediateParticleConst {
  friend class IntermediateParticleFactory;
  IntermediateParticle(NodeHandle nh, FloatKey radius, Vector3Key coordinates)
      : IntermediateParticleConst(nh, radius, coordinates) {}

 public:
  void set_radius(Float v) {
    try {
      get_node().set_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_radius(Float v) {
    try {
      get_node().set_frame_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_radius(Float v) {
    try {
      get_node().set_static_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_coordinates(Vector3 v) {
    try {
      get_node().set_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_coordinates(Vector3 v) {
    try {
      get_node().set_frame_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_coordinates(Vector3 v) {
    try {
      get_node().set_static_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "IntermediateParticle";
  }
};

/** Create decorators of type IntermediateParticle.
 */
class IntermediateParticleFactory : public Factory {
  Category cat_;
  FloatKey radius_;
  Vector3Key coordinates_;

 public:
  IntermediateParticleFactory(FileConstHandle fh)
      : cat_(fh.get_category("physics")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")) {}
  IntermediateParticleFactory(FileHandle fh)
      : cat_(fh.get_category("physics")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")) {}
  /** Get a IntermediateParticleConst for nh.*/
  IntermediateParticleConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  IntermediateParticle");
    return IntermediateParticleConst(nh, radius_, coordinates_);
  }
  /** Get a IntermediateParticle for nh.*/
  IntermediateParticle get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  IntermediateParticle");
    return IntermediateParticle(nh, radius_, coordinates_);
  }
  /** Check whether nh has all the attributes required to be a
      IntermediateParticleConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(radius_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(radius_).get_is_null() &&
           !nh.get_static_value(coordinates_).get_is_null();
  }
  RMF_SHOWABLE(IntermediateParticleFactory, "IntermediateParticleFactory");
};
#ifndef RMF_DOXYGEN
struct IntermediateParticleConstFactory : public IntermediateParticleFactory {
  IntermediateParticleConstFactory(FileConstHandle fh)
      : IntermediateParticleFactory(fh) {}
  IntermediateParticleConstFactory(FileHandle fh)
      : IntermediateParticleFactory(fh) {}
};
#endif

/** See also GaussianParticle and GaussianParticleFactory.
 */
class GaussianParticleConst : public Decorator {
  friend class GaussianParticleFactory;

 protected:
  Vector3Key variances_;
  FloatKey mass_;
  GaussianParticleConst(NodeConstHandle nh, Vector3Key variances, FloatKey mass)
      : Decorator(nh), variances_(variances), mass_(mass) {}

 public:
  Vector3 get_variances() const {
    try {
      return get_node().get_value(variances_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_frame_variances() const {
    try {
      return get_node().get_frame_value(variances_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_static_variances() const {
    try {
      return get_node().get_static_value(variances_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_mass() const {
    try {
      return get_node().get_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_mass() const {
    try {
      return get_node().get_frame_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_mass() const {
    try {
      return get_node().get_static_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "GaussianParticleConst";
  }
  RMF_SHOWABLE(GaussianParticleConst, "GaussianParticle: " << get_node());
};
/** See also GaussianParticleFactory.
 */
class GaussianParticle : public GaussianParticleConst {
  friend class GaussianParticleFactory;
  GaussianParticle(NodeHandle nh, Vector3Key variances, FloatKey mass)
      : GaussianParticleConst(nh, variances, mass) {}

 public:
  void set_variances(Vector3 v) {
    try {
      get_node().set_value(variances_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_variances(Vector3 v) {
    try {
      get_node().set_frame_value(variances_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_variances(Vector3 v) {
    try {
      get_node().set_static_value(variances_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_mass(Float v) {
    try {
      get_node().set_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_mass(Float v) {
    try {
      get_node().set_frame_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_mass(Float v) {
    try {
      get_node().set_static_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "GaussianParticle"; }
};

/** Create decorators of type GaussianParticle.
 */
class GaussianParticleFactory : public Factory {
  Category cat_;
  Vector3Key variances_;
  FloatKey mass_;

 public:
  GaussianParticleFactory(FileConstHandle fh)
      : cat_(fh.get_category("physics")),
        variances_(fh.get_key<Vector3Tag>(cat_, "variances")),
        mass_(fh.get_key<FloatTag>(cat_, "mass")) {}
  GaussianParticleFactory(FileHandle fh)
      : cat_(fh.get_category("physics")),
        variances_(fh.get_key<Vector3Tag>(cat_, "variances")),
        mass_(fh.get_key<FloatTag>(cat_, "mass")) {}
  /** Get a GaussianParticleConst for nh.*/
  GaussianParticleConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  GaussianParticle");
    return GaussianParticleConst(nh, variances_, mass_);
  }
  /** Get a GaussianParticle for nh.*/
  GaussianParticle get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  GaussianParticle");
    return GaussianParticle(nh, variances_, mass_);
  }
  /** Check whether nh has all the attributes required to be a
      GaussianParticleConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(variances_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(variances_).get_is_null() &&
           !nh.get_static_value(mass_).get_is_null();
  }
  RMF_SHOWABLE(GaussianParticleFactory, "GaussianParticleFactory");
};
#ifndef RMF_DOXYGEN
struct GaussianParticleConstFactory : public GaussianParticleFactory {
  GaussianParticleConstFactory(FileConstHandle fh)
      : GaussianParticleFactory(fh) {}
  GaussianParticleConstFactory(FileHandle fh) : GaussianParticleFactory(fh) {}
};
#endif

/** See also RigidParticle and RigidParticleFactory.
 */
class RigidParticleConst : public Decorator {
  friend class RigidParticleFactory;

 protected:
  Vector4Key orientation_;
  Vector3Key coordinates_;
  RigidParticleConst(NodeConstHandle nh, Vector4Key orientation,
                     Vector3Key coordinates)
      : Decorator(nh), orientation_(orientation), coordinates_(coordinates) {}

 public:
  Vector4 get_orientation() const {
    try {
      return get_node().get_value(orientation_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector4 get_frame_orientation() const {
    try {
      return get_node().get_frame_value(orientation_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector4 get_static_orientation() const {
    try {
      return get_node().get_static_value(orientation_);
    }
    RMF_DECORATOR_CATCH();
  }

  Vector3 get_coordinates() const {
    try {
      return get_node().get_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_frame_coordinates() const {
    try {
      return get_node().get_frame_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_static_coordinates() const {
    try {
      return get_node().get_static_value(coordinates_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "RigidParticleConst"; }
  RMF_SHOWABLE(RigidParticleConst, "RigidParticle: " << get_node());
};
/** See also RigidParticleFactory.
 */
class RigidParticle : public RigidParticleConst {
  friend class RigidParticleFactory;
  RigidParticle(NodeHandle nh, Vector4Key orientation, Vector3Key coordinates)
      : RigidParticleConst(nh, orientation, coordinates) {}

 public:
  void set_orientation(Vector4 v) {
    try {
      get_node().set_value(orientation_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_orientation(Vector4 v) {
    try {
      get_node().set_frame_value(orientation_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_orientation(Vector4 v) {
    try {
      get_node().set_static_value(orientation_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_coordinates(Vector3 v) {
    try {
      get_node().set_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_coordinates(Vector3 v) {
    try {
      get_node().set_frame_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_coordinates(Vector3 v) {
    try {
      get_node().set_static_value(coordinates_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "RigidParticle"; }
};

/** Create decorators of type RigidParticle.
 */
class RigidParticleFactory : public Factory {
  Category cat_;
  Vector4Key orientation_;
  Vector3Key coordinates_;

 public:
  RigidParticleFactory(FileConstHandle fh)
      : cat_(fh.get_category("physics")),
        orientation_(fh.get_key<Vector4Tag>(cat_, "orientation")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")) {}
  RigidParticleFactory(FileHandle fh)
      : cat_(fh.get_category("physics")),
        orientation_(fh.get_key<Vector4Tag>(cat_, "orientation")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")) {}
  /** Get a RigidParticleConst for nh.*/
  RigidParticleConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  RigidParticle");
    return RigidParticleConst(nh, orientation_, coordinates_);
  }
  /** Get a RigidParticle for nh.*/
  RigidParticle get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  RigidParticle");
    return RigidParticle(nh, orientation_, coordinates_);
  }
  /** Check whether nh has all the attributes required to be a
      RigidParticleConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(orientation_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(orientation_).get_is_null() &&
           !nh.get_static_value(coordinates_).get_is_null();
  }
  RMF_SHOWABLE(RigidParticleFactory, "RigidParticleFactory");
};
#ifndef RMF_DOXYGEN
struct RigidParticleConstFactory : public RigidParticleFactory {
  RigidParticleConstFactory(FileConstHandle fh) : RigidParticleFactory(fh) {}
  RigidParticleConstFactory(FileHandle fh) : RigidParticleFactory(fh) {}
};
#endif

/** See also Diffuser and DiffuserFactory.
 */
class DiffuserConst : public Decorator {
  friend class DiffuserFactory;

 protected:
  FloatKey diffusion_coefficient_;
  DiffuserConst(NodeConstHandle nh, FloatKey diffusion_coefficient)
      : Decorator(nh), diffusion_coefficient_(diffusion_coefficient) {}

 public:
  Float get_diffusion_coefficient() const {
    try {
      return get_node().get_value(diffusion_coefficient_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_diffusion_coefficient() const {
    try {
      return get_node().get_frame_value(diffusion_coefficient_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_diffusion_coefficient() const {
    try {
      return get_node().get_static_value(diffusion_coefficient_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "DiffuserConst"; }
  RMF_SHOWABLE(DiffuserConst, "Diffuser: " << get_node());
};
/** See also DiffuserFactory.
 */
class Diffuser : public DiffuserConst {
  friend class DiffuserFactory;
  Diffuser(NodeHandle nh, FloatKey diffusion_coefficient)
      : DiffuserConst(nh, diffusion_coefficient) {}

 public:
  void set_diffusion_coefficient(Float v) {
    try {
      get_node().set_value(diffusion_coefficient_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_diffusion_coefficient(Float v) {
    try {
      get_node().set_frame_value(diffusion_coefficient_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_diffusion_coefficient(Float v) {
    try {
      get_node().set_static_value(diffusion_coefficient_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Diffuser"; }
};

/** Create decorators of type Diffuser.
 */
class DiffuserFactory : public Factory {
  Category cat_;
  FloatKey diffusion_coefficient_;

 public:
  DiffuserFactory(FileConstHandle fh)
      : cat_(fh.get_category("physics")),
        diffusion_coefficient_(
            fh.get_key<FloatTag>(cat_, "diffusion coefficient")) {}
  DiffuserFactory(FileHandle fh)
      : cat_(fh.get_category("physics")),
        diffusion_coefficient_(
            fh.get_key<FloatTag>(cat_, "diffusion coefficient")) {}
  /** Get a DiffuserConst for nh.*/
  DiffuserConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Diffuser");
    return DiffuserConst(nh, diffusion_coefficient_);
  }
  /** Get a Diffuser for nh.*/
  Diffuser get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Diffuser");
    return Diffuser(nh, diffusion_coefficient_);
  }
  /** Check whether nh has all the attributes required to be a
      DiffuserConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(diffusion_coefficient_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(diffusion_coefficient_).get_is_null();
  }
  RMF_SHOWABLE(DiffuserFactory, "DiffuserFactory");
};
#ifndef RMF_DOXYGEN
struct DiffuserConstFactory : public DiffuserFactory {
  DiffuserConstFactory(FileConstHandle fh) : DiffuserFactory(fh) {}
  DiffuserConstFactory(FileHandle fh) : DiffuserFactory(fh) {}
};
#endif

/** See also Atom and AtomFactory.
 */
class AtomConst : public Decorator {
  friend class AtomFactory;

 protected:
  IntKey element_;
  FloatKey mass_;
  FloatKey radius_;
  AtomConst(NodeConstHandle nh, IntKey element, FloatKey mass, FloatKey radius)
      : Decorator(nh), element_(element), mass_(mass), radius_(radius) {}

 public:
  Int get_element() const {
    try {
      return get_node().get_value(element_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_element() const {
    try {
      return get_node().get_frame_value(element_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_element() const {
    try {
      return get_node().get_static_value(element_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_mass() const {
    try {
      return get_node().get_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_mass() const {
    try {
      return get_node().get_frame_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_mass() const {
    try {
      return get_node().get_static_value(mass_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_radius() const {
    try {
      return get_node().get_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_radius() const {
    try {
      return get_node().get_frame_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_radius() const {
    try {
      return get_node().get_static_value(radius_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "AtomConst"; }
  RMF_SHOWABLE(AtomConst, "Atom: " << get_node());
};
/** See also AtomFactory.
 */
class Atom : public AtomConst {
  friend class AtomFactory;
  Atom(NodeHandle nh, IntKey element, FloatKey mass, FloatKey radius)
      : AtomConst(nh, element, mass, radius) {}

 public:
  void set_element(Int v) {
    try {
      get_node().set_value(element_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_element(Int v) {
    try {
      get_node().set_frame_value(element_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_element(Int v) {
    try {
      get_node().set_static_value(element_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_mass(Float v) {
    try {
      get_node().set_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_mass(Float v) {
    try {
      get_node().set_frame_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_mass(Float v) {
    try {
      get_node().set_static_value(mass_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_radius(Float v) {
    try {
      get_node().set_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_radius(Float v) {
    try {
      get_node().set_frame_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_radius(Float v) {
    try {
      get_node().set_static_value(radius_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Atom"; }
};

/** Create decorators of type Atom.
 */
class AtomFactory : public Factory {
  Category cat_;
  IntKey element_;
  FloatKey mass_;
  FloatKey radius_;

 public:
  AtomFactory(FileConstHandle fh)
      : cat_(fh.get_category("physics")),
        element_(fh.get_key<IntTag>(cat_, "element")),
        mass_(fh.get_key<FloatTag>(cat_, "mass")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")) {}
  AtomFactory(FileHandle fh)
      : cat_(fh.get_category("physics")),
        element_(fh.get_key<IntTag>(cat_, "element")),
        mass_(fh.get_key<FloatTag>(cat_, "mass")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")) {}
  /** Get a AtomConst for nh.*/
  AtomConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Atom");
    return AtomConst(nh, element_, mass_, radius_);
  }
  /** Get a Atom for nh.*/
  Atom get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Atom");
    return Atom(nh, element_, mass_, radius_);
  }
  /** Check whether nh has all the attributes required to be a
      AtomConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(element_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(element_).get_is_null() &&
           !nh.get_static_value(mass_).get_is_null() &&
           !nh.get_static_value(radius_).get_is_null();
  }
  RMF_SHOWABLE(AtomFactory, "AtomFactory");
};
#ifndef RMF_DOXYGEN
struct AtomConstFactory : public AtomFactory {
  AtomConstFactory(FileConstHandle fh) : AtomFactory(fh) {}
  AtomConstFactory(FileHandle fh) : AtomFactory(fh) {}
};
#endif

/** See also ReferenceFrame and ReferenceFrameFactory.
 */
class ReferenceFrameConst : public Decorator {
  friend class ReferenceFrameFactory;

 protected:
  Vector4Key rotation_;
  Vector3Key translation_;
  ReferenceFrameConst(NodeConstHandle nh, Vector4Key rotation,
                      Vector3Key translation)
      : Decorator(nh), rotation_(rotation), translation_(translation) {}

 public:
  Vector4 get_rotation() const {
    try {
      return get_node().get_value(rotation_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector4 get_frame_rotation() const {
    try {
      return get_node().get_frame_value(rotation_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector4 get_static_rotation() const {
    try {
      return get_node().get_static_value(rotation_);
    }
    RMF_DECORATOR_CATCH();
  }

  Vector3 get_translation() const {
    try {
      return get_node().get_value(translation_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_frame_translation() const {
    try {
      return get_node().get_frame_value(translation_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_static_translation() const {
    try {
      return get_node().get_static_value(translation_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ReferenceFrameConst"; }
  RMF_SHOWABLE(ReferenceFrameConst, "ReferenceFrame: " << get_node());
};
/** See also ReferenceFrameFactory.
 */
class ReferenceFrame : public ReferenceFrameConst {
  friend class ReferenceFrameFactory;
  ReferenceFrame(NodeHandle nh, Vector4Key rotation, Vector3Key translation)
      : ReferenceFrameConst(nh, rotation, translation) {}

 public:
  void set_rotation(Vector4 v) {
    try {
      get_node().set_value(rotation_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_rotation(Vector4 v) {
    try {
      get_node().set_frame_value(rotation_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_rotation(Vector4 v) {
    try {
      get_node().set_static_value(rotation_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_translation(Vector3 v) {
    try {
      get_node().set_value(translation_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_translation(Vector3 v) {
    try {
      get_node().set_frame_value(translation_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_translation(Vector3 v) {
    try {
      get_node().set_static_value(translation_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ReferenceFrame"; }
};

/** Create decorators of type ReferenceFrame.
 */
class ReferenceFrameFactory : public Factory {
  Category cat_;
  Vector4Key rotation_;
  Vector3Key translation_;

 public:
  ReferenceFrameFactory(FileConstHandle fh)
      : cat_(fh.get_category("physics")),
        rotation_(fh.get_key<Vector4Tag>(cat_, "rotation")),
        translation_(fh.get_key<Vector3Tag>(cat_, "translation")) {}
  ReferenceFrameFactory(FileHandle fh)
      : cat_(fh.get_category("physics")),
        rotation_(fh.get_key<Vector4Tag>(cat_, "rotation")),
        translation_(fh.get_key<Vector3Tag>(cat_, "translation")) {}
  /** Get a ReferenceFrameConst for nh.*/
  ReferenceFrameConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION ||
                     nh.get_type() == RMF::ORGANIZATIONAL),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ReferenceFrame");
    return ReferenceFrameConst(nh, rotation_, translation_);
  }
  /** Get a ReferenceFrame for nh.*/
  ReferenceFrame get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION ||
                     nh.get_type() == RMF::ORGANIZATIONAL),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ReferenceFrame");
    return ReferenceFrame(nh, rotation_, translation_);
  }
  /** Check whether nh has all the attributes required to be a
      ReferenceFrameConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION ||
            nh.get_type() == RMF::ORGANIZATIONAL) &&
           !nh.get_value(rotation_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION ||
            nh.get_type() == RMF::ORGANIZATIONAL) &&
           !nh.get_static_value(rotation_).get_is_null() &&
           !nh.get_static_value(translation_).get_is_null();
  }
  RMF_SHOWABLE(ReferenceFrameFactory, "ReferenceFrameFactory");
};
#ifndef RMF_DOXYGEN
struct ReferenceFrameConstFactory : public ReferenceFrameFactory {
  ReferenceFrameConstFactory(FileConstHandle fh) : ReferenceFrameFactory(fh) {}
  ReferenceFrameConstFactory(FileHandle fh) : ReferenceFrameFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_PHYSICS_DECORATORS_H */
