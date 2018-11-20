package(default_visibility = ["//base:__subpackages__"])

load("//build:buildflag_header.bzl", "buildflag_header")

buildflag_header(
    name = "debug_buildflags",
    flags = {
        # Indicates if the Location object contains the source code information
        # (file, function, line). False means only the program counter (and currently
        # file name) is saved.
        "ENABLE_LOCATION_SOURCE": "true",
        # Compile in such a way as to enable profiling of the generated code. For
        # example, don't omit the frame pointer and leave in symbols.
        "ENABLE_PROFILING": "false",
        # In general assume that if we have frame pointers then we can use them to
        # unwind the stack. However, this requires that they are enabled by default for
        # most translation units, that they are emitted correctly, and that the
        # compiler or platform provides a way to access them.
        # Enabled on linux x86/x64 platforms
        "CAN_UNWIND_WITH_FRAME_POINTERS": "true",
        # Unsafe developer build. Has developer-friendly features that may weaken or
        # disable security measures like sandboxing or ASLR.
        # IMPORTANT: Unsafe developer builds should never be distributed to end users.
        "UNSAFE_DEVELOPER_BUILD": "false",
        # Android support only
        "CAN_UNWIND_WITH_CFI_TABLE": "false",
    },
    header = "debugging_buildflags.h",
)

filegroup(
    name = "headers",
    srcs = [
        "activity_analyzer.h",
        "activity_tracker.h",
        "alias.h",
        "asan_invalid_access.h",
        "crash_logging.h",
        "debugger.h",
        "dump_without_crashing.h",
        "leak_annotations.h",
        "leak_tracker.h",
        "profiler.h",
        "stack_trace.h",
        "task_annotator.h",
        "thread_heap_usage_tracker.h",
        ":debug_buildflags",
    ] + [
        "proc_maps_linux.h",
        "elf_reader_linux.h",
    ],
)

filegroup(
    name = "debug",
    srcs = [
        "activity_analyzer.cc",
        "activity_tracker.cc",
        "alias.cc",
        "asan_invalid_access.cc",
        "crash_logging.cc",
        "debugger.cc",
        "dump_without_crashing.cc",
        "profiler.cc",
        "stack_trace.cc",
        "task_annotator.cc",
        "thread_heap_usage_tracker.cc",
    ] + [
        "proc_maps_linux.cc",
        "debugger_posix.cc",
        "stack_trace_posix.cc",
        "elf_reader_linux.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "activity_analyzer_unittest.cc",
        "activity_tracker_unittest.cc",
        "alias_unittest.cc",
        "crash_logging_unittest.cc",
        "debugger_unittest.cc",
        "elf_reader_linux_unittest.cc",
        "leak_tracker_unittest.cc",
        "proc_maps_linux_unittest.cc",
        "stack_trace_unittest.cc",
        "task_annotator_unittest.cc",
        "thread_heap_usage_tracker_unittest.cc",
    ],
)
