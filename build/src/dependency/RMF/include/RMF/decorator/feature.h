/**
 *  \file RMF/decorator/feature.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_FEATURE_DECORATORS_H
#define RMF_FEATURE_DECORATORS_H

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

/** See also Score and ScoreFactory.
 */
class ScoreConst : public Decorator {
  friend class ScoreFactory;

 protected:
  FloatKey score_;
  ScoreConst(NodeConstHandle nh, FloatKey score)
      : Decorator(nh), score_(score) {}

 public:
  Float get_score() const {
    try {
      return get_node().get_value(score_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_score() const {
    try {
      return get_node().get_frame_value(score_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_score() const {
    try {
      return get_node().get_static_value(score_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ScoreConst"; }
  RMF_SHOWABLE(ScoreConst, "Score: " << get_node());
};
/** See also ScoreFactory.
 */
class Score : public ScoreConst {
  friend class ScoreFactory;
  Score(NodeHandle nh, FloatKey score) : ScoreConst(nh, score) {}

 public:
  void set_score(Float v) {
    try {
      get_node().set_value(score_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_score(Float v) {
    try {
      get_node().set_frame_value(score_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_score(Float v) {
    try {
      get_node().set_static_value(score_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Score"; }
};

/** Create decorators of type Score.
 */
class ScoreFactory : public Factory {
  Category cat_;
  FloatKey score_;

 public:
  ScoreFactory(FileConstHandle fh)
      : cat_(fh.get_category("feature")),
        score_(fh.get_key<FloatTag>(cat_, "score")) {}
  ScoreFactory(FileHandle fh)
      : cat_(fh.get_category("feature")),
        score_(fh.get_key<FloatTag>(cat_, "score")) {}
  /** Get a ScoreConst for nh.*/
  ScoreConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::FEATURE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Score");
    return ScoreConst(nh, score_);
  }
  /** Get a Score for nh.*/
  Score get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::FEATURE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Score");
    return Score(nh, score_);
  }
  /** Check whether nh has all the attributes required to be a
      ScoreConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::FEATURE) &&
           !nh.get_value(score_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::FEATURE) &&
           !nh.get_static_value(score_).get_is_null();
  }
  RMF_SHOWABLE(ScoreFactory, "ScoreFactory");
};
#ifndef RMF_DOXYGEN
struct ScoreConstFactory : public ScoreFactory {
  ScoreConstFactory(FileConstHandle fh) : ScoreFactory(fh) {}
  ScoreConstFactory(FileHandle fh) : ScoreFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_FEATURE_DECORATORS_H */
