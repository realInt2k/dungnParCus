//===-- dungn.h -------------------------------------------------*- C++ -*-===//
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
// Private Dungn header.
//===----------------------------------------------------------------------===//

#ifndef DUNGN_H
#define DUNGN_H

#include "../sanitizer_common/sanitizer_internal_defs.h"
#include "dungn_platform.h"

using __sanitizer::uptr;
using __sanitizer::u16;

// Copy declarations from public sanitizer/dungn_interface.h header here.
#include "defs.h"
/*
extern "C" {
void dungn_add_label(dungn_label label, void *addr, uptr size);
void dungn_set_label(dungn_label label, void *addr, uptr size);
dungn_label dungn_read_label(const void *addr, uptr size);
const dungn_label * dungn_shadow_for(const void * addr);
dungn_label dungn_union(dungn_label l1, dungn_label l2);
}  // extern "C"

template <typename T>
void dungn_set_label(dungn_label label, T &data) {  // NOLINT
  dungn_set_label(label, (void *)&data, sizeof(T));
}

namespace __dungn {

void InitializeInterceptors();

inline dungn_label *shadow_for(void *ptr) {
  return (dungn_label *) ((((uptr) ptr) & ShadowMask()) << 2);
}

inline const dungn_label *shadow_for(const void *ptr) {
  return shadow_for(const_cast<void *>(ptr));
}

struct Flags {
#define DUNGN_FLAG(Type, Name, DefaultValue, Description) Type Name;
#include "dungn_flags.inc"
#undef DUNGN_FLAG

  void SetDefaults();
};

extern Flags flags_data;
inline Flags &flags() {
  return flags_data;
}

}  // namespace __dungn
*/
#endif  // DUNGN_H
