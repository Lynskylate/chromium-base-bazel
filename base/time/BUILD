package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "clock.h",
        "default_clock.h",
        "default_tick_clock.h",
        "tick_clock.h",
        "time.h",
        "time_override.h",
        "time_to_iso8601.h",
    ],
)

filegroup(
    name = "time",
    srcs = [
        "clock.cc",
        "default_clock.cc",
        "default_tick_clock.cc",
        "tick_clock.cc",
        "time.cc",
        "time_override.cc",
        "time_to_iso8601.cc",
    ] + [
        "time_conversion_posix.cc",
        "time_exploded_posix.cc",
        "time_now_posix.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "time_unittest.cc",
    ],
)
