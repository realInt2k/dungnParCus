//===-- aibar.h -------------------------------------------------*- C++ -*-===//
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

#ifndef AIBAR_H
#define AIBAR_H

#include "../sanitizer_common/sanitizer_internal_defs.h"
#include "aibar_platform.h"

using __sanitizer::uptr;
using __sanitizer::u16;

// Copy declarations from public sanitizer/aibar_interface.h header here.
#include "defs.h"
/*
extern "C" {
void aibar_add_label(aibar_label label, void *addr, uptr size);
void aibar_set_label(aibar_label label, void *addr, uptr size);
aibar_label aibar_read_label(const void *addr, uptr size);
const aibar_label * aibar_shadow_for(const void * addr);
aibar_label aibar_union(aibar_label l1, aibar_label l2);
}  // extern "C"

template <typename T>
void aibar_set_label(aibar_label label, T &data) {  // NOLINT
  aibar_set_label(label, (void *)&data, sizeof(T));
}

namespace __aibar {

void InitializeInterceptors();

inline aibar_label *shadow_for(void *ptr) {
  return (aibar_label *) ((((uptr) ptr) & ShadowMask()) << 2);
}

inline const aibar_label *shadow_for(const void *ptr) {
  return shadow_for(const_cast<void *>(ptr));
}

struct Flags {
#define AIBAR_FLAG(Type, Name, DefaultValue, Description) Type Name;
#include "aibar_flags.inc"
#undef AIBAR_FLAG

  void SetDefaults();
};

extern Flags flags_data;
inline Flags &flags() {
  return flags_data;
}

}  // namespace __aibar
*/
#endif  // AIBAR_H
