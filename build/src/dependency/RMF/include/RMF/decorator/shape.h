/**
 *  \file RMF/decorator/shape.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_SHAPE_DECORATORS_H
#define RMF_SHAPE_DECORATORS_H

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

/** See also Colored and ColoredFactory.
 */
class ColoredConst : public Decorator {
  friend class ColoredFactory;

 protected:
  Vector3Key rgb_color_;
  ColoredConst(NodeConstHandle nh, Vector3Key rgb_color)
      : Decorator(nh), rgb_color_(rgb_color) {}

 public:
  Vector3 get_rgb_color() const {
    try {
      return get_node().get_value(rgb_color_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_frame_rgb_color() const {
    try {
      return get_node().get_frame_value(rgb_color_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_static_rgb_color() const {
    try {
      return get_node().get_static_value(rgb_color_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ColoredConst"; }
  RMF_SHOWABLE(ColoredConst, "Colored: " << get_node());
};
/** See also ColoredFactory.
 */
class Colored : public ColoredConst {
  friend class ColoredFactory;
  Colored(NodeHandle nh, Vector3Key rgb_color) : ColoredConst(nh, rgb_color) {}

 public:
  void set_rgb_color(Vector3 v) {
    try {
      get_node().set_value(rgb_color_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_rgb_color(Vector3 v) {
    try {
      get_node().set_frame_value(rgb_color_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_rgb_color(Vector3 v) {
    try {
      get_node().set_static_value(rgb_color_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Colored"; }
};

/** Create decorators of type Colored.
 */
class ColoredFactory : public Factory {
  Category cat_;
  Vector3Key rgb_color_;

 public:
  ColoredFactory(FileConstHandle fh)
      : cat_(fh.get_category("shape")),
        rgb_color_(fh.get_key<Vector3Tag>(cat_, "rgb color")) {}
  ColoredFactory(FileHandle fh)
      : cat_(fh.get_category("shape")),
        rgb_color_(fh.get_key<Vector3Tag>(cat_, "rgb color")) {}
  /** Get a ColoredConst for nh.*/
  ColoredConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK(
        (nh.get_type() == RMF::REPRESENTATION ||
         nh.get_type() == RMF::ORGANIZATIONAL || nh.get_type() == RMF::ALIAS ||
         nh.get_type() == RMF::FEATURE || nh.get_type() == RMF::GEOMETRY),
        std::string("Bad node type. Got \"") +
            boost::lexical_cast<std::string>(nh.get_type()) +
            "\" in decorator type  Colored");
    return ColoredConst(nh, rgb_color_);
  }
  /** Get a Colored for nh.*/
  Colored get(NodeHandle nh) const {
    RMF_USAGE_CHECK(
        (nh.get_type() == RMF::REPRESENTATION ||
         nh.get_type() == RMF::ORGANIZATIONAL || nh.get_type() == RMF::ALIAS ||
         nh.get_type() == RMF::FEATURE || nh.get_type() == RMF::GEOMETRY),
        std::string("Bad node type. Got \"") +
            boost::lexical_cast<std::string>(nh.get_type()) +
            "\" in decorator type  Colored");
    return Colored(nh, rgb_color_);
  }
  /** Check whether nh has all the attributes required to be a
      ColoredConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION ||
            nh.get_type() == RMF::ORGANIZATIONAL ||
            nh.get_type() == RMF::ALIAS || nh.get_type() == RMF::FEATURE ||
            nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_value(rgb_color_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION ||
            nh.get_type() == RMF::ORGANIZATIONAL ||
            nh.get_type() == RMF::ALIAS || nh.get_type() == RMF::FEATURE ||
            nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_static_value(rgb_color_).get_is_null();
  }
  RMF_SHOWABLE(ColoredFactory, "ColoredFactory");
};
#ifndef RMF_DOXYGEN
struct ColoredConstFactory : public ColoredFactory {
  ColoredConstFactory(FileConstHandle fh) : ColoredFactory(fh) {}
  ColoredConstFactory(FileHandle fh) : ColoredFactory(fh) {}
};
#endif

/** See also Ball and BallFactory.
 */
class BallConst : public Decorator {
  friend class BallFactory;

 protected:
  Vector3Key coordinates_;
  FloatKey radius_;
  BallConst(NodeConstHandle nh, Vector3Key coordinates, FloatKey radius)
      : Decorator(nh), coordinates_(coordinates), radius_(radius) {}

 public:
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

  static std::string get_decorator_type_name() { return "BallConst"; }
  RMF_SHOWABLE(BallConst, "Ball: " << get_node());
};
/** See also BallFactory.
 */
class Ball : public BallConst {
  friend class BallFactory;
  Ball(NodeHandle nh, Vector3Key coordinates, FloatKey radius)
      : BallConst(nh, coordinates, radius) {}

 public:
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

  static std::string get_decorator_type_name() { return "Ball"; }
};

/** Create decorators of type Ball.
 */
class BallFactory : public Factory {
  Category cat_;
  Vector3Key coordinates_;
  FloatKey radius_;

 public:
  BallFactory(FileConstHandle fh)
      : cat_(fh.get_category("shape")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")) {}
  BallFactory(FileHandle fh)
      : cat_(fh.get_category("shape")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")) {}
  /** Get a BallConst for nh.*/
  BallConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Ball");
    return BallConst(nh, coordinates_, radius_);
  }
  /** Get a Ball for nh.*/
  Ball get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Ball");
    return Ball(nh, coordinates_, radius_);
  }
  /** Check whether nh has all the attributes required to be a
      BallConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_value(coordinates_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_static_value(coordinates_).get_is_null() &&
           !nh.get_static_value(radius_).get_is_null();
  }
  RMF_SHOWABLE(BallFactory, "BallFactory");
};
#ifndef RMF_DOXYGEN
struct BallConstFactory : public BallFactory {
  BallConstFactory(FileConstHandle fh) : BallFactory(fh) {}
  BallConstFactory(FileHandle fh) : BallFactory(fh) {}
};
#endif

/** See also Ellipsoid and EllipsoidFactory.
 */
class EllipsoidConst : public Decorator {
  friend class EllipsoidFactory;

 protected:
  Vector3Key axis_lengths_;
  Vector4Key orientation_;
  Vector3Key coordinates_;
  EllipsoidConst(NodeConstHandle nh, Vector3Key axis_lengths,
                 Vector4Key orientation, Vector3Key coordinates)
      : Decorator(nh),
        axis_lengths_(axis_lengths),
        orientation_(orientation),
        coordinates_(coordinates) {}

 public:
  Vector3 get_axis_lengths() const {
    try {
      return get_node().get_value(axis_lengths_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_frame_axis_lengths() const {
    try {
      return get_node().get_frame_value(axis_lengths_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3 get_static_axis_lengths() const {
    try {
      return get_node().get_static_value(axis_lengths_);
    }
    RMF_DECORATOR_CATCH();
  }

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

  static std::string get_decorator_type_name() { return "EllipsoidConst"; }
  RMF_SHOWABLE(EllipsoidConst, "Ellipsoid: " << get_node());
};
/** See also EllipsoidFactory.
 */
class Ellipsoid : public EllipsoidConst {
  friend class EllipsoidFactory;
  Ellipsoid(NodeHandle nh, Vector3Key axis_lengths, Vector4Key orientation,
            Vector3Key coordinates)
      : EllipsoidConst(nh, axis_lengths, orientation, coordinates) {}

 public:
  void set_axis_lengths(Vector3 v) {
    try {
      get_node().set_value(axis_lengths_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_axis_lengths(Vector3 v) {
    try {
      get_node().set_frame_value(axis_lengths_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_axis_lengths(Vector3 v) {
    try {
      get_node().set_static_value(axis_lengths_, v);
    }
    RMF_DECORATOR_CATCH();
  }

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

  static std::string get_decorator_type_name() { return "Ellipsoid"; }
};

/** Create decorators of type Ellipsoid.
 */
class EllipsoidFactory : public Factory {
  Category cat_;
  Vector3Key axis_lengths_;
  Vector4Key orientation_;
  Vector3Key coordinates_;

 public:
  EllipsoidFactory(FileConstHandle fh)
      : cat_(fh.get_category("shape")),
        axis_lengths_(fh.get_key<Vector3Tag>(cat_, "axis lengths")),
        orientation_(fh.get_key<Vector4Tag>(cat_, "orientation")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")) {}
  EllipsoidFactory(FileHandle fh)
      : cat_(fh.get_category("shape")),
        axis_lengths_(fh.get_key<Vector3Tag>(cat_, "axis lengths")),
        orientation_(fh.get_key<Vector4Tag>(cat_, "orientation")),
        coordinates_(fh.get_key<Vector3Tag>(cat_, "coordinates")) {}
  /** Get a EllipsoidConst for nh.*/
  EllipsoidConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Ellipsoid");
    return EllipsoidConst(nh, axis_lengths_, orientation_, coordinates_);
  }
  /** Get a Ellipsoid for nh.*/
  Ellipsoid get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Ellipsoid");
    return Ellipsoid(nh, axis_lengths_, orientation_, coordinates_);
  }
  /** Check whether nh has all the attributes required to be a
      EllipsoidConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_value(axis_lengths_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_static_value(axis_lengths_).get_is_null() &&
           !nh.get_static_value(orientation_).get_is_null() &&
           !nh.get_static_value(coordinates_).get_is_null();
  }
  RMF_SHOWABLE(EllipsoidFactory, "EllipsoidFactory");
};
#ifndef RMF_DOXYGEN
struct EllipsoidConstFactory : public EllipsoidFactory {
  EllipsoidConstFactory(FileConstHandle fh) : EllipsoidFactory(fh) {}
  EllipsoidConstFactory(FileHandle fh) : EllipsoidFactory(fh) {}
};
#endif

/** See also Cylinder and CylinderFactory.
 */
class CylinderConst : public Decorator {
  friend class CylinderFactory;

 protected:
  FloatKey radius_;
  Vector3sKey coordinates_list_;
  CylinderConst(NodeConstHandle nh, FloatKey radius,
                Vector3sKey coordinates_list)
      : Decorator(nh), radius_(radius), coordinates_list_(coordinates_list) {}

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

  Vector3s get_coordinates_list() const {
    try {
      return get_node().get_value(coordinates_list_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3s get_frame_coordinates_list() const {
    try {
      return get_node().get_frame_value(coordinates_list_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3s get_static_coordinates_list() const {
    try {
      return get_node().get_static_value(coordinates_list_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "CylinderConst"; }
  RMF_SHOWABLE(CylinderConst, "Cylinder: " << get_node());
};
/** See also CylinderFactory.
 */
class Cylinder : public CylinderConst {
  friend class CylinderFactory;
  Cylinder(NodeHandle nh, FloatKey radius, Vector3sKey coordinates_list)
      : CylinderConst(nh, radius, coordinates_list) {}

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

  void set_coordinates_list(Vector3s v) {
    try {
      get_node().set_value(coordinates_list_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_coordinates_list(Vector3s v) {
    try {
      get_node().set_frame_value(coordinates_list_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_coordinates_list(Vector3s v) {
    try {
      get_node().set_static_value(coordinates_list_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Cylinder"; }
};

/** Create decorators of type Cylinder.
 */
class CylinderFactory : public Factory {
  Category cat_;
  FloatKey radius_;
  Vector3sKey coordinates_list_;

 public:
  CylinderFactory(FileConstHandle fh)
      : cat_(fh.get_category("shape")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")),
        coordinates_list_(fh.get_key<Vector3sTag>(cat_, "coordinates list")) {}
  CylinderFactory(FileHandle fh)
      : cat_(fh.get_category("shape")),
        radius_(fh.get_key<FloatTag>(cat_, "radius")),
        coordinates_list_(fh.get_key<Vector3sTag>(cat_, "coordinates list")) {}
  /** Get a CylinderConst for nh.*/
  CylinderConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Cylinder");
    return CylinderConst(nh, radius_, coordinates_list_);
  }
  /** Get a Cylinder for nh.*/
  Cylinder get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Cylinder");
    return Cylinder(nh, radius_, coordinates_list_);
  }
  /** Check whether nh has all the attributes required to be a
      CylinderConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_value(radius_).get_is_null() &&
           !nh.get_value(coordinates_list_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_static_value(radius_).get_is_null() &&
           !nh.get_static_value(coordinates_list_).get_is_null();
  }
  RMF_SHOWABLE(CylinderFactory, "CylinderFactory");
};
#ifndef RMF_DOXYGEN
struct CylinderConstFactory : public CylinderFactory {
  CylinderConstFactory(FileConstHandle fh) : CylinderFactory(fh) {}
  CylinderConstFactory(FileHandle fh) : CylinderFactory(fh) {}
};
#endif

/** See also Segment and SegmentFactory.
 */
class SegmentConst : public Decorator {
  friend class SegmentFactory;

 protected:
  Vector3sKey coordinates_list_;
  SegmentConst(NodeConstHandle nh, Vector3sKey coordinates_list)
      : Decorator(nh), coordinates_list_(coordinates_list) {}

 public:
  Vector3s get_coordinates_list() const {
    try {
      return get_node().get_value(coordinates_list_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3s get_frame_coordinates_list() const {
    try {
      return get_node().get_frame_value(coordinates_list_);
    }
    RMF_DECORATOR_CATCH();
  }
  Vector3s get_static_coordinates_list() const {
    try {
      return get_node().get_static_value(coordinates_list_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "SegmentConst"; }
  RMF_SHOWABLE(SegmentConst, "Segment: " << get_node());
};
/** See also SegmentFactory.
 */
class Segment : public SegmentConst {
  friend class SegmentFactory;
  Segment(NodeHandle nh, Vector3sKey coordinates_list)
      : SegmentConst(nh, coordinates_list) {}

 public:
  void set_coordinates_list(Vector3s v) {
    try {
      get_node().set_value(coordinates_list_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_coordinates_list(Vector3s v) {
    try {
      get_node().set_frame_value(coordinates_list_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_coordinates_list(Vector3s v) {
    try {
      get_node().set_static_value(coordinates_list_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Segment"; }
};

/** Create decorators of type Segment.
 */
class SegmentFactory : public Factory {
  Category cat_;
  Vector3sKey coordinates_list_;

 public:
  SegmentFactory(FileConstHandle fh)
      : cat_(fh.get_category("shape")),
        coordinates_list_(fh.get_key<Vector3sTag>(cat_, "coordinates list")) {}
  SegmentFactory(FileHandle fh)
      : cat_(fh.get_category("shape")),
        coordinates_list_(fh.get_key<Vector3sTag>(cat_, "coordinates list")) {}
  /** Get a SegmentConst for nh.*/
  SegmentConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Segment");
    return SegmentConst(nh, coordinates_list_);
  }
  /** Get a Segment for nh.*/
  Segment get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::GEOMETRY),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Segment");
    return Segment(nh, coordinates_list_);
  }
  /** Check whether nh has all the attributes required to be a
      SegmentConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_value(coordinates_list_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::GEOMETRY) &&
           !nh.get_static_value(coordinates_list_).get_is_null();
  }
  RMF_SHOWABLE(SegmentFactory, "SegmentFactory");
};
#ifndef RMF_DOXYGEN
struct SegmentConstFactory : public SegmentFactory {
  SegmentConstFactory(FileConstHandle fh) : SegmentFactory(fh) {}
  SegmentConstFactory(FileHandle fh) : SegmentFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_SHAPE_DECORATORS_H */
