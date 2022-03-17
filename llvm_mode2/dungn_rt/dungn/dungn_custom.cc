//===-- dungn.cc ----------------------------------------------------------===//
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
// This file defines the custom functions listed in done_abilist.txt.
//===----------------------------------------------------------------------===//

#include "../sanitizer_common/sanitizer_common.h"
#include "../sanitizer_common/sanitizer_internal_defs.h"
#include "../sanitizer_common/sanitizer_linux.h"

#include "dungn.h"

#include <arpa/inet.h>
#include <assert.h>
#include <ctype.h>
#include <dlfcn.h>
#include <link.h>
#include <poll.h>
#include <pthread.h>
#include <pwd.h>
#include <sched.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

using namespace __dungn;

#define CALL_WEAK_INTERCEPTOR_HOOK(f, ...) \
  do {                                     \
    if (f) f(__VA_ARGS__);                 \
  } while (false)
#define DECLARE_WEAK_INTERCEPTOR_HOOK(f, ...) \
  SANITIZER_INTERFACE_ATTRIBUTE SANITIZER_WEAK_ATTRIBUTE void f(__VA_ARGS__);

/*
SANITIZER_INTERFACE_ATTRIBUTE int
__dfsw_stat(const char *path, struct stat *buf, dungn_label path_label,
            dungn_label buf_label, dungn_label *ret_label) {
  int ret = stat(path, buf);
  if (ret == 0)
    dungn_set_label(0, buf, sizeof(struct stat));
  *ret_label = 0;
  return ret;
}

SANITIZER_INTERFACE_ATTRIBUTE int __dfsw_fstat(int fd, struct stat *buf,
                                               dungn_label fd_label,
                                               dungn_label buf_label,
                                               dungn_label *ret_label) {
  int ret = fstat(fd, buf);
  if (ret == 0)
    dungn_set_label(0, buf, sizeof(struct stat));
  *ret_label = 0;
  return ret;
}
*/

