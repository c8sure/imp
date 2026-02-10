/**
 *  \file RMF/decorator/provenance.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_PROVENANCE_DECORATORS_H
#define RMF_PROVENANCE_DECORATORS_H

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

/** See also StructureProvenance and StructureProvenanceFactory.
 */
class StructureProvenanceConst : public Decorator {
  friend class StructureProvenanceFactory;

 protected:
  StringKey structure_filename_;
  StringKey structure_chain_;
  IntKey structure_residue_offset_;
  StructureProvenanceConst(NodeConstHandle nh, StringKey structure_filename,
                           StringKey structure_chain,
                           IntKey structure_residue_offset)
      : Decorator(nh),
        structure_filename_(structure_filename),
        structure_chain_(structure_chain),
        structure_residue_offset_(structure_residue_offset) {}

 public:
  String get_filename() const {
    try {
      String relpath = get_node().get_value(structure_filename_);
      String filename = get_node().get_file().get_path();
      return internal::get_absolute_path(filename, relpath);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_chain() const {
    try {
      return get_node().get_value(structure_chain_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_chain() const {
    try {
      return get_node().get_frame_value(structure_chain_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_chain() const {
    try {
      return get_node().get_static_value(structure_chain_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_residue_offset() const {
    try {
      if (!get_node().get_has_value(structure_residue_offset_)) return 0;
      return get_node().get_value(structure_residue_offset_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_residue_offset() const {
    try {
      if (!get_node().get_has_value(structure_residue_offset_)) return 0;
      return get_node().get_frame_value(structure_residue_offset_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_residue_offset() const {
    try {
      if (!get_node().get_has_value(structure_residue_offset_)) return 0;
      return get_node().get_static_value(structure_residue_offset_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "StructureProvenanceConst";
  }
  RMF_SHOWABLE(StructureProvenanceConst, "StructureProvenance: " << get_node());
};
/** See also StructureProvenanceFactory.
 */
class StructureProvenance : public StructureProvenanceConst {
  friend class StructureProvenanceFactory;
  StructureProvenance(NodeHandle nh, StringKey structure_filename,
                      StringKey structure_chain,
                      IntKey structure_residue_offset)
      : StructureProvenanceConst(nh, structure_filename, structure_chain,
                                 structure_residue_offset) {}

 public:
  void set_filename(String path) {
    try {
      String filename = get_node().get_file().get_path();
      String relpath = internal::get_relative_path(filename, path);
      get_node().set_value(structure_filename_, relpath);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_chain(String v) {
    try {
      get_node().set_value(structure_chain_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_chain(String v) {
    try {
      get_node().set_frame_value(structure_chain_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_chain(String v) {
    try {
      get_node().set_static_value(structure_chain_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_residue_offset(Int v) {
    try {
      get_node().set_value(structure_residue_offset_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_residue_offset(Int v) {
    try {
      get_node().set_frame_value(structure_residue_offset_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_residue_offset(Int v) {
    try {
      get_node().set_static_value(structure_residue_offset_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "StructureProvenance"; }
};

/** Create decorators of type StructureProvenance.
 */
class StructureProvenanceFactory : public Factory {
  Category cat_;
  StringKey structure_filename_;
  StringKey structure_chain_;
  IntKey structure_residue_offset_;

 public:
  StructureProvenanceFactory(FileConstHandle fh)
      : cat_(fh.get_category("provenance")),
        structure_filename_(fh.get_key<StringTag>(cat_, "structure filename")),
        structure_chain_(fh.get_key<StringTag>(cat_, "structure chain")),
        structure_residue_offset_(
            fh.get_key<IntTag>(cat_, "structure residue offset")) {}
  StructureProvenanceFactory(FileHandle fh)
      : cat_(fh.get_category("provenance")),
        structure_filename_(fh.get_key<StringTag>(cat_, "structure filename")),
        structure_chain_(fh.get_key<StringTag>(cat_, "structure chain")),
        structure_residue_offset_(
            fh.get_key<IntTag>(cat_, "structure residue offset")) {}
  /** Get a StructureProvenanceConst for nh.*/
  StructureProvenanceConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  StructureProvenance");
    return StructureProvenanceConst(nh, structure_filename_, structure_chain_,
                                    structure_residue_offset_);
  }
  /** Get a StructureProvenance for nh.*/
  StructureProvenance get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  StructureProvenance");
    return StructureProvenance(nh, structure_filename_, structure_chain_,
                               structure_residue_offset_);
  }
  /** Check whether nh has all the attributes required to be a
      StructureProvenanceConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_value(structure_filename_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_static_value(structure_filename_).get_is_null() &&
           !nh.get_static_value(structure_chain_).get_is_null();
  }
  RMF_SHOWABLE(StructureProvenanceFactory, "StructureProvenanceFactory");
};
#ifndef RMF_DOXYGEN
struct StructureProvenanceConstFactory : public StructureProvenanceFactory {
  StructureProvenanceConstFactory(FileConstHandle fh)
      : StructureProvenanceFactory(fh) {}
  StructureProvenanceConstFactory(FileHandle fh)
      : StructureProvenanceFactory(fh) {}
};
#endif

/** See also SampleProvenance and SampleProvenanceFactory.
 */
class SampleProvenanceConst : public Decorator {
  friend class SampleProvenanceFactory;

 protected:
  StringKey sampling_method_;
  IntKey sampling_frames_;
  IntKey sampling_iterations_;
  IntKey sampling_replicas_;
  SampleProvenanceConst(NodeConstHandle nh, StringKey sampling_method,
                        IntKey sampling_frames, IntKey sampling_iterations,
                        IntKey sampling_replicas)
      : Decorator(nh),
        sampling_method_(sampling_method),
        sampling_frames_(sampling_frames),
        sampling_iterations_(sampling_iterations),
        sampling_replicas_(sampling_replicas) {}

 public:
  String get_method() const {
    try {
      return get_node().get_value(sampling_method_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_method() const {
    try {
      return get_node().get_frame_value(sampling_method_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_method() const {
    try {
      return get_node().get_static_value(sampling_method_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_frames() const {
    try {
      return get_node().get_value(sampling_frames_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_frames() const {
    try {
      return get_node().get_frame_value(sampling_frames_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_frames() const {
    try {
      return get_node().get_static_value(sampling_frames_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_iterations() const {
    try {
      return get_node().get_value(sampling_iterations_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_iterations() const {
    try {
      return get_node().get_frame_value(sampling_iterations_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_iterations() const {
    try {
      return get_node().get_static_value(sampling_iterations_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_replicas() const {
    try {
      return get_node().get_value(sampling_replicas_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_replicas() const {
    try {
      return get_node().get_frame_value(sampling_replicas_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_replicas() const {
    try {
      return get_node().get_static_value(sampling_replicas_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "SampleProvenanceConst";
  }
  RMF_SHOWABLE(SampleProvenanceConst, "SampleProvenance: " << get_node());
};
/** See also SampleProvenanceFactory.
 */
class SampleProvenance : public SampleProvenanceConst {
  friend class SampleProvenanceFactory;
  SampleProvenance(NodeHandle nh, StringKey sampling_method,
                   IntKey sampling_frames, IntKey sampling_iterations,
                   IntKey sampling_replicas)
      : SampleProvenanceConst(nh, sampling_method, sampling_frames,
                              sampling_iterations, sampling_replicas) {}

 public:
  void set_method(String v) {
    try {
      get_node().set_value(sampling_method_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_method(String v) {
    try {
      get_node().set_frame_value(sampling_method_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_method(String v) {
    try {
      get_node().set_static_value(sampling_method_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_frames(Int v) {
    try {
      get_node().set_value(sampling_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_frames(Int v) {
    try {
      get_node().set_frame_value(sampling_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_frames(Int v) {
    try {
      get_node().set_static_value(sampling_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_iterations(Int v) {
    try {
      get_node().set_value(sampling_iterations_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_iterations(Int v) {
    try {
      get_node().set_frame_value(sampling_iterations_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_iterations(Int v) {
    try {
      get_node().set_static_value(sampling_iterations_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_replicas(Int v) {
    try {
      get_node().set_value(sampling_replicas_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_replicas(Int v) {
    try {
      get_node().set_frame_value(sampling_replicas_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_replicas(Int v) {
    try {
      get_node().set_static_value(sampling_replicas_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "SampleProvenance"; }
};

/** Create decorators of type SampleProvenance.
 */
class SampleProvenanceFactory : public Factory {
  Category cat_;
  StringKey sampling_method_;
  IntKey sampling_frames_;
  IntKey sampling_iterations_;
  IntKey sampling_replicas_;

 public:
  SampleProvenanceFactory(FileConstHandle fh)
      : cat_(fh.get_category("provenance")),
        sampling_method_(fh.get_key<StringTag>(cat_, "sampling method")),
        sampling_frames_(fh.get_key<IntTag>(cat_, "sampling frames")),
        sampling_iterations_(fh.get_key<IntTag>(cat_, "sampling iterations")),
        sampling_replicas_(fh.get_key<IntTag>(cat_, "sampling replicas")) {}
  SampleProvenanceFactory(FileHandle fh)
      : cat_(fh.get_category("provenance")),
        sampling_method_(fh.get_key<StringTag>(cat_, "sampling method")),
        sampling_frames_(fh.get_key<IntTag>(cat_, "sampling frames")),
        sampling_iterations_(fh.get_key<IntTag>(cat_, "sampling iterations")),
        sampling_replicas_(fh.get_key<IntTag>(cat_, "sampling replicas")) {}
  /** Get a SampleProvenanceConst for nh.*/
  SampleProvenanceConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  SampleProvenance");
    return SampleProvenanceConst(nh, sampling_method_, sampling_frames_,
                                 sampling_iterations_, sampling_replicas_);
  }
  /** Get a SampleProvenance for nh.*/
  SampleProvenance get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  SampleProvenance");
    return SampleProvenance(nh, sampling_method_, sampling_frames_,
                            sampling_iterations_, sampling_replicas_);
  }
  /** Check whether nh has all the attributes required to be a
      SampleProvenanceConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_value(sampling_method_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_static_value(sampling_method_).get_is_null() &&
           !nh.get_static_value(sampling_frames_).get_is_null() &&
           !nh.get_static_value(sampling_iterations_).get_is_null() &&
           !nh.get_static_value(sampling_replicas_).get_is_null();
  }
  RMF_SHOWABLE(SampleProvenanceFactory, "SampleProvenanceFactory");
};
#ifndef RMF_DOXYGEN
struct SampleProvenanceConstFactory : public SampleProvenanceFactory {
  SampleProvenanceConstFactory(FileConstHandle fh)
      : SampleProvenanceFactory(fh) {}
  SampleProvenanceConstFactory(FileHandle fh) : SampleProvenanceFactory(fh) {}
};
#endif

/** See also CombineProvenance and CombineProvenanceFactory.
 */
class CombineProvenanceConst : public Decorator {
  friend class CombineProvenanceFactory;

 protected:
  IntKey combined_runs_;
  IntKey combined_frames_;
  CombineProvenanceConst(NodeConstHandle nh, IntKey combined_runs,
                         IntKey combined_frames)
      : Decorator(nh),
        combined_runs_(combined_runs),
        combined_frames_(combined_frames) {}

 public:
  Int get_runs() const {
    try {
      return get_node().get_value(combined_runs_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_runs() const {
    try {
      return get_node().get_frame_value(combined_runs_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_runs() const {
    try {
      return get_node().get_static_value(combined_runs_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_frames() const {
    try {
      return get_node().get_value(combined_frames_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_frames() const {
    try {
      return get_node().get_frame_value(combined_frames_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_frames() const {
    try {
      return get_node().get_static_value(combined_frames_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "CombineProvenanceConst";
  }
  RMF_SHOWABLE(CombineProvenanceConst, "CombineProvenance: " << get_node());
};
/** See also CombineProvenanceFactory.
 */
class CombineProvenance : public CombineProvenanceConst {
  friend class CombineProvenanceFactory;
  CombineProvenance(NodeHandle nh, IntKey combined_runs, IntKey combined_frames)
      : CombineProvenanceConst(nh, combined_runs, combined_frames) {}

 public:
  void set_runs(Int v) {
    try {
      get_node().set_value(combined_runs_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_runs(Int v) {
    try {
      get_node().set_frame_value(combined_runs_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_runs(Int v) {
    try {
      get_node().set_static_value(combined_runs_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_frames(Int v) {
    try {
      get_node().set_value(combined_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_frames(Int v) {
    try {
      get_node().set_frame_value(combined_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_frames(Int v) {
    try {
      get_node().set_static_value(combined_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "CombineProvenance"; }
};

/** Create decorators of type CombineProvenance.
 */
class CombineProvenanceFactory : public Factory {
  Category cat_;
  IntKey combined_runs_;
  IntKey combined_frames_;

 public:
  CombineProvenanceFactory(FileConstHandle fh)
      : cat_(fh.get_category("provenance")),
        combined_runs_(fh.get_key<IntTag>(cat_, "combined runs")),
        combined_frames_(fh.get_key<IntTag>(cat_, "combined frames")) {}
  CombineProvenanceFactory(FileHandle fh)
      : cat_(fh.get_category("provenance")),
        combined_runs_(fh.get_key<IntTag>(cat_, "combined runs")),
        combined_frames_(fh.get_key<IntTag>(cat_, "combined frames")) {}
  /** Get a CombineProvenanceConst for nh.*/
  CombineProvenanceConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  CombineProvenance");
    return CombineProvenanceConst(nh, combined_runs_, combined_frames_);
  }
  /** Get a CombineProvenance for nh.*/
  CombineProvenance get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  CombineProvenance");
    return CombineProvenance(nh, combined_runs_, combined_frames_);
  }
  /** Check whether nh has all the attributes required to be a
      CombineProvenanceConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_value(combined_runs_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_static_value(combined_runs_).get_is_null() &&
           !nh.get_static_value(combined_frames_).get_is_null();
  }
  RMF_SHOWABLE(CombineProvenanceFactory, "CombineProvenanceFactory");
};
#ifndef RMF_DOXYGEN
struct CombineProvenanceConstFactory : public CombineProvenanceFactory {
  CombineProvenanceConstFactory(FileConstHandle fh)
      : CombineProvenanceFactory(fh) {}
  CombineProvenanceConstFactory(FileHandle fh) : CombineProvenanceFactory(fh) {}
};
#endif

/** See also FilterProvenance and FilterProvenanceFactory.
 */
class FilterProvenanceConst : public Decorator {
  friend class FilterProvenanceFactory;

 protected:
  StringKey filter_method_;
  FloatKey filter_threshold_;
  IntKey filter_frames_;
  FilterProvenanceConst(NodeConstHandle nh, StringKey filter_method,
                        FloatKey filter_threshold, IntKey filter_frames)
      : Decorator(nh),
        filter_method_(filter_method),
        filter_threshold_(filter_threshold),
        filter_frames_(filter_frames) {}

 public:
  String get_method() const {
    try {
      return get_node().get_value(filter_method_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_method() const {
    try {
      return get_node().get_frame_value(filter_method_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_method() const {
    try {
      return get_node().get_static_value(filter_method_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_threshold() const {
    try {
      return get_node().get_value(filter_threshold_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_threshold() const {
    try {
      return get_node().get_frame_value(filter_threshold_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_threshold() const {
    try {
      return get_node().get_static_value(filter_threshold_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_frames() const {
    try {
      return get_node().get_value(filter_frames_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_frames() const {
    try {
      return get_node().get_frame_value(filter_frames_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_frames() const {
    try {
      return get_node().get_static_value(filter_frames_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "FilterProvenanceConst";
  }
  RMF_SHOWABLE(FilterProvenanceConst, "FilterProvenance: " << get_node());
};
/** See also FilterProvenanceFactory.
 */
class FilterProvenance : public FilterProvenanceConst {
  friend class FilterProvenanceFactory;
  FilterProvenance(NodeHandle nh, StringKey filter_method,
                   FloatKey filter_threshold, IntKey filter_frames)
      : FilterProvenanceConst(nh, filter_method, filter_threshold,
                              filter_frames) {}

 public:
  void set_method(String v) {
    try {
      get_node().set_value(filter_method_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_method(String v) {
    try {
      get_node().set_frame_value(filter_method_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_method(String v) {
    try {
      get_node().set_static_value(filter_method_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_threshold(Float v) {
    try {
      get_node().set_value(filter_threshold_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_threshold(Float v) {
    try {
      get_node().set_frame_value(filter_threshold_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_threshold(Float v) {
    try {
      get_node().set_static_value(filter_threshold_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_frames(Int v) {
    try {
      get_node().set_value(filter_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_frames(Int v) {
    try {
      get_node().set_frame_value(filter_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_frames(Int v) {
    try {
      get_node().set_static_value(filter_frames_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "FilterProvenance"; }
};

/** Create decorators of type FilterProvenance.
 */
class FilterProvenanceFactory : public Factory {
  Category cat_;
  StringKey filter_method_;
  FloatKey filter_threshold_;
  IntKey filter_frames_;

 public:
  FilterProvenanceFactory(FileConstHandle fh)
      : cat_(fh.get_category("provenance")),
        filter_method_(fh.get_key<StringTag>(cat_, "filter method")),
        filter_threshold_(fh.get_key<FloatTag>(cat_, "filter threshold")),
        filter_frames_(fh.get_key<IntTag>(cat_, "filter frames")) {}
  FilterProvenanceFactory(FileHandle fh)
      : cat_(fh.get_category("provenance")),
        filter_method_(fh.get_key<StringTag>(cat_, "filter method")),
        filter_threshold_(fh.get_key<FloatTag>(cat_, "filter threshold")),
        filter_frames_(fh.get_key<IntTag>(cat_, "filter frames")) {}
  /** Get a FilterProvenanceConst for nh.*/
  FilterProvenanceConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  FilterProvenance");
    return FilterProvenanceConst(nh, filter_method_, filter_threshold_,
                                 filter_frames_);
  }
  /** Get a FilterProvenance for nh.*/
  FilterProvenance get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  FilterProvenance");
    return FilterProvenance(nh, filter_method_, filter_threshold_,
                            filter_frames_);
  }
  /** Check whether nh has all the attributes required to be a
      FilterProvenanceConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_value(filter_method_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_static_value(filter_method_).get_is_null() &&
           !nh.get_static_value(filter_threshold_).get_is_null() &&
           !nh.get_static_value(filter_frames_).get_is_null();
  }
  RMF_SHOWABLE(FilterProvenanceFactory, "FilterProvenanceFactory");
};
#ifndef RMF_DOXYGEN
struct FilterProvenanceConstFactory : public FilterProvenanceFactory {
  FilterProvenanceConstFactory(FileConstHandle fh)
      : FilterProvenanceFactory(fh) {}
  FilterProvenanceConstFactory(FileHandle fh) : FilterProvenanceFactory(fh) {}
};
#endif

/** See also ClusterProvenance and ClusterProvenanceFactory.
 */
class ClusterProvenanceConst : public Decorator {
  friend class ClusterProvenanceFactory;

 protected:
  IntKey cluster_members_;
  FloatKey cluster_precision_;
  StringKey cluster_density_;
  ClusterProvenanceConst(NodeConstHandle nh, IntKey cluster_members,
                         FloatKey cluster_precision, StringKey cluster_density)
      : Decorator(nh),
        cluster_members_(cluster_members),
        cluster_precision_(cluster_precision),
        cluster_density_(cluster_density) {}

 public:
  Int get_members() const {
    try {
      return get_node().get_value(cluster_members_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_members() const {
    try {
      return get_node().get_frame_value(cluster_members_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_members() const {
    try {
      return get_node().get_static_value(cluster_members_);
    }
    RMF_DECORATOR_CATCH();
  }

  Float get_precision() const {
    try {
      if (!get_node().get_has_value(cluster_precision_)) return 0.0;
      return get_node().get_value(cluster_precision_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_frame_precision() const {
    try {
      if (!get_node().get_has_value(cluster_precision_)) return 0.0;
      return get_node().get_frame_value(cluster_precision_);
    }
    RMF_DECORATOR_CATCH();
  }
  Float get_static_precision() const {
    try {
      if (!get_node().get_has_value(cluster_precision_)) return 0.0;
      return get_node().get_static_value(cluster_precision_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_density() const {
    try {
      if (!get_node().get_has_value(cluster_density_)) {
        return "";
      } else {
        String relpath = get_node().get_value(cluster_density_);
        String filename = get_node().get_file().get_path();
        return internal::get_absolute_path(filename, relpath);
      }
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "ClusterProvenanceConst";
  }
  RMF_SHOWABLE(ClusterProvenanceConst, "ClusterProvenance: " << get_node());
};
/** See also ClusterProvenanceFactory.
 */
class ClusterProvenance : public ClusterProvenanceConst {
  friend class ClusterProvenanceFactory;
  ClusterProvenance(NodeHandle nh, IntKey cluster_members,
                    FloatKey cluster_precision, StringKey cluster_density)
      : ClusterProvenanceConst(nh, cluster_members, cluster_precision,
                               cluster_density) {}

 public:
  void set_members(Int v) {
    try {
      get_node().set_value(cluster_members_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_members(Int v) {
    try {
      get_node().set_frame_value(cluster_members_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_members(Int v) {
    try {
      get_node().set_static_value(cluster_members_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_precision(Float v) {
    try {
      get_node().set_value(cluster_precision_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_precision(Float v) {
    try {
      get_node().set_frame_value(cluster_precision_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_precision(Float v) {
    try {
      get_node().set_static_value(cluster_precision_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_density(String path) {
    try {
      if (path.empty()) {
        get_node().set_value(cluster_density_, path);
      } else {
        String filename = get_node().get_file().get_path();
        String relpath = internal::get_relative_path(filename, path);
        get_node().set_value(cluster_density_, relpath);
      }
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ClusterProvenance"; }
};

/** Create decorators of type ClusterProvenance.
 */
class ClusterProvenanceFactory : public Factory {
  Category cat_;
  IntKey cluster_members_;
  FloatKey cluster_precision_;
  StringKey cluster_density_;

 public:
  ClusterProvenanceFactory(FileConstHandle fh)
      : cat_(fh.get_category("provenance")),
        cluster_members_(fh.get_key<IntTag>(cat_, "cluster members")),
        cluster_precision_(fh.get_key<FloatTag>(cat_, "cluster precision")),
        cluster_density_(fh.get_key<StringTag>(cat_, "cluster density")) {}
  ClusterProvenanceFactory(FileHandle fh)
      : cat_(fh.get_category("provenance")),
        cluster_members_(fh.get_key<IntTag>(cat_, "cluster members")),
        cluster_precision_(fh.get_key<FloatTag>(cat_, "cluster precision")),
        cluster_density_(fh.get_key<StringTag>(cat_, "cluster density")) {}
  /** Get a ClusterProvenanceConst for nh.*/
  ClusterProvenanceConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ClusterProvenance");
    return ClusterProvenanceConst(nh, cluster_members_, cluster_precision_,
                                  cluster_density_);
  }
  /** Get a ClusterProvenance for nh.*/
  ClusterProvenance get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ClusterProvenance");
    return ClusterProvenance(nh, cluster_members_, cluster_precision_,
                             cluster_density_);
  }
  /** Check whether nh has all the attributes required to be a
      ClusterProvenanceConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_value(cluster_members_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_static_value(cluster_members_).get_is_null() &&
           !nh.get_static_value(cluster_density_).get_is_null();
  }
  RMF_SHOWABLE(ClusterProvenanceFactory, "ClusterProvenanceFactory");
};
#ifndef RMF_DOXYGEN
struct ClusterProvenanceConstFactory : public ClusterProvenanceFactory {
  ClusterProvenanceConstFactory(FileConstHandle fh)
      : ClusterProvenanceFactory(fh) {}
  ClusterProvenanceConstFactory(FileHandle fh) : ClusterProvenanceFactory(fh) {}
};
#endif

/** See also ScriptProvenance and ScriptProvenanceFactory.
 */
class ScriptProvenanceConst : public Decorator {
  friend class ScriptProvenanceFactory;

 protected:
  StringKey script_filename_;
  ScriptProvenanceConst(NodeConstHandle nh, StringKey script_filename)
      : Decorator(nh), script_filename_(script_filename) {}

 public:
  String get_filename() const {
    try {
      String relpath = get_node().get_value(script_filename_);
      String filename = get_node().get_file().get_path();
      return internal::get_absolute_path(filename, relpath);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "ScriptProvenanceConst";
  }
  RMF_SHOWABLE(ScriptProvenanceConst, "ScriptProvenance: " << get_node());
};
/** See also ScriptProvenanceFactory.
 */
class ScriptProvenance : public ScriptProvenanceConst {
  friend class ScriptProvenanceFactory;
  ScriptProvenance(NodeHandle nh, StringKey script_filename)
      : ScriptProvenanceConst(nh, script_filename) {}

 public:
  void set_filename(String path) {
    try {
      String filename = get_node().get_file().get_path();
      String relpath = internal::get_relative_path(filename, path);
      get_node().set_value(script_filename_, relpath);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "ScriptProvenance"; }
};

/** Create decorators of type ScriptProvenance.
 */
class ScriptProvenanceFactory : public Factory {
  Category cat_;
  StringKey script_filename_;

 public:
  ScriptProvenanceFactory(FileConstHandle fh)
      : cat_(fh.get_category("provenance")),
        script_filename_(fh.get_key<StringTag>(cat_, "script filename")) {}
  ScriptProvenanceFactory(FileHandle fh)
      : cat_(fh.get_category("provenance")),
        script_filename_(fh.get_key<StringTag>(cat_, "script filename")) {}
  /** Get a ScriptProvenanceConst for nh.*/
  ScriptProvenanceConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ScriptProvenance");
    return ScriptProvenanceConst(nh, script_filename_);
  }
  /** Get a ScriptProvenance for nh.*/
  ScriptProvenance get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  ScriptProvenance");
    return ScriptProvenance(nh, script_filename_);
  }
  /** Check whether nh has all the attributes required to be a
      ScriptProvenanceConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_value(script_filename_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_static_value(script_filename_).get_is_null();
  }
  RMF_SHOWABLE(ScriptProvenanceFactory, "ScriptProvenanceFactory");
};
#ifndef RMF_DOXYGEN
struct ScriptProvenanceConstFactory : public ScriptProvenanceFactory {
  ScriptProvenanceConstFactory(FileConstHandle fh)
      : ScriptProvenanceFactory(fh) {}
  ScriptProvenanceConstFactory(FileHandle fh) : ScriptProvenanceFactory(fh) {}
};
#endif

/** See also SoftwareProvenance and SoftwareProvenanceFactory.
 */
class SoftwareProvenanceConst : public Decorator {
  friend class SoftwareProvenanceFactory;

 protected:
  StringKey software_name_;
  StringKey software_version_;
  StringKey software_location_;
  SoftwareProvenanceConst(NodeConstHandle nh, StringKey software_name,
                          StringKey software_version,
                          StringKey software_location)
      : Decorator(nh),
        software_name_(software_name),
        software_version_(software_version),
        software_location_(software_location) {}

 public:
  String get_name() const {
    try {
      return get_node().get_value(software_name_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_name() const {
    try {
      return get_node().get_frame_value(software_name_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_name() const {
    try {
      return get_node().get_static_value(software_name_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_version() const {
    try {
      return get_node().get_value(software_version_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_version() const {
    try {
      return get_node().get_frame_value(software_version_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_version() const {
    try {
      return get_node().get_static_value(software_version_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_location() const {
    try {
      return get_node().get_value(software_location_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_location() const {
    try {
      return get_node().get_frame_value(software_location_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_location() const {
    try {
      return get_node().get_static_value(software_location_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() {
    return "SoftwareProvenanceConst";
  }
  RMF_SHOWABLE(SoftwareProvenanceConst, "SoftwareProvenance: " << get_node());
};
/** See also SoftwareProvenanceFactory.
 */
class SoftwareProvenance : public SoftwareProvenanceConst {
  friend class SoftwareProvenanceFactory;
  SoftwareProvenance(NodeHandle nh, StringKey software_name,
                     StringKey software_version, StringKey software_location)
      : SoftwareProvenanceConst(nh, software_name, software_version,
                                software_location) {}

 public:
  void set_name(String v) {
    try {
      get_node().set_value(software_name_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_name(String v) {
    try {
      get_node().set_frame_value(software_name_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_name(String v) {
    try {
      get_node().set_static_value(software_name_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_version(String v) {
    try {
      get_node().set_value(software_version_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_version(String v) {
    try {
      get_node().set_frame_value(software_version_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_version(String v) {
    try {
      get_node().set_static_value(software_version_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_location(String v) {
    try {
      get_node().set_value(software_location_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_location(String v) {
    try {
      get_node().set_frame_value(software_location_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_location(String v) {
    try {
      get_node().set_static_value(software_location_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "SoftwareProvenance"; }
};

/** Create decorators of type SoftwareProvenance.
 */
class SoftwareProvenanceFactory : public Factory {
  Category cat_;
  StringKey software_name_;
  StringKey software_version_;
  StringKey software_location_;

 public:
  SoftwareProvenanceFactory(FileConstHandle fh)
      : cat_(fh.get_category("provenance")),
        software_name_(fh.get_key<StringTag>(cat_, "software name")),
        software_version_(fh.get_key<StringTag>(cat_, "software version")),
        software_location_(fh.get_key<StringTag>(cat_, "software location")) {}
  SoftwareProvenanceFactory(FileHandle fh)
      : cat_(fh.get_category("provenance")),
        software_name_(fh.get_key<StringTag>(cat_, "software name")),
        software_version_(fh.get_key<StringTag>(cat_, "software version")),
        software_location_(fh.get_key<StringTag>(cat_, "software location")) {}
  /** Get a SoftwareProvenanceConst for nh.*/
  SoftwareProvenanceConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  SoftwareProvenance");
    return SoftwareProvenanceConst(nh, software_name_, software_version_,
                                   software_location_);
  }
  /** Get a SoftwareProvenance for nh.*/
  SoftwareProvenance get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::PROVENANCE),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  SoftwareProvenance");
    return SoftwareProvenance(nh, software_name_, software_version_,
                              software_location_);
  }
  /** Check whether nh has all the attributes required to be a
      SoftwareProvenanceConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_value(software_name_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::PROVENANCE) &&
           !nh.get_static_value(software_name_).get_is_null() &&
           !nh.get_static_value(software_version_).get_is_null() &&
           !nh.get_static_value(software_location_).get_is_null();
  }
  RMF_SHOWABLE(SoftwareProvenanceFactory, "SoftwareProvenanceFactory");
};
#ifndef RMF_DOXYGEN
struct SoftwareProvenanceConstFactory : public SoftwareProvenanceFactory {
  SoftwareProvenanceConstFactory(FileConstHandle fh)
      : SoftwareProvenanceFactory(fh) {}
  SoftwareProvenanceConstFactory(FileHandle fh)
      : SoftwareProvenanceFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_PROVENANCE_DECORATORS_H */
