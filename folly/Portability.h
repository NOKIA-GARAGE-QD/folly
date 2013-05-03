/*
 * Copyright 2013 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FOLLY_PORTABILITY_H_
#define FOLLY_PORTABILITY_H_

#include "folly-config.h"

#ifdef FOLLY_HAVE_SCHED_H
 #include <sched.h>
 #ifndef FOLLY_HAVE_PTHREAD_YIELD
  #define pthread_yield sched_yield
 #endif
#endif


// MaxAlign: max_align_t isn't supported by gcc
#ifdef __GNUC__
struct MaxAlign { char c; } __attribute__((aligned));
#else /* !__GNUC__ */
# error Cannot define MaxAlign on this platform
#endif

#if defined(__clang__) || defined(__GNUC__)
# define FOLLY_NORETURN __attribute__((noreturn))
#else
# define FOLLY_NORETURN
#endif

#endif // FOLLY_PORTABILITY_H_
