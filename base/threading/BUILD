package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "platform_thread.h",
        "post_task_and_reply_impl.h",
        "scoped_blocking_call.h",
        "sequence_bound.h",
        "sequence_local_storage_map.h",
        "sequence_local_storage_slot.h",
        "sequenced_task_runner_handle.h",
        "simple_thread.h",
        "thread.h",
        "thread_checker.h",
        "thread_checker_impl.h",
        "thread_collision_warner.h",
        "thread_id_name_manager.h",
        "thread_local.h",
        "thread_local_storage.h",
        "thread_restrictions.h",
        "thread_task_runner_handle.h",
        "watchdog.h",
    ] + [
        "platform_thread_internal_posix.h",
    ],
)

filegroup(
    name = "threading",
    srcs = [
        "post_task_and_reply_impl.cc",
        "scoped_blocking_call.cc",
        "sequence_local_storage_map.cc",
        "sequence_local_storage_slot.cc",
        "sequenced_task_runner_handle.cc",
        "simple_thread.cc",
        "thread.cc",
        "thread_checker_impl.cc",
        "thread_collision_warner.cc",
        "thread_id_name_manager.cc",
        "thread_local_storage.cc",
        "thread_restrictions.cc",
        "thread_task_runner_handle.cc",
        "watchdog.cc",
    ] + [
        # LINUX
        "platform_thread_internal_posix.cc",
        "platform_thread_posix.cc",
        "thread_local_storage_posix.cc",
        "platform_thread_linux.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "platform_thread_unittest.cc",
        "post_task_and_reply_impl_unittest.cc",
        "scoped_blocking_call_unittest.cc",
        "sequence_bound_unittest.cc",
        "sequence_local_storage_map_unittest.cc",
        "sequence_local_storage_slot_unittest.cc",
        "sequenced_task_runner_handle_unittest.cc",
        "simple_thread_unittest.cc",
        "thread_checker_unittest.cc",
        "thread_collision_warner_unittest.cc",
        "thread_id_name_manager_unittest.cc",
        "thread_local_storage_unittest.cc",
        "thread_local_unittest.cc",
        "thread_restrictions_unittest.cc",
        "thread_task_runner_handle_unittest.cc",
        "thread_unittest.cc",
        "watchdog_unittest.cc",
    ],
)
