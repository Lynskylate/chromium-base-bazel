// -*- Mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*-
// Copyright 2009 Google Inc. All Rights Reserved.
// Author: sanjay@google.com (Sanjay Ghemawat)
//
// Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE file.

#include "raw_printer.h"
#include <stdio.h>
#include <string>

#include "gtest/gtest.h"

using std::string;

TEST(RawPrinterUnitTest, Empty) {
  char buffer[1];
  base::RawPrinter printer(buffer, arraysize(buffer));
  ASSERT_EQ(0, printer.length());
  ASSERT_EQ(string(""), buffer);
  ASSERT_EQ(0, printer.space_left());
  printer.Printf("foo");
  ASSERT_EQ(string(""), string(buffer));
  ASSERT_EQ(0, printer.length());
  ASSERT_EQ(0, printer.space_left());
}

TEST(RawPrinterUnitTest, PartiallyFilled) {
  char buffer[100];
  base::RawPrinter printer(buffer, arraysize(buffer));
  printer.Printf("%s %s", "hello", "world");
  ASSERT_EQ(string("hello world"), string(buffer));
  ASSERT_EQ(11, printer.length());
  ASSERT_LT(0, printer.space_left());
}

TEST(RawPrinterUnitTest, Truncated) {
  char buffer[3];
  base::RawPrinter printer(buffer, arraysize(buffer));
  printer.Printf("%d", 12345678);
  ASSERT_EQ(string("12"), string(buffer));
  ASSERT_EQ(2, printer.length());
  ASSERT_EQ(0, printer.space_left());
}

TEST(RawPrinterUnitTest, ExactlyFilled) {
  char buffer[12];
  base::RawPrinter printer(buffer, arraysize(buffer));
  printer.Printf("%s %s", "hello", "world");
  ASSERT_EQ(string("hello world"), string(buffer));
  ASSERT_EQ(11, printer.length());
  ASSERT_EQ(0, printer.space_left());
}
