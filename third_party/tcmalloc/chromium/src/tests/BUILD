load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "test_util",
    testonly = True,
    srcs = [
        "testutil.cc",
        "testutil.h",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [
        "//third_party/googletest:gtest_main",
        "//third_party/tcmalloc",
    ],
)

cc_test(
    name = "addressmap_unittest",
    srcs = [
        "addressmap_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "atomicops_unittest",
    srcs = [
        "atomicops_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "current_allocated_bytes_test",
    srcs = [
        "current_allocated_bytes_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "frag_unittest",
    srcs = [
        "frag_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "getpc_test",
    srcs = [
        "getpc_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

# TODO heap-profiler_unittest.cc (complex support)

cc_test(
    name = "large_heap_fragmentation_unittest",
    srcs = [
        "large_heap_fragmentation_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "low_level_alloc_unittest",
    srcs = [
        "low_level_alloc_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

# TODO keep going with migrating tests

cc_test(
    name = "malloc_extension_test",
    srcs = [
        "malloc_extension_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "malloc_hook_test",
    srcs = [
        "malloc_hook_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

# TODO continue with unit tests

#cc_test(
#    name = "markidle_unittest",
#    srcs = [
#        "markidle_unittest.cc",
#    ],
#    copts = CXXOPTS,
#    licenses = ["permissive"],
#    deps = [":test_util"],
#)
