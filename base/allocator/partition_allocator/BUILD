package(default_visibility = ["//base:__subpackages__"])

load("//build:buildflag_header.bzl", "buildflag_header")

buildflag_header(
    name = "partition_alloc_buildflags",
    flags = {
        # Partition alloc is included by default except iOS.
        "USE_PARTITION_ALLOC": "true",
    },
    header = "partition_alloc_buildflags.h",
)

filegroup(
    name = "headers",
    srcs = [
        "address_space_randomization.h",
        "oom.h",
        "oom_callback.h",
        "page_allocator.h",
        "page_allocator_constants.h",
        "page_allocator_internal.h",
        "partition_alloc.h",
        "partition_alloc_constants.h",
        "partition_bucket.h",
        "partition_cookie.h",
        "partition_direct_map_extent.h",
        "partition_freelist_entry.h",
        "partition_oom.h",
        "partition_page.h",
        "partition_root_base.h",
        "spin_lock.h",
        ":partition_alloc_buildflags",
    ] + [
        "page_allocator_internals_posix.h",
    ],
)

filegroup(
    name = "partition_allocator",
    srcs = [
        "address_space_randomization.cc",
        "oom_callback.cc",
        "page_allocator.cc",
        "partition_alloc.cc",
        "partition_bucket.cc",
        "partition_oom.cc",
        "partition_page.cc",
        "partition_root_base.cc",
        "spin_lock.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "address_space_randomization_unittest.cc",
        "page_allocator_unittest.cc",
        "partition_alloc_unittest.cc",
        "spin_lock_unittest.cc",
    ],
)
