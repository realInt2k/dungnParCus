//===-- aibar_flags.inc -----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Dungn runtime flags.
//
//===----------------------------------------------------------------------===//
#ifndef AIBAR_FLAG
# error "Define AIBAR_FLAG prior to including this file!"
#endif

// AIBAR_FLAG(Type, Name, DefaultValue, Description)
// See COMMON_FLAG in sanitizer_flags.inc for more details.

AIBAR_FLAG(bool, warn_unimplemented, true,
           "Whether to warn on unimplemented functions.")
AIBAR_FLAG(bool, warn_nonzero_labels, false,
           "Whether to warn on unimplemented functions.")
AIBAR_FLAG(
    bool, strict_data_dependencies, true,
    "Whether to propagate labels only when there is an obvious data dependency"
    "(e.g., when comparing strings, ignore the fact that the output of the"
    "comparison might be data-dependent on the content of the strings). This"
    "applies only to the custom functions defined in 'custom.c'.")
AIBAR_FLAG(const char *, dump_labels_at_exit, "", "The path of the file where "
                                                  "to dump the labels when the "
                                                  "program terminates.")
