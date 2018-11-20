package(default_visibility = ["//base:__subpackages__"])

load("//build:buildflag_header.bzl", "buildflag_header")

buildflag_header(
    name = "synchronization_buildflags",
    flags = {
        # Set to true to enable mutex priority inheritance. See the comments in
        # LockImpl::PriorityInheritanceAvailable() in lock_impl_posix.cc for the
        # platform requirements to safely enable priority inheritance.
        "ENABLE_MUTEX_PRIORITY_INHERITANCE": "false",
    },
    header = "synchronization_buildflags.h",
)

filegroup(
    name = "headers",
    srcs = [
        "atomic_flag.h",
        "cancellation_flag.h",
        "condition_variable.h",
        "lock.h",
        "lock_impl.h",
        "spin_wait.h",
        "waitable_event.h",
        "waitable_event_watcher.h",
        ":synchronization_buildflags",
    ],
)

filegroup(
    name = "synchronization",
    srcs = [
        "atomic_flag.cc",
        "lock.cc",
    ] + [
        # LINUX
        "condition_variable_posix.cc",
        "lock_impl_posix.cc",
        "waitable_event_posix.cc",
        "waitable_event_watcher_posix.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "atomic_flag_unittest.cc",
        "condition_variable_unittest.cc",
        "lock_unittest.cc",
        "waitable_event_unittest.cc",
        "waitable_event_watcher_unittest.cc",
    ],
)
