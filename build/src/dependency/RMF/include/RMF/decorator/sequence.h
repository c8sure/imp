/**
 *  \file RMF/decorator/sequence.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_SEQUENCE_DECORATORS_H
#define RMF_SEQUENCE_DECORATORS_H

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

/** See also Residue and ResidueFactory.
 */
class ResidueConst : public Decorator {
  friend class ResidueFactory;

 protected:
  IntKey residue_index_;
  StringKey residue_type_;
  ResidueConst(NodeConstHandle nh, IntKey residue_index, StringKey residue_type)
      : Decorator(nh),
        residue_index_(residue_index),
        residue_type_(residue_type) {}

 public:
  Int get_residue_index() const {
    try {
      return get_node().get_value(residue_index_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_residue_index() const {
    try {
      return get_node().get_frame_value(residue_index_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_residue_index() const {
    try {
      return get_node().get_static_value(residue_index_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_residue_type() const {
    try {
      return get_node().get_value(residue_type_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_residue_type() const {
    try {
      return get_node().get_frame_value(residue_type_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_residue_type() const {
    try {
      return get_node().get_static_value(residue_type_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ResidueConst"; }
  RMF_SHOWABLE(ResidueConst, "Residue: " << get_node());
};
/** See also ResidueFactory.
 */
class Residue : public ResidueConst {
  friend class ResidueFactory;
  Residue(NodeHandle nh, IntKey residue_index, StringKey residue_type)
      : ResidueConst(nh, residue_index, residue_type) {}

 public:
  void set_residue_index(Int v) {
    try {
      get_node().set_value(residue_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_residue_index(Int v) {
    try {
      get_node().set_frame_value(residue_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_residue_index(Int v) {
    try {
      get_node().set_static_value(residue_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_residue_type(String v) {
    try {
      get_node().set_value(residue_type_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_residue_type(String v) {
    try {
      get_node().set_frame_value(residue_type_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_residue_type(String v) {
    try {
      get_node().set_static_value(residue_type_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Residue"; }
};

/** Create decorators of type Residue.
 */
class ResidueFactory : public Factory {
  Category cat_;
  IntKey residue_index_;
  StringKey residue_type_;

 public:
  ResidueFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        residue_index_(fh.get_key<IntTag>(cat_, "residue index")),
        residue_type_(fh.get_key<StringTag>(cat_, "residue type")) {}
  ResidueFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        residue_index_(fh.get_key<IntTag>(cat_, "residue index")),
        residue_type_(fh.get_key<StringTag>(cat_, "residue type")) {}
  /** Get a ResidueConst for nh.*/
  ResidueConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Residue");
    return ResidueConst(nh, residue_index_, residue_type_);
  }
  /** Get a Residue for nh.*/
  Residue get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Residue");
    return Residue(nh, residue_index_, residue_type_);
  }
  /** Check whether nh has all the attributes required to be a
      ResidueConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(residue_index_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(residue_index_).get_is_null() &&
           !nh.get_static_value(residue_type_).get_is_null();
  }
  RMF_SHOWABLE(ResidueFactory, "ResidueFactory");
};
#ifndef RMF_DOXYGEN
struct ResidueConstFactory : public ResidueFactory {
  ResidueConstFactory(FileConstHandle fh) : ResidueFactory(fh) {}
  ResidueConstFactory(FileHandle fh) : ResidueFactory(fh) {}
};
#endif

/** See also Chain and ChainFactory.
 */
class ChainConst : public Decorator {
  friend class ChainFactory;

 protected:
  StringKey chain_id_;
  StringKey sequence_;
  IntKey sequence_offset_;
  StringKey uniprot_accession_;
  StringKey label_asym_id_;
  StringKey chain_type_;
  ChainConst(NodeConstHandle nh, StringKey chain_id, StringKey sequence,
             IntKey sequence_offset, StringKey uniprot_accession,
             StringKey label_asym_id, StringKey chain_type)
      : Decorator(nh),
        chain_id_(chain_id),
        sequence_(sequence),
        sequence_offset_(sequence_offset),
        uniprot_accession_(uniprot_accession),
        label_asym_id_(label_asym_id),
        chain_type_(chain_type) {}

 public:
  String get_chain_id() const {
    try {
      return get_node().get_value(chain_id_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_chain_id() const {
    try {
      return get_node().get_frame_value(chain_id_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_chain_id() const {
    try {
      return get_node().get_static_value(chain_id_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_sequence() const {
    try {
      if (!get_node().get_has_value(sequence_)) return "";
      return get_node().get_value(sequence_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_sequence() const {
    try {
      if (!get_node().get_has_value(sequence_)) return "";
      return get_node().get_frame_value(sequence_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_sequence() const {
    try {
      if (!get_node().get_has_value(sequence_)) return "";
      return get_node().get_static_value(sequence_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_sequence_offset() const {
    try {
      if (!get_node().get_has_value(sequence_offset_)) return 0;
      return get_node().get_value(sequence_offset_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_sequence_offset() const {
    try {
      if (!get_node().get_has_value(sequence_offset_)) return 0;
      return get_node().get_frame_value(sequence_offset_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_sequence_offset() const {
    try {
      if (!get_node().get_has_value(sequence_offset_)) return 0;
      return get_node().get_static_value(sequence_offset_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_uniprot_accession() const {
    try {
      if (!get_node().get_has_value(uniprot_accession_)) return "";
      return get_node().get_value(uniprot_accession_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_uniprot_accession() const {
    try {
      if (!get_node().get_has_value(uniprot_accession_)) return "";
      return get_node().get_frame_value(uniprot_accession_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_uniprot_accession() const {
    try {
      if (!get_node().get_has_value(uniprot_accession_)) return "";
      return get_node().get_static_value(uniprot_accession_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_label_asym_id() const {
    try {
      if (!get_node().get_has_value(label_asym_id_)) return "";
      return get_node().get_value(label_asym_id_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_label_asym_id() const {
    try {
      if (!get_node().get_has_value(label_asym_id_)) return "";
      return get_node().get_frame_value(label_asym_id_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_label_asym_id() const {
    try {
      if (!get_node().get_has_value(label_asym_id_)) return "";
      return get_node().get_static_value(label_asym_id_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_chain_type() const {
    try {
      if (!get_node().get_has_value(chain_type_)) return "UnknownChainType";
      return get_node().get_value(chain_type_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_chain_type() const {
    try {
      if (!get_node().get_has_value(chain_type_)) return "UnknownChainType";
      return get_node().get_frame_value(chain_type_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_chain_type() const {
    try {
      if (!get_node().get_has_value(chain_type_)) return "UnknownChainType";
      return get_node().get_static_value(chain_type_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ChainConst"; }
  RMF_SHOWABLE(ChainConst, "Chain: " << get_node());
};
/** See also ChainFactory.
 */
class Chain : public ChainConst {
  friend class ChainFactory;
  Chain(NodeHandle nh, StringKey chain_id, StringKey sequence,
        IntKey sequence_offset, StringKey uniprot_accession,
        StringKey label_asym_id, StringKey chain_type)
      : ChainConst(nh, chain_id, sequence, sequence_offset, uniprot_accession,
                   label_asym_id, chain_type) {}

 public:
  void set_chain_id(String v) {
    try {
      get_node().set_value(chain_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_chain_id(String v) {
    try {
      get_node().set_frame_value(chain_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_chain_id(String v) {
    try {
      get_node().set_static_value(chain_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_sequence(String v) {
    try {
      get_node().set_value(sequence_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_sequence(String v) {
    try {
      get_node().set_frame_value(sequence_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_sequence(String v) {
    try {
      get_node().set_static_value(sequence_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_sequence_offset(Int v) {
    try {
      get_node().set_value(sequence_offset_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_sequence_offset(Int v) {
    try {
      get_node().set_frame_value(sequence_offset_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_sequence_offset(Int v) {
    try {
      get_node().set_static_value(sequence_offset_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_uniprot_accession(String v) {
    try {
      get_node().set_value(uniprot_accession_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_uniprot_accession(String v) {
    try {
      get_node().set_frame_value(uniprot_accession_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_uniprot_accession(String v) {
    try {
      get_node().set_static_value(uniprot_accession_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_label_asym_id(String v) {
    try {
      get_node().set_value(label_asym_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_label_asym_id(String v) {
    try {
      get_node().set_frame_value(label_asym_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_label_asym_id(String v) {
    try {
      get_node().set_static_value(label_asym_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_chain_type(String v) {
    try {
      get_node().set_value(chain_type_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_chain_type(String v) {
    try {
      get_node().set_frame_value(chain_type_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_chain_type(String v) {
    try {
      get_node().set_static_value(chain_type_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Chain"; }
};

/** Create decorators of type Chain.
 */
class ChainFactory : public Factory {
  Category cat_;
  StringKey chain_id_;
  StringKey sequence_;
  IntKey sequence_offset_;
  StringKey uniprot_accession_;
  StringKey label_asym_id_;
  StringKey chain_type_;

 public:
  ChainFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        chain_id_(fh.get_key<StringTag>(cat_, "chain id")),
        sequence_(fh.get_key<StringTag>(cat_, "sequence")),
        sequence_offset_(fh.get_key<IntTag>(cat_, "sequence offset")),
        uniprot_accession_(fh.get_key<StringTag>(cat_, "uniprot accession")),
        label_asym_id_(fh.get_key<StringTag>(cat_, "label asym id")),
        chain_type_(fh.get_key<StringTag>(cat_, "chain type")) {}
  ChainFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        chain_id_(fh.get_key<StringTag>(cat_, "chain id")),
        sequence_(fh.get_key<StringTag>(cat_, "sequence")),
        sequence_offset_(fh.get_key<IntTag>(cat_, "sequence offset")),
        uniprot_accession_(fh.get_key<StringTag>(cat_, "uniprot accession")),
        label_asym_id_(fh.get_key<StringTag>(cat_, "label asym id")),
        chain_type_(fh.get_key<StringTag>(cat_, "chain type")) {}
  /** Get a ChainConst for nh.*/
  ChainConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Chain");
    return ChainConst(nh, chain_id_, sequence_, sequence_offset_,
                      uniprot_accession_, label_asym_id_, chain_type_);
  }
  /** Get a Chain for nh.*/
  Chain get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Chain");
    return Chain(nh, chain_id_, sequence_, sequence_offset_, uniprot_accession_,
                 label_asym_id_, chain_type_);
  }
  /** Check whether nh has all the attributes required to be a
      ChainConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(chain_id_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(chain_id_).get_is_null();
  }
  RMF_SHOWABLE(ChainFactory, "ChainFactory");
};
#ifndef RMF_DOXYGEN
struct ChainConstFactory : public ChainFactory {
  ChainConstFactory(FileConstHandle fh) : ChainFactory(fh) {}
  ChainConstFactory(FileHandle fh) : ChainFactory(fh) {}
};
#endif

/** See also Fragment and FragmentFactory.
 */
class FragmentConst : public Decorator {
  friend class FragmentFactory;

 protected:
  IntsKey residue_indexes_;
  FragmentConst(NodeConstHandle nh, IntsKey residue_indexes)
      : Decorator(nh), residue_indexes_(residue_indexes) {}

 public:
  Ints get_residue_indexes() const {
    try {
      return get_node().get_value(residue_indexes_);
    }
    RMF_DECORATOR_CATCH();
  }
  Ints get_frame_residue_indexes() const {
    try {
      return get_node().get_frame_value(residue_indexes_);
    }
    RMF_DECORATOR_CATCH();
  }
  Ints get_static_residue_indexes() const {
    try {
      return get_node().get_static_value(residue_indexes_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "FragmentConst"; }
  RMF_SHOWABLE(FragmentConst, "Fragment: " << get_node());
};
/** See also FragmentFactory.
 */
class Fragment : public FragmentConst {
  friend class FragmentFactory;
  Fragment(NodeHandle nh, IntsKey residue_indexes)
      : FragmentConst(nh, residue_indexes) {}

 public:
  void set_residue_indexes(Ints v) {
    try {
      get_node().set_value(residue_indexes_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_residue_indexes(Ints v) {
    try {
      get_node().set_frame_value(residue_indexes_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_residue_indexes(Ints v) {
    try {
      get_node().set_static_value(residue_indexes_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Fragment"; }
};

/** Create decorators of type Fragment.
 */
class FragmentFactory : public Factory {
  Category cat_;
  IntsKey residue_indexes_;

 public:
  FragmentFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        residue_indexes_(fh.get_key<IntsTag>(cat_, "residue indexes")) {}
  FragmentFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        residue_indexes_(fh.get_key<IntsTag>(cat_, "residue indexes")) {}
  /** Get a FragmentConst for nh.*/
  FragmentConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Fragment");
    return FragmentConst(nh, residue_indexes_);
  }
  /** Get a Fragment for nh.*/
  Fragment get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Fragment");
    return Fragment(nh, residue_indexes_);
  }
  /** Check whether nh has all the attributes required to be a
      FragmentConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(residue_indexes_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(residue_indexes_).get_is_null();
  }
  RMF_SHOWABLE(FragmentFactory, "FragmentFactory");
};
#ifndef RMF_DOXYGEN
struct FragmentConstFactory : public FragmentFactory {
  FragmentConstFactory(FileConstHandle fh) : FragmentFactory(fh) {}
  FragmentConstFactory(FileHandle fh) : FragmentFactory(fh) {}
};
#endif

/** See also BackwardsCompatibilityFragment and
 * BackwardsCompatibilityFragmentFactory.
 */
class BackwardsCompatibilityFragmentConst : public Decorator {
  friend class BackwardsCompatibilityFragmentFactory;

 protected:
  IntsKey indexes_;
  BackwardsCompatibilityFragmentConst(NodeConstHandle nh, IntsKey indexes)
      : Decorator(nh), indexes_(indexes) {}

 public:
  Ints get_indexes() const {
    try {
      return get_node().get_value(indexes_);
    }
    RMF_DECORATOR_CATCH();
  }
  Ints get_frame_indexes() const {
    try {
      return get_node().get_frame_value(indexes_);
    }
    RMF_DECORATOR_CATCH();
  }
  Ints get_static_indexes() const {
    try {
      return get_node().get_static_value(indexes_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "BackwardsCompatibilityFragmentConst";
  }
  RMF_SHOWABLE(BackwardsCompatibilityFragmentConst,
               "BackwardsCompatibilityFragment: " << get_node());
};
/** See also BackwardsCompatibilityFragmentFactory.
 */
class BackwardsCompatibilityFragment
    : public BackwardsCompatibilityFragmentConst {
  friend class BackwardsCompatibilityFragmentFactory;
  BackwardsCompatibilityFragment(NodeHandle nh, IntsKey indexes)
      : BackwardsCompatibilityFragmentConst(nh, indexes) {}

 public:
  void set_indexes(Ints v) {
    try {
      get_node().set_value(indexes_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_indexes(Ints v) {
    try {
      get_node().set_frame_value(indexes_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_indexes(Ints v) {
    try {
      get_node().set_static_value(indexes_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "BackwardsCompatibilityFragment";
  }
};

/** Create decorators of type BackwardsCompatibilityFragment.
 */
class BackwardsCompatibilityFragmentFactory : public Factory {
  Category cat_;
  IntsKey indexes_;

 public:
  BackwardsCompatibilityFragmentFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        indexes_(fh.get_key<IntsTag>(cat_, "indexes")) {}
  BackwardsCompatibilityFragmentFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        indexes_(fh.get_key<IntsTag>(cat_, "indexes")) {}
  /** Get a BackwardsCompatibilityFragmentConst for nh.*/
  BackwardsCompatibilityFragmentConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  BackwardsCompatibilityFragment");
    return BackwardsCompatibilityFragmentConst(nh, indexes_);
  }
  /** Get a BackwardsCompatibilityFragment for nh.*/
  BackwardsCompatibilityFragment get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  BackwardsCompatibilityFragment");
    return BackwardsCompatibilityFragment(nh, indexes_);
  }
  /** Check whether nh has all the attributes required to be a
      BackwardsCompatibilityFragmentConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(indexes_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(indexes_).get_is_null();
  }
  RMF_SHOWABLE(BackwardsCompatibilityFragmentFactory,
               "BackwardsCompatibilityFragmentFactory");
};
#ifndef RMF_DOXYGEN
struct BackwardsCompatibilityFragmentConstFactory
    : public BackwardsCompatibilityFragmentFactory {
  BackwardsCompatibilityFragmentConstFactory(FileConstHandle fh)
      : BackwardsCompatibilityFragmentFactory(fh) {}
  BackwardsCompatibilityFragmentConstFactory(FileHandle fh)
      : BackwardsCompatibilityFragmentFactory(fh) {}
};
#endif

/** See also Domain and DomainFactory.
 */
class DomainConst : public Decorator {
  friend class DomainFactory;

 protected:
  std::array<IntKey, 2> residue_indexes_;
  DomainConst(NodeConstHandle nh, std::array<IntKey, 2> residue_indexes)
      : Decorator(nh), residue_indexes_(residue_indexes) {}

 public:
  IntRange get_residue_indexes() const {
    try {
      IntRange ret;
      ret[0] = get_node().get_value(residue_indexes_[0]);
      ret[1] = get_node().get_value(residue_indexes_[1]);
      return ret;
    }
    RMF_DECORATOR_CATCH();
  }
  IntRange get_static_residue_indexes() const {
    try {
      IntRange ret;
      ret[0] = get_node().get_static_value(residue_indexes_[0]);
      ret[1] = get_node().get_static_value(residue_indexes_[1]);
      return ret;
    }
    RMF_DECORATOR_CATCH();
  }
  IntRange get_frame_residue_indexes() const {
    try {
      IntRange ret;
      ret[0] = get_node().get_frame_value(residue_indexes_[0]);
      ret[1] = get_node().get_frame_value(residue_indexes_[1]);
      return ret;
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "DomainConst"; }
  RMF_SHOWABLE(DomainConst, "Domain: " << get_node());
};
/** See also DomainFactory.
 */
class Domain : public DomainConst {
  friend class DomainFactory;
  Domain(NodeHandle nh, std::array<IntKey, 2> residue_indexes)
      : DomainConst(nh, residue_indexes) {}

 public:
  void set_residue_indexes(Int v0, Int v1) {
    try {
      get_node().set_value(residue_indexes_[0], v0);
      get_node().set_value(residue_indexes_[1], v1);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_residue_indexes(Int v0, Int v1) {
    try {
      get_node().set_frame_value(residue_indexes_[0], v0);
      get_node().set_frame_value(residue_indexes_[1], v1);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_residue_indexes(Int v0, Int v1) {
    try {
      get_node().set_static_value(residue_indexes_[0], v0);
      get_node().set_static_value(residue_indexes_[1], v1);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Domain"; }
};

/** Create decorators of type Domain.
 */
class DomainFactory : public Factory {
  Category cat_;
  std::array<IntKey, 2> residue_indexes_;
  template <class H>
  std::array<IntKey, 2> get_residue_indexes_keys(H fh) const {
    std::array<IntKey, 2> ret;
    ret[0] = fh.template get_key<IntTag>(cat_, "first residue index");
    ret[1] = fh.template get_key<IntTag>(cat_, "last residue index");
    return ret;
  }

 public:
  DomainFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        residue_indexes_(get_residue_indexes_keys(fh)) {}
  DomainFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        residue_indexes_(get_residue_indexes_keys(fh)) {}
  /** Get a DomainConst for nh.*/
  DomainConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Domain");
    return DomainConst(nh, residue_indexes_);
  }
  /** Get a Domain for nh.*/
  Domain get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Domain");
    return Domain(nh, residue_indexes_);
  }
  /** Check whether nh has all the attributes required to be a
      DomainConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(residue_indexes_[0]).get_is_null() &&
           !nh.get_value(residue_indexes_[1]).get_is_null() &&
           nh.get_value(residue_indexes_[0]) <
               nh.get_value(residue_indexes_[1]);
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(residue_indexes_[0]).get_is_null() &&
           !nh.get_static_value(residue_indexes_[1]).get_is_null() &&
           nh.get_value(residue_indexes_[0]) <
               nh.get_value(residue_indexes_[1]);
  }
  RMF_SHOWABLE(DomainFactory, "DomainFactory");
};
#ifndef RMF_DOXYGEN
struct DomainConstFactory : public DomainFactory {
  DomainConstFactory(FileConstHandle fh) : DomainFactory(fh) {}
  DomainConstFactory(FileHandle fh) : DomainFactory(fh) {}
};
#endif

/** See also Typed and TypedFactory.
 */
class TypedConst : public Decorator {
  friend class TypedFactory;

 protected:
  StringKey type_name_;
  TypedConst(NodeConstHandle nh, StringKey type_name)
      : Decorator(nh), type_name_(type_name) {}

 public:
  String get_type_name() const {
    try {
      return get_node().get_value(type_name_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_type_name() const {
    try {
      return get_node().get_frame_value(type_name_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_type_name() const {
    try {
      return get_node().get_static_value(type_name_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "TypedConst"; }
  RMF_SHOWABLE(TypedConst, "Typed: " << get_node());
};
/** See also TypedFactory.
 */
class Typed : public TypedConst {
  friend class TypedFactory;
  Typed(NodeHandle nh, StringKey type_name) : TypedConst(nh, type_name) {}

 public:
  void set_type_name(String v) {
    try {
      get_node().set_value(type_name_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_type_name(String v) {
    try {
      get_node().set_frame_value(type_name_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_type_name(String v) {
    try {
      get_node().set_static_value(type_name_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Typed"; }
};

/** Create decorators of type Typed.
 */
class TypedFactory : public Factory {
  Category cat_;
  StringKey type_name_;

 public:
  TypedFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        type_name_(fh.get_key<StringTag>(cat_, "type name")) {}
  TypedFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        type_name_(fh.get_key<StringTag>(cat_, "type name")) {}
  /** Get a TypedConst for nh.*/
  TypedConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Typed");
    return TypedConst(nh, type_name_);
  }
  /** Get a Typed for nh.*/
  Typed get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Typed");
    return Typed(nh, type_name_);
  }
  /** Check whether nh has all the attributes required to be a
      TypedConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(type_name_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(type_name_).get_is_null();
  }
  RMF_SHOWABLE(TypedFactory, "TypedFactory");
};
#ifndef RMF_DOXYGEN
struct TypedConstFactory : public TypedFactory {
  TypedConstFactory(FileConstHandle fh) : TypedFactory(fh) {}
  TypedConstFactory(FileHandle fh) : TypedFactory(fh) {}
};
#endif

/** See also Copy and CopyFactory.
 */
class CopyConst : public Decorator {
  friend class CopyFactory;

 protected:
  IntKey copy_index_;
  CopyConst(NodeConstHandle nh, IntKey copy_index)
      : Decorator(nh), copy_index_(copy_index) {}

 public:
  Int get_copy_index() const {
    try {
      return get_node().get_value(copy_index_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_copy_index() const {
    try {
      return get_node().get_frame_value(copy_index_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_copy_index() const {
    try {
      return get_node().get_static_value(copy_index_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "CopyConst"; }
  RMF_SHOWABLE(CopyConst, "Copy: " << get_node());
};
/** See also CopyFactory.
 */
class Copy : public CopyConst {
  friend class CopyFactory;
  Copy(NodeHandle nh, IntKey copy_index) : CopyConst(nh, copy_index) {}

 public:
  void set_copy_index(Int v) {
    try {
      get_node().set_value(copy_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_copy_index(Int v) {
    try {
      get_node().set_frame_value(copy_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_copy_index(Int v) {
    try {
      get_node().set_static_value(copy_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "Copy"; }
};

/** Create decorators of type Copy.
 */
class CopyFactory : public Factory {
  Category cat_;
  IntKey copy_index_;

 public:
  CopyFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        copy_index_(fh.get_key<IntTag>(cat_, "copy index")) {}
  CopyFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        copy_index_(fh.get_key<IntTag>(cat_, "copy index")) {}
  /** Get a CopyConst for nh.*/
  CopyConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Copy");
    return CopyConst(nh, copy_index_);
  }
  /** Get a Copy for nh.*/
  Copy get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  Copy");
    return Copy(nh, copy_index_);
  }
  /** Check whether nh has all the attributes required to be a
      CopyConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(copy_index_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(copy_index_).get_is_null();
  }
  RMF_SHOWABLE(CopyFactory, "CopyFactory");
};
#ifndef RMF_DOXYGEN
struct CopyConstFactory : public CopyFactory {
  CopyConstFactory(FileConstHandle fh) : CopyFactory(fh) {}
  CopyConstFactory(FileHandle fh) : CopyFactory(fh) {}
};
#endif

/** See also State and StateFactory.
 */
class StateConst : public Decorator {
  friend class StateFactory;

 protected:
  IntKey state_index_;
  StateConst(NodeConstHandle nh, IntKey state_index)
      : Decorator(nh), state_index_(state_index) {}

 public:
  Int get_state_index() const {
    try {
      return get_node().get_value(state_index_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_state_index() const {
    try {
      return get_node().get_frame_value(state_index_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_state_index() const {
    try {
      return get_node().get_static_value(state_index_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "StateConst"; }
  RMF_SHOWABLE(StateConst, "State: " << get_node());
};
/** See also StateFactory.
 */
class State : public StateConst {
  friend class StateFactory;
  State(NodeHandle nh, IntKey state_index) : StateConst(nh, state_index) {}

 public:
  void set_state_index(Int v) {
    try {
      get_node().set_value(state_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_state_index(Int v) {
    try {
      get_node().set_frame_value(state_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_state_index(Int v) {
    try {
      get_node().set_static_value(state_index_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "State"; }
};

/** Create decorators of type State.
 */
class StateFactory : public Factory {
  Category cat_;
  IntKey state_index_;

 public:
  StateFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        state_index_(fh.get_key<IntTag>(cat_, "state index")) {}
  StateFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        state_index_(fh.get_key<IntTag>(cat_, "state index")) {}
  /** Get a StateConst for nh.*/
  StateConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  State");
    return StateConst(nh, state_index_);
  }
  /** Get a State for nh.*/
  State get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  State");
    return State(nh, state_index_);
  }
  /** Check whether nh has all the attributes required to be a
      StateConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(state_index_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(state_index_).get_is_null();
  }
  RMF_SHOWABLE(StateFactory, "StateFactory");
};
#ifndef RMF_DOXYGEN
struct StateConstFactory : public StateFactory {
  StateConstFactory(FileConstHandle fh) : StateFactory(fh) {}
  StateConstFactory(FileHandle fh) : StateFactory(fh) {}
};
#endif

/** See also ExplicitResolution and ExplicitResolutionFactory.
 */
class ExplicitResolutionConst : public Decorator {
  friend class ExplicitResolutionFactory;

 protected:
  FloatKey explicit_resolution_;
  ExplicitResolutionConst(NodeConstHandle nh, FloatKey explicit_resolution)
      : Decorator(nh), explicit_resolution_(explicit_resolution) {}

 public:
  Float get_explicit_resolution() const {
    try {
      return get_node().get_value(explicit_resolution_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_explicit_resolution() const {
    try {
      return get_node().get_frame_value(explicit_resolution_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_explicit_resolution() const {
    try {
      return get_node().get_static_value(explicit_resolution_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "ExplicitResolutionConst";
  }
  RMF_SHOWABLE(ExplicitResolutionConst, "ExplicitResolution: " << get_node());
};
/** See also ExplicitResolutionFactory.
 */
class ExplicitResolution : public ExplicitResolutionConst {
  friend class ExplicitResolutionFactory;
  ExplicitResolution(NodeHandle nh, FloatKey explicit_resolution)
      : ExplicitResolutionConst(nh, explicit_resolution) {}

 public:
  void set_explicit_resolution(Float v) {
    try {
      get_node().set_value(explicit_resolution_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_explicit_resolution(Float v) {
    try {
      get_node().set_frame_value(explicit_resolution_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_explicit_resolution(Float v) {
    try {
      get_node().set_static_value(explicit_resolution_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ExplicitResolution"; }
};

/** Create decorators of type ExplicitResolution.
 */
class ExplicitResolutionFactory : public Factory {
  Category cat_;
  FloatKey explicit_resolution_;

 public:
  ExplicitResolutionFactory(FileConstHandle fh)
      : cat_(fh.get_category("sequence")),
        explicit_resolution_(
            fh.get_key<FloatTag>(cat_, "explicit resolution")) {}
  ExplicitResolutionFactory(FileHandle fh)
      : cat_(fh.get_category("sequence")),
        explicit_resolution_(
            fh.get_key<FloatTag>(cat_, "explicit resolution")) {}
  /** Get a ExplicitResolutionConst for nh.*/
  ExplicitResolutionConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ExplicitResolution");
    return ExplicitResolutionConst(nh, explicit_resolution_);
  }
  /** Get a ExplicitResolution for nh.*/
  ExplicitResolution get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::REPRESENTATION),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ExplicitResolution");
    return ExplicitResolution(nh, explicit_resolution_);
  }
  /** Check whether nh has all the attributes required to be a
      ExplicitResolutionConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_value(explicit_resolution_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::REPRESENTATION) &&
           !nh.get_static_value(explicit_resolution_).get_is_null();
  }
  RMF_SHOWABLE(ExplicitResolutionFactory, "ExplicitResolutionFactory");
};
#ifndef RMF_DOXYGEN
struct ExplicitResolutionConstFactory : public ExplicitResolutionFactory {
  ExplicitResolutionConstFactory(FileConstHandle fh)
      : ExplicitResolutionFactory(fh) {}
  ExplicitResolutionConstFactory(FileHandle fh)
      : ExplicitResolutionFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_SEQUENCE_DECORATORS_H */
