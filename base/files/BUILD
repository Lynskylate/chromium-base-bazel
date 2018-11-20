package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "dir_reader_fallback.h",
        "file.h",
        "file_enumerator.h",
        "file_path.h",
        "file_path_watcher.h",
        "file_proxy.h",
        "file_tracing.h",
        "file_util.h",
        "important_file_writer.h",
        "memory_mapped_file.h",
        "platform_file.h",
        "scoped_file.h",
        "scoped_temp_dir.h",
    ] + [
        # LINUX
        "dir_reader_linux.h",
        "dir_reader_posix.h",
        "file_descriptor_watcher_posix.h",
    ],
)

filegroup(
    name = "files",
    srcs = [
        "file.cc",
        "file_enumerator.cc",
        "file_path.cc",
        "file_path_constants.cc",
        "file_path_watcher.cc",
        "file_proxy.cc",
        "file_tracing.cc",
        "file_util.cc",
        "important_file_writer.cc",
        "memory_mapped_file.cc",
        "scoped_file.cc",
        "scoped_temp_dir.cc",
    ] + [
        # LINUX
        "file_descriptor_watcher_posix.cc",
        "file_enumerator_posix.cc",
        "file_path_watcher_linux.cc",
        "file_posix.cc",
        "file_util_linux.cc",
        "file_util_posix.cc",
        "memory_mapped_file_posix.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "dir_reader_posix_unittest.cc",
        "file_descriptor_watcher_posix_unittest.cc",
        "file_enumerator_unittest.cc",
        "file_path_unittest.cc",
        "file_path_watcher_unittest.cc",
        "file_proxy_unittest.cc",
        "file_unittest.cc",
        "file_util_unittest.cc",
        "important_file_writer_unittest.cc",
        "memory_mapped_file_unittest.cc",
        "scoped_temp_dir_unittest.cc",
    ],
)
