// -*- Mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*-
// Copyright 2009 Google Inc. All Rights Reserved.
// Author: fikes@google.com (Andrew Fikes)
//
// Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE file.

#include "config_for_unittests.h"
#include "page_heap.h"
#include "system-alloc.h"
#include <stdio.h>
#include "common.h"

#include "gtest/gtest.h"

DECLARE_int64(tcmalloc_heap_limit_mb);

namespace {

// The system will only release memory if the block size is equal or hight than
// system page size.
static bool HaveSystemRelease =
    TCMalloc_SystemRelease(
      TCMalloc_SystemAlloc(getpagesize(), nullptr, 0), getpagesize());

static void CheckStats(const tcmalloc::PageHeap* ph,
                       uint64_t system_pages,
                       uint64_t free_pages,
                       uint64_t unmapped_pages) {
  tcmalloc::PageHeap::Stats stats = ph->stats();

  if (!HaveSystemRelease) {
    free_pages += unmapped_pages;
    unmapped_pages = 0;
  }

  EXPECT_EQ(system_pages, stats.system_bytes >> kPageShift);
  EXPECT_EQ(free_pages, stats.free_bytes >> kPageShift);
  EXPECT_EQ(unmapped_pages, stats.unmapped_bytes >> kPageShift);
}

TEST(PageHeapUnitTest, PageHeapStats) {
  tcmalloc::PageHeap* ph = new tcmalloc::PageHeap();

  // Empty page heap
  CheckStats(ph, 0, 0, 0);

  // Allocate a span 's1'
  tcmalloc::Span* s1 = ph->New(256);
  CheckStats(ph, 256, 0, 0);

  // Split span 's1' into 's1', 's2'.  Delete 's2'
  tcmalloc::Span* s2 = ph->Split(s1, 128);
  ph->Delete(s2);
  CheckStats(ph, 256, 128, 0);

  // Unmap deleted span 's2'
  ph->ReleaseAtLeastNPages(1);
  CheckStats(ph, 256, 0, 128);

  // Delete span 's1'
  ph->Delete(s1);
  CheckStats(ph, 256, 128, 128);

  FLAGS_tcmalloc_heap_limit_mb = 0;
  delete ph;
}

TEST(PageHeapUnitTest, PageHeapLimit) {
  tcmalloc::PageHeap* ph = new tcmalloc::PageHeap();

  ASSERT_EQ(kMaxPages, 1 << (20 - kPageShift));

  // We do not know much is taken from the system for other purposes,
  // so we detect the proper limit:
  {
    FLAGS_tcmalloc_heap_limit_mb = 1;
    tcmalloc::Span* s = nullptr;
    while((s = ph->New(kMaxPages)) == nullptr) {
      FLAGS_tcmalloc_heap_limit_mb++;
    }
    FLAGS_tcmalloc_heap_limit_mb += 9;
    ph->Delete(s);
    // We are [10, 11) mb from the limit now.
  }

  // Test AllocLarge and GrowHeap first:
  {
    tcmalloc::Span * spans[10];
    for (int i=0; i<10; ++i) {
      spans[i] = ph->New(kMaxPages);
      ASSERT_NE(spans[i], nullptr);
    }
    ASSERT_EQ(ph->New(kMaxPages), nullptr);

    for (int i=0; i<10; i += 2) {
      ph->Delete(spans[i]);
    }

    tcmalloc::Span *defragmented = ph->New(5 * kMaxPages);

    if (HaveSystemRelease) {
      // EnsureLimit should release deleted normal spans
      ASSERT_NE(defragmented, nullptr);
      ASSERT_TRUE(ph->CheckExpensive());
      ph->Delete(defragmented);
    }
    else
    {
      ASSERT_EQ(defragmented, nullptr);
      ASSERT_TRUE(ph->CheckExpensive());
    }

    for (int i=1; i<10; i += 2) {
      ph->Delete(spans[i]);
    }
  }

  // Once again, testing small lists this time (twice smaller spans):
  {
    tcmalloc::Span * spans[20];
    for (int i=0; i<20; ++i) {
      spans[i] = ph->New(kMaxPages >> 1);
      ASSERT_NE(spans[i], nullptr);
    }
    // one more half size allocation may be possible:
    tcmalloc::Span * lastHalf = ph->New(kMaxPages >> 1);
    ASSERT_EQ(ph->New(kMaxPages >> 1), nullptr);

    for (int i=0; i<20; i += 2) {
      ph->Delete(spans[i]);
    }

    for(Length len = kMaxPages >> 2; len < 5 * kMaxPages; len = len << 1)
    {
      if(len <= kMaxPages >> 1 || HaveSystemRelease) {
        tcmalloc::Span *s = ph->New(len);
        ASSERT_NE(s, nullptr);
        ph->Delete(s);
      }
    }

    ASSERT_TRUE(ph->CheckExpensive());

    for (int i=1; i<20; i += 2) {
      ph->Delete(spans[i]);
    }

    if (lastHalf != nullptr) {
      ph->Delete(lastHalf);
    }
  }

  FLAGS_tcmalloc_heap_limit_mb = 0;
  delete ph;
}

}  // namespace