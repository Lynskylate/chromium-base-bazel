package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "native_stack_sampler.h",
        "stack_sampling_profiler.h",
    ],
)

filegroup(
    name = "profiler",
    srcs = [
        "native_stack_sampler.cc",
        "native_stack_sampler_posix.cc",
        "stack_sampling_profiler.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "stack_sampling_profiler_unittest.cc",
    ],
)
