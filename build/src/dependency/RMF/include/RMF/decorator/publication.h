/**
 *  \file RMF/decorator/publication.h
 *  \brief Helper functions for manipulating RMF files.
 *
 *  Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_PUBLICATION_DECORATORS_H
#define RMF_PUBLICATION_DECORATORS_H

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

/** See also JournalArticle and JournalArticleFactory.
 */
class JournalArticleConst : public Decorator {
  friend class JournalArticleFactory;

 protected:
  StringKey title_;
  StringKey journal_;
  StringKey pubmed_id_;
  IntKey year_;
  StringsKey authors_;
  JournalArticleConst(NodeConstHandle nh, StringKey title, StringKey journal,
                      StringKey pubmed_id, IntKey year, StringsKey authors)
      : Decorator(nh),
        title_(title),
        journal_(journal),
        pubmed_id_(pubmed_id),
        year_(year),
        authors_(authors) {}

 public:
  String get_title() const {
    try {
      return get_node().get_value(title_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_title() const {
    try {
      return get_node().get_frame_value(title_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_title() const {
    try {
      return get_node().get_static_value(title_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_journal() const {
    try {
      return get_node().get_value(journal_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_journal() const {
    try {
      return get_node().get_frame_value(journal_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_journal() const {
    try {
      return get_node().get_static_value(journal_);
    }
    RMF_DECORATOR_CATCH();
  }

  String get_pubmed_id() const {
    try {
      return get_node().get_value(pubmed_id_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_frame_pubmed_id() const {
    try {
      return get_node().get_frame_value(pubmed_id_);
    }
    RMF_DECORATOR_CATCH();
  }
  String get_static_pubmed_id() const {
    try {
      return get_node().get_static_value(pubmed_id_);
    }
    RMF_DECORATOR_CATCH();
  }

  Int get_year() const {
    try {
      return get_node().get_value(year_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_frame_year() const {
    try {
      return get_node().get_frame_value(year_);
    }
    RMF_DECORATOR_CATCH();
  }
  Int get_static_year() const {
    try {
      return get_node().get_static_value(year_);
    }
    RMF_DECORATOR_CATCH();
  }

  Strings get_authors() const {
    try {
      return get_node().get_value(authors_);
    }
    RMF_DECORATOR_CATCH();
  }
  Strings get_frame_authors() const {
    try {
      return get_node().get_frame_value(authors_);
    }
    RMF_DECORATOR_CATCH();
  }
  Strings get_static_authors() const {
    try {
      return get_node().get_static_value(authors_);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "JournalArticleConst"; }
  RMF_SHOWABLE(JournalArticleConst, "JournalArticle: " << get_node());
};
/** See also JournalArticleFactory.
 */
class JournalArticle : public JournalArticleConst {
  friend class JournalArticleFactory;
  JournalArticle(NodeHandle nh, StringKey title, StringKey journal,
                 StringKey pubmed_id, IntKey year, StringsKey authors)
      : JournalArticleConst(nh, title, journal, pubmed_id, year, authors) {}

 public:
  void set_title(String v) {
    try {
      get_node().set_value(title_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_title(String v) {
    try {
      get_node().set_frame_value(title_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_title(String v) {
    try {
      get_node().set_static_value(title_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_journal(String v) {
    try {
      get_node().set_value(journal_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_journal(String v) {
    try {
      get_node().set_frame_value(journal_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_journal(String v) {
    try {
      get_node().set_static_value(journal_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_pubmed_id(String v) {
    try {
      get_node().set_value(pubmed_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_pubmed_id(String v) {
    try {
      get_node().set_frame_value(pubmed_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_pubmed_id(String v) {
    try {
      get_node().set_static_value(pubmed_id_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_year(Int v) {
    try {
      get_node().set_value(year_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_year(Int v) {
    try {
      get_node().set_frame_value(year_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_year(Int v) {
    try {
      get_node().set_static_value(year_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  void set_authors(Strings v) {
    try {
      get_node().set_value(authors_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_frame_authors(Strings v) {
    try {
      get_node().set_frame_value(authors_, v);
    }
    RMF_DECORATOR_CATCH();
  }
  void set_static_authors(Strings v) {
    try {
      get_node().set_static_value(authors_, v);
    }
    RMF_DECORATOR_CATCH();
  }

  static std::string get_decorator_type_name() { return "JournalArticle"; }
};

/** Create decorators of type JournalArticle.
 */
class JournalArticleFactory : public Factory {
  Category cat_;
  StringKey title_;
  StringKey journal_;
  StringKey pubmed_id_;
  IntKey year_;
  StringsKey authors_;

 public:
  JournalArticleFactory(FileConstHandle fh)
      : cat_(fh.get_category("publication")),
        title_(fh.get_key<StringTag>(cat_, "title")),
        journal_(fh.get_key<StringTag>(cat_, "journal")),
        pubmed_id_(fh.get_key<StringTag>(cat_, "pubmed id")),
        year_(fh.get_key<IntTag>(cat_, "year")),
        authors_(fh.get_key<StringsTag>(cat_, "authors")) {}
  JournalArticleFactory(FileHandle fh)
      : cat_(fh.get_category("publication")),
        title_(fh.get_key<StringTag>(cat_, "title")),
        journal_(fh.get_key<StringTag>(cat_, "journal")),
        pubmed_id_(fh.get_key<StringTag>(cat_, "pubmed id")),
        year_(fh.get_key<IntTag>(cat_, "year")),
        authors_(fh.get_key<StringsTag>(cat_, "authors")) {}
  /** Get a JournalArticleConst for nh.*/
  JournalArticleConst get(NodeConstHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::ORGANIZATIONAL),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  JournalArticle");
    return JournalArticleConst(nh, title_, journal_, pubmed_id_, year_,
                               authors_);
  }
  /** Get a JournalArticle for nh.*/
  JournalArticle get(NodeHandle nh) const {
    RMF_USAGE_CHECK((nh.get_type() == RMF::ORGANIZATIONAL),
                    std::string("Bad node type. Got \"") +
                        boost::lexical_cast<std::string>(nh.get_type()) +
                        "\" in decorator type  JournalArticle");
    return JournalArticle(nh, title_, journal_, pubmed_id_, year_, authors_);
  }
  /** Check whether nh has all the attributes required to be a
      JournalArticleConst.*/
  bool get_is(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::ORGANIZATIONAL) &&
           !nh.get_value(title_).get_is_null();
  }
  bool get_is_static(NodeConstHandle nh) const {
    return (nh.get_type() == RMF::ORGANIZATIONAL) &&
           !nh.get_static_value(title_).get_is_null() &&
           !nh.get_static_value(journal_).get_is_null() &&
           !nh.get_static_value(pubmed_id_).get_is_null() &&
           !nh.get_static_value(year_).get_is_null() &&
           !nh.get_static_value(authors_).get_is_null();
  }
  RMF_SHOWABLE(JournalArticleFactory, "JournalArticleFactory");
};
#ifndef RMF_DOXYGEN
struct JournalArticleConstFactory : public JournalArticleFactory {
  JournalArticleConstFactory(FileConstHandle fh) : JournalArticleFactory(fh) {}
  JournalArticleConstFactory(FileHandle fh) : JournalArticleFactory(fh) {}
};
#endif

} /* namespace decorator */
} /* namespace RMF */
RMF_DISABLE_WARNINGS

#endif /* RMF_PUBLICATION_DECORATORS_H */
