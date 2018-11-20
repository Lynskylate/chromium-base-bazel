package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "message_loop.h",
        "message_loop_current.h",
        "message_loop_impl.h",
        "message_loop_task_runner.h",
        "message_pump.h",
        "message_pump_default.h",
        "message_pump_for_io.h",
        "message_pump_for_ui.h",
        "pending_task_queue.h",
        "sequenced_task_source.h",
        "timer_slack.h",
    ] + [
        # LINUX
        "watchable_io_message_pump_posix.h",
        "message_pump_libevent.h",
    ],
)

filegroup(
    name = "message_loop",
    srcs = [
        "message_loop.cc",
        "message_loop_current.cc",
        "message_loop_impl.cc",
        "message_loop_task_runner.cc",
        "message_pump.cc",
        "message_pump_default.cc",
        "pending_task_queue.cc",
    ] + [
        # LINUX
        "watchable_io_message_pump_posix.cc",
        "message_pump_libevent.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "message_loop_io_posix_unittest.cc",
        "message_loop_task_runner_unittest.cc",
        "message_loop_unittest.cc",
        "message_pump_libevent_unittest.cc",
    ],
)
