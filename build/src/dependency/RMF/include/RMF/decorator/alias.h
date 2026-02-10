/**
 *  \file RMF/decorator/alias.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_ALIAS_DECORATORS_H
#define RMF_ALIAS_DECORATORS_H

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

/** See also Alias and AliasFactory.
 */
class AliasConst : public Decorator {
  friend class AliasFactory;

 protected:
  IntKey aliased_;
  AliasConst(NodeConstHandle nh, IntKey aliased)
      : Decorator(nh), aliased_(aliased) {}

 public:
  NodeConstHandle get_aliased() const {
    try {
      int id = get_node().get_value(aliased_);
      return get_node().get_file().get_node(NodeID(id));
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "AliasConst"; }
  RMF_SHOWABLE(AliasConst, "Alias: " << get_node());
};
/** See also AliasFactory.
 */
class Alias : public AliasConst {
  friend class AliasFactory;
  Alias(NodeHandle nh, IntKey aliased) : AliasConst(nh, aliased) {}

 public:
  void set_aliased(NodeConstHandle v) {
    try {
      get_node().set_value(aliased_, v.get_id().get_index());
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Alias"; }
};

/** Create decorators of type Alias.
 */
class AliasFactory : public Factory {
  Category cat_;
  IntKey aliased_;

 public:
  AliasFactory(FileConstHandle fh)
      : cat_(fh.get_category("alias")),
        aliased_(fh.get_key<IntTag>(cat_, "aliased")) {}
  AliasFactory(FileHandle fh)
      : cat_(fh.get_category("alias")),
        aliased_(fh.get_key<IntTag>(cat_, "aliased")) {}
  /** Get a AliasConst for nh.*/
  AliasConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::ALIAS),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Alias");
    return AliasConst(nh, aliased_);
  }
  /** Get a Alias for nh.*/
  Alias get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::ALIAS),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Alias");
    return Alias(nh, aliased_);
  }
  /** Check whether nh has all the attributes required to be a
      AliasConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::ALIAS) &&
           !nh.get_value(aliased_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::ALIAS) &&
           !nh.get_static_value(aliased_).get_is_null();
  }
  RMF_SHOWABLE(AliasFactory, "AliasFactory");
};
#ifndef RMF_DOXYGEN
struct AliasConstFactory : public AliasFactory {
  AliasConstFactory(FileConstHandle fh) : AliasFactory(fh) {}
  AliasConstFactory(FileHandle fh) : AliasFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_ALIAS_DECORATORS_H */
