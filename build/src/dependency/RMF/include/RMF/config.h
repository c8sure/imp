/*
 * \file RMF/RMF_config.h
 * \brief Configuration and utility macros
 *        Provide version information, plus macros to mark functions and
 *        classes as exported from a DLL/.so and to set up namespaces.
 *
 * Copyright 2007-2022 IMP Inventors. All rights reserved.
 *
 */

#ifndef RMF_CONFIG_H
#define RMF_CONFIG_H

/* Protect against RMFEXPORT being defined already */
#ifdef RMFEXPORT
#undef RMFEXPORT
#endif

#ifdef _MSC_VER

#ifdef RMF_EXPORTS
#define RMFEXPORT __declspec(dllexport)
#else // EXPORTS
#define RMFEXPORT __declspec(dllimport)
#endif // EXPORTS

#else // _MSC_VER

#define RMFEXPORT

#endif // _MSC_VER

// Version number
#define RMF_VERSION_MAJOR 1
#define RMF_VERSION_MINOR 7
#define RMF_VERSION_MICRO 0
#define RMF_VERSION 100700

#define RMF_HAS_LOG4CXX 0
#define RMF_HAS_NUMPY 1

#define RMF_HAS_DEPRECATED_BACKENDS 1

#ifdef _MSC_VER
#pragma warning(disable: 4003)
#endif

#include "RMF/compiler_macros.h" // IWYU pragma: export

#endif  /* RMF_CONFIG_H */
