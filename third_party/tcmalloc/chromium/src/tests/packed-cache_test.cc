// -*- Mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*-
// Copyright (c) 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// ---
// Author: Geoff Pike

#include <stdio.h>
#include "packed-cache-inl.h"

#include "gtest/gtest.h"

static const int kHashbits = PackedCache<20>::kHashbits;

template <int kKeybits>
static void MustGet(const PackedCache<kKeybits>& cache, uintptr_t key, uint32 *rv) {
  ASSERT_TRUE(cache.TryGet(key, rv));
}

template <int kKeybits>
static size_t Has(const PackedCache<kKeybits>& cache, uintptr_t key) {
  uint32 dummy;
  return cache.TryGet(key, &dummy);
}

// A basic sanity test.
TEST(PackedCacheUnitTest, PackedCache) {
  uint32 rv;
  PackedCache<20> cache;

  ASSERT_FALSE(Has(cache, 0));
  cache.Put(0, 17);
  ASSERT_TRUE(Has(cache, 0));

  ASSERT_NO_FATAL_FAILURE(MustGet(cache, 0, &rv));
  ASSERT_EQ(rv, 17);

  cache.Put(19, 99);

  ASSERT_NO_FATAL_FAILURE(MustGet(cache, 0, &rv));
  ASSERT_EQ(rv, 17);
  ASSERT_NO_FATAL_FAILURE(MustGet(cache, 19, &rv));
  ASSERT_EQ(rv, 99);

  // Knock <0, 17> out by using a conflicting key.
  cache.Put(1 << kHashbits, 22);
  ASSERT_FALSE(Has(cache, 0));
  ASSERT_NO_FATAL_FAILURE(MustGet(cache, 1 << kHashbits, &rv));
  ASSERT_EQ(rv, 22);

  cache.Invalidate(19);
  ASSERT_FALSE(Has(cache, 19));
  ASSERT_FALSE(Has(cache, 0));
  ASSERT_TRUE(Has(cache, 1 << kHashbits));
}
