//===-- dungn_interceptors.cc ---------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a part of DataFlowSanitizer.
//
// Interceptors for standard library functions.
//===----------------------------------------------------------------------===//

#include "dungn.h"
#include "../interception/interception.h"
#include "../sanitizer_common/sanitizer_common.h"

using namespace __sanitizer;

