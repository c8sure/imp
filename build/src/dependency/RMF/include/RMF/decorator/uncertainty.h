/**
 *  \file RMF/decorator/uncertainty.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_UNCERTAINTY_DECORATORS_H
#define RMF_UNCERTAINTY_DECORATORS_H

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

RMF_ENABLE_WARNINGS
namespace RMF {
namespace decorator {

/** See also Scale and ScaleFactory.
 */
class ScaleConst : public Decorator {
  friend class ScaleFactory;

 protected:
  FloatKey scale_;
  FloatKey scale_lower_;
  FloatKey scale_upper_;
  ScaleConst(NodeConstHandle nh, FloatKey scale, FloatKey scale_lower,
             FloatKey scale_upper)
      : Decorator(nh),
        scale_(scale),
        scale_lower_(scale_lower),
        scale_upper_(scale_upper) {}

 public:
  Float get_scale() const {
    try {
      return get_node().get_value(scale_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_scale() const {
    try {
      return get_node().get_frame_value(scale_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_scale() const {
    try {
      return get_node().get_static_value(scale_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_lower() const {
    try {
      return get_node().get_value(scale_lower_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_lower() const {
    try {
      return get_node().get_frame_value(scale_lower_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_lower() const {
    try {
      return get_node().get_static_value(scale_lower_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_upper() const {
    try {
      return get_node().get_value(scale_upper_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_upper() const {
    try {
      return get_node().get_frame_value(scale_upper_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_upper() const {
    try {
      return get_node().get_static_value(scale_upper_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ScaleConst"; }
  RMF_SHOWABLE(ScaleConst, "Scale: " << get_node());
};
/** See also ScaleFactory.
 */
class Scale : public ScaleConst {
  friend class ScaleFactory;
  Scale(NodeHandle nh, FloatKey scale, FloatKey scale_lower,
        FloatKey scale_upper)
      : ScaleConst(nh, scale, scale_lower, scale_upper) {}

 public:
  void set_scale(Float v) {
    try {
      get_node().set_value(scale_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_scale(Float v) {
    try {
      get_node().set_frame_value(scale_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_scale(Float v) {
    try {
      get_node().set_static_value(scale_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_lower(Float v) {
    try {
      get_node().set_value(scale_lower_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_lower(Float v) {
    try {
      get_node().set_frame_value(scale_lower_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_lower(Float v) {
    try {
      get_node().set_static_value(scale_lower_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_upper(Float v) {
    try {
      get_node().set_value(scale_upper_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_upper(Float v) {
    try {
      get_node().set_frame_value(scale_upper_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_upper(Float v) {
    try {
      get_node().set_static_value(scale_upper_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Scale"; }
};

/** Create decorators of type Scale.
 */
class ScaleFactory : public Factory {
  Category cat_;
  FloatKey scale_;
  FloatKey scale_lower_;
  FloatKey scale_upper_;

 public:
  ScaleFactory(FileConstHandle fh)
      : cat_(fh.get_category("uncertainty")),
        scale_(fh.get_key<FloatTag>(cat_, "scale")),
        scale_lower_(fh.get_key<FloatTag>(cat_, "scale lower")),
        scale_upper_(fh.get_key<FloatTag>(cat_, "scale upper")) {}
  ScaleFactory(FileHandle fh)
      : cat_(fh.get_category("uncertainty")),
        scale_(fh.get_key<FloatTag>(cat_, "scale")),
        scale_lower_(fh.get_key<FloatTag>(cat_, "scale lower")),
        scale_upper_(fh.get_key<FloatTag>(cat_, "scale upper")) {}
  /** Get a ScaleConst for nh.*/
  ScaleConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Scale");
    return ScaleConst(nh, scale_, scale_lower_, scale_upper_);
  }
  /** Get a Scale for nh.*/
  Scale get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Scale");
    return Scale(nh, scale_, scale_lower_, scale_upper_);
  }
  /** Check whether nh has all the attributes required to be a
      ScaleConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(scale_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(scale_).get_is_null() &&
           !nh.get_static_value(scale_lower_).get_is_null() &&
           !nh.get_static_value(scale_upper_).get_is_null();
  }
  RMF_SHOWABLE(ScaleFactory, "ScaleFactory");
};
#ifndef RMF_DOXYGEN
struct ScaleConstFactory : public ScaleFactory {
  ScaleConstFactory(FileConstHandle fh) : ScaleFactory(fh) {}
  ScaleConstFactory(FileHandle fh) : ScaleFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_UNCERTAINTY_DECORATORS_H */
