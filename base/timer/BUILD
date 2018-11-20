package(default_visibility = ["//base:__subpackages__"])

load("//build:compiler.bzl", "CXXOPTS")

filegroup(
    name = "headers",
    srcs = [
        "elapsed_timer.h",
        "hi_res_timer_manager.h",
        "timer.h",
    ],
)

filegroup(
    name = "timer",
    srcs = [
        "elapsed_timer.cc",
        "timer.cc",
    ] + [
        "hi_res_timer_manager_posix.cc",
    ],
)

filegroup(
    name = "test_support_headers",
    srcs = [
        "mock_timer.h",
    ],
)

filegroup(
    name = "test_support",
    srcs = [
        "mock_timer.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "hi_res_timer_manager_unittest.cc",
        "mock_timer_unittest.cc",
        "timer_unittest.cc",
    ],
)
