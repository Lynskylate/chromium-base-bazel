// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/debug/elf_reader_linux.h"

#include <dlfcn.h>

#include "base/files/memory_mapped_file.h"
#include "base/path_service.h"
#include "base/strings/string_util.h"
#include "build/build_config.h"
#include "gtest/gtest.h"

extern char __executable_start;

namespace base {
namespace debug {

// The linker flag --build-id is passed only on official builds. Clang does not
// enable it by default and we do not have build id section in non-official
// builds.
#if defined(OFFICIAL_BUILD)
TEST(ElfReaderTest, ReadElfBuildId) {
  Optional<std::string> build_id = ReadElfBuildId(&__executable_start);
  ASSERT_TRUE(build_id);
  const size_t kGuidBytes = 20;
  EXPECT_EQ(2 * kGuidBytes, build_id.value().size());
  for (char c : *build_id) {
    EXPECT_TRUE(IsHexDigit(c));
    EXPECT_FALSE(IsAsciiLower(c));
  }
}
#endif

TEST(ElfReaderTest, ReadElfLibraryName) {
#if defined(OS_ANDROID)
  // On Android the library loader memory maps the full so file.
  const char kLibraryName[] = "lib_base_unittests__library";
  const void* addr = &__executable_start;
#else

  // On Linux the executable does not contain soname and is not mapped till
  // dynamic segment. So, use malloc wrapper so file on which the test already
  // depends on.
  // Hack to work under the bazel sandbox
  base::FilePath exe_path;
  CHECK(base::PathService::Get(base::DIR_EXE, &exe_path));
  std::string libraryPath = exe_path.AppendASCII("test/")
          .AppendASCII(MALLOC_WRAPPER_LIB).MaybeAsASCII();

  // Find any symbol in the loaded file.
  void* handle = dlopen(libraryPath.c_str(), RTLD_NOW | RTLD_LOCAL);

  const void* init_addr = dlsym(handle, "_init");
  // Use this symbol to get full path to the loaded library.
  Dl_info info;
  int res = dladdr(init_addr, &info);
  ASSERT_NE(0, res);
  std::string filename(info.dli_fname);
  EXPECT_FALSE(filename.empty());
  EXPECT_NE(std::string::npos, filename.find(MALLOC_WRAPPER_LIB));

  // Memory map the so file and use it to test reading so name.
  MemoryMappedFile file;
  ASSERT_TRUE(file.Initialize(FilePath(filename)));
  const void* addr = file.data();
#endif

  auto name = ReadElfLibraryName(addr);
  ASSERT_TRUE(name);
  EXPECT_NE(std::string::npos, name->find(MALLOC_WRAPPER_LIB))
      << "Library name " << *name << " doesn't contain expected "
      << MALLOC_WRAPPER_LIB;
}

}  // namespace debug
}  // namespace base
