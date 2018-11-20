package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "kill.h",
        "launch.h",
        "memory.h",
        "process.h",
        "process_handle.h",
        "process_info.h",
        "process_iterator.h",
        "process_metrics.h",
        "process_metrics_iocounters.h",
    ] + [
        "internal_linux.h",
    ],
)

filegroup(
    name = "process",
    srcs = [
        "kill.cc",
        "launch.cc",
        "memory.cc",
        "process_handle.cc",
        "process_iterator.cc",
        "process_metrics.cc",
    ] + [
        # LINUX / POSIX
        "process_linux.cc",
        "process_metrics_linux.cc",
        "kill_posix.cc",
        "launch_posix.cc",
        "process_handle_posix.cc",
        "process_metrics_posix.cc",
        "process_posix.cc",
        "internal_linux.cc",
        "memory_linux.cc",
        "process_handle_linux.cc",
        "process_iterator_linux.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "memory_unittest.cc",
        "process_metrics_unittest.cc",
        "process_unittest.cc",
        "process_util_unittest.cc",
    ],
)
