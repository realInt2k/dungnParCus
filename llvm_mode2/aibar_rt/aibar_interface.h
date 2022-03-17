//===-- aibar_interface.h -------------------------------------------------===//
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
// Public interface header.
//===----------------------------------------------------------------------===//
#ifndef AIBAR_INTERFACE_H
#define AIBAR_INTERFACE_H

#include <stddef.h>
#include <stdint.h>
#include "./common_interface_defs.h"
#include "./defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Stores information associated with a specific label identifier.  A label
/// may be a base label created using aibar_create_label, with associated
/// text description and user data, or an automatically created union label,
/// which represents the union of two label identifiers (which may themselves
/// be base or union labels).
  /*
struct aibar_label_info {
  // Fields for union labels, set to 0 for base labels.
  aibar_label l1;
  aibar_label l2;

  // Fields for base labels.
  const char *desc;
  void *userdata;
};
  */

/// Signature of the callback argument to aibar_set_write_callback().
typedef void (*aibar_write_callback_t)(int fd, const void *buf, size_t count);

/// Computes the union of \c l1 and \c l2, possibly creating a union label in
/// the process.
aibar_label aibar_union(aibar_label l1, aibar_label l2);

/// Creates and returns a base label with the given description and user data.
aibar_label aibar_create_label(int pos);
  
/// Sets the label for each address in [addr,addr+size) to \c label.
void aibar_set_label(aibar_label label, void *addr, size_t size);

/// Sets the label for each address in [addr,addr+size) to the union of the
/// current label for that address and \c label.
void aibar_add_label(aibar_label label, void *addr, size_t size);

/// Retrieves the label associated with the given data.
///
/// The type of 'data' is arbitrary.  The function accepts a value of any type,
/// which can be truncated or extended (implicitly or explicitly) as necessary.
/// The truncation/extension operations will preserve the label of the original
/// value.
aibar_label aibar_get_label(long data);

/// Retrieves the label associated with the data at the given address.
aibar_label aibar_read_label(const void *addr, size_t size);

/// Retrieves the starting address for the shadow memory of the given address
const aibar_label * aibar_shadow_for(const void * addr);

/// Retrieves a pointer to the aibar_label_info struct for the given label.
// const struct aibar_label_info *aibar_get_label_info(aibar_label label);

/// Returns whether the given label label contains the label elem.
// int aibar_has_label(aibar_label label, aibar_label elem);

/// If the given label label contains a label with the description desc, returns
/// that label, else returns 0.
// aibar_label aibar_has_label_with_desc(aibar_label label, const char *desc);

/// Returns the number of labels allocated.
//size_t aibar_get_label_count(void);

/// Sets a callback to be invoked on calls to write().  The callback is invoked
/// before the write is done.  The write is not guaranteed to succeed when the
/// callback executes.  Pass in NULL to remove any callback.
void aibar_set_write_callback(aibar_write_callback_t labeled_write_callback);

/// Writes the labels currently used by the program to the given file
/// descriptor. The lines of the output have the following format:
///
/// <label> <parent label 1> <parent label 2> <label description if any>
//void aibar_dump_labels(int fd);

/// Interceptor hooks.
/// Whenever a aibar's custom function is called the corresponding
/// hook is called it non-zero. The hooks should be defined by the user.
/// The primary use case is taint-guided fuzzing, where the fuzzer
/// needs to see the parameters of the function and the labels.
/// FIXME: implement more hooks.
void aibar_weak_hook_memcmp(void *caller_pc, const void *s1, const void *s2,
                            size_t n, aibar_label s1_label,
                            aibar_label s2_label, aibar_label n_label);
void aibar_weak_hook_strncmp(void *caller_pc, const char *s1, const char *s2,
                             size_t n, aibar_label s1_label,
                             aibar_label s2_label, aibar_label n_label);
#ifdef __cplusplus
}  // extern "C"

template <typename T>
void aibar_set_label(aibar_label label, T &data) {  // NOLINT
  aibar_set_label(label, (void *)&data, sizeof(T));
}
#include <vector>
const std::vector<tag_seg> aibar_get_label_offsets(aibar_label l);

#endif

#endif  // AIBAR_INTERFACE_H
