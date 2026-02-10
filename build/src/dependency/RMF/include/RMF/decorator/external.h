/**
 *  \file RMF/decorator/external.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_EXTERNAL_DECORATORS_H
#define RMF_EXTERNAL_DECORATORS_H

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

/** See also External and ExternalFactory.
 */
class ExternalConst : public Decorator {
  friend class ExternalFactory;

 protected:
  StringKey path_;
  ExternalConst(NodeConstHandle nh, StringKey path)
      : Decorator(nh), path_(path) {}

 public:
  String get_path() const {
    try {
      String relpath = get_node().get_value(path_);
      String filename = get_node().get_file().get_path();
      return internal::get_absolute_path(filename, relpath);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ExternalConst"; }
  RMF_SHOWABLE(ExternalConst, "External: " << get_node());
};
/** See also ExternalFactory.
 */
class External : public ExternalConst {
  friend class ExternalFactory;
  External(NodeHandle nh, StringKey path) : ExternalConst(nh, path) {}

 public:
  void set_path(String path) {
    try {
      String filename = get_node().get_file().get_path();
      String relpath = internal::get_relative_path(filename, path);
      get_node().set_value(path_, relpath);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "External"; }
};

/** Create decorators of type External.
 */
class ExternalFactory : public Factory {
  Category cat_;
  StringKey path_;

 public:
  ExternalFactory(FileConstHandle fh)
      : cat_(fh.get_category("external")),
        path_(fh.get_key<StringTag>(cat_, "path")) {}
  ExternalFactory(FileHandle fh)
      : cat_(fh.get_category("external")),
        path_(fh.get_key<StringTag>(cat_, "path")) {}
  /** Get a ExternalConst for nh.*/
  ExternalConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  External");
    return ExternalConst(nh, path_);
  }
  /** Get a External for nh.*/
  External get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  External");
    return External(nh, path_);
  }
  /** Check whether nh has all the attributes required to be a
      ExternalConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(path_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(path_).get_is_null();
  }
  RMF_SHOWABLE(ExternalFactory, "ExternalFactory");
};
#ifndef RMF_DOXYGEN
struct ExternalConstFactory : public ExternalFactory {
  ExternalConstFactory(FileConstHandle fh) : ExternalFactory(fh) {}
  ExternalConstFactory(FileHandle fh) : ExternalFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_EXTERNAL_DECORATORS_H */
