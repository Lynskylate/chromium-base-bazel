package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "lock_free_address_hash_set.h",
        "module_cache.h",
        "poisson_allocation_sampler.h",
        "sampling_heap_profiler.h",
    ],
)

filegroup(
    name = "sampling_heap_profiler",
    srcs = [
        "lock_free_address_hash_set.cc",
        "module_cache.cc",
        "module_cache_posix.cc",
        "poisson_allocation_sampler.cc",
        "sampling_heap_profiler.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "lock_free_address_hash_set_unittest.cc",
        "module_cache_unittest.cc",
        "sampling_heap_profiler_unittest.cc",
    ],
)
