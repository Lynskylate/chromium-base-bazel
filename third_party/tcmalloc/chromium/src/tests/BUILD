package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

# Skipping the heap checker, debug allocator, and some of the profiler tests
# Along with the tcmalloc super unit test (due to exception usage)

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
    name = "addressmap_unit_test",
    srcs = [
        "addressmap_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "atomicops_unit_test",
    srcs = [
        "atomicops_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "current_allocated_bytes_unit_test",
    srcs = [
        "current_allocated_bytes_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "large_heap_fragmentation_unit_test",
    srcs = [
        "large_heap_fragmentation_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "low_level_alloc_unit_test",
    srcs = [
        "low_level_alloc_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

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

cc_test(
    name = "markidle_unit_test",
    srcs = [
        "markidle_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "memalign_unit_test",
    srcs = [
        "memalign_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "packed_cache_unit_test",
    srcs = [
        "packed-cache_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "page_heap_unit_test",
    srcs = [
        "page_heap_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "pagemap_unit_test",
    srcs = [
        "pagemap_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "profile_handler_unit_test",
    srcs = [
        "profile-handler_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "profiledata_unit_test",
    srcs = [
        "profiledata_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "raw_printer_unit_test",
    srcs = [
        "raw_printer_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "realloc_unit_test",
    srcs = [
        "realloc_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "sampler_unit_test",
    srcs = [
        "sampler_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "sampling_test_bin",
    srcs = [
        "sampling_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    visibility = ["//visibility:private"],
    deps = [":test_util"],
)

sh_test(
    name = "sampling_unit_test",
    size = "small",
    srcs = ["sampling_test.sh"],
    data = [
        ":sampling_test_bin",
    ],
    licenses = ["permissive"],
    deps = [
        "//third_party/tcmalloc:pprof",
    ],
)

cc_test(
    name = "simple_compat_unit_test",
    srcs = [
        "simple_compat_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "stack_trace_table_unit_test",
    srcs = [
        "stack_trace_table_test.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "stacktrace_unit_test",
    srcs = [
        "stacktrace_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "system_alloc_unit_test",
    srcs = [
        "system-alloc_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)

cc_test(
    name = "tcmalloc_large_unit_test",
    srcs = [
        "tcmalloc_large_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [":test_util"],
)
