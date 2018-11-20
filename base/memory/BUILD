package(default_visibility = ["//base:__subpackages__"])

load("//build:buildflag_header.bzl", "buildflag_header")

# Build flags for ProtectedMemory, temporary workaround for crbug.com/792777
buildflag_header(
    name = "protected_memory_buildflags",
    flags = {
        # Set to true to use lld, the LLVM linker. This flag may be used on Windows, Linux or Fuschia.
        "USE_LLD": "false",
    },
    header = "protected_memory_buildflags.h",
)

filegroup(
    name = "headers",
    srcs = [
        "aligned_memory.h",
        "discardable_memory.h",
        "discardable_memory_allocator.h",
        "discardable_shared_memory.h",
        "free_deleter.h",
        "linked_ptr.h",
        "memory_pressure_listener.h",
        "memory_pressure_monitor.h",
        "platform_shared_memory_region.h",
        "protected_memory.h",
        "protected_memory_cfi.h",
        "ptr_util.h",
        "raw_scoped_refptr_mismatch_checker.h",
        "read_only_shared_memory_region.h",
        "ref_counted.h",
        "ref_counted_delete_on_sequence.h",
        "ref_counted_memory.h",
        "scoped_policy.h",
        "scoped_refptr.h",
        "shared_memory.h",
        "shared_memory_handle.h",
        "shared_memory_helper.h",
        "shared_memory_mapping.h",
        "shared_memory_tracker.h",
        "singleton.h",
        "unsafe_shared_memory_region.h",
        "weak_ptr.h",
        "writable_shared_memory_region.h",
        ":protected_memory_buildflags",
    ],
)

filegroup(
    name = "memory",
    srcs = [
        "aligned_memory.cc",
        "discardable_memory.cc",
        "discardable_memory_allocator.cc",
        "discardable_shared_memory.cc",
        "memory_pressure_listener.cc",
        "memory_pressure_monitor.cc",
        "platform_shared_memory_region.cc",
        "protected_memory.cc",
        "read_only_shared_memory_region.cc",
        "ref_counted.cc",
        "ref_counted_memory.cc",
        "shared_memory_handle.cc",
        "shared_memory_helper.cc",
        "shared_memory_mapping.cc",
        "shared_memory_tracker.cc",
        "unsafe_shared_memory_region.cc",
        "weak_ptr.cc",
        "writable_shared_memory_region.cc",
    ] + [
        # LINUX
        "protected_memory_posix.cc",
        "platform_shared_memory_region_posix.cc",
        "shared_memory_handle_posix.cc",
        "shared_memory_posix.cc",
    ],
)

filegroup(
    name = "test_support",
    srcs = [
        "fake_memory_pressure_monitor.cc",
    ],
)

filegroup(
    name = "test_support_headers",
    srcs = [
        "fake_memory_pressure_monitor.h",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "aligned_memory_unittest.cc",
        "discardable_shared_memory_unittest.cc",
        "linked_ptr_unittest.cc",
        "memory_pressure_listener_unittest.cc",
        "memory_pressure_monitor_unittest.cc",
        "platform_shared_memory_region_unittest.cc",
        "protected_memory_unittest.cc",
        "ptr_util_unittest.cc",
        "ref_counted_memory_unittest.cc",
        "ref_counted_unittest.cc",
        "shared_memory_mapping_unittest.cc",
        "shared_memory_region_unittest.cc",
        "shared_memory_unittest.cc",
        "singleton_unittest.cc",
        "weak_ptr_unittest.cc",
    ],
)
