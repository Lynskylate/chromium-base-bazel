package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "eintr_wrapper.h",
        "file_descriptor_shuffle.h",
        "global_descriptors.h",
        "safe_strerror.h",
        "unix_domain_socket.h",
    ] + [
        "can_lower_nice_to.h",
    ],
)

filegroup(
    name = "posix",
    srcs = [
        "file_descriptor_shuffle.cc",
        "global_descriptors.cc",
        "safe_strerror.cc",
        "unix_domain_socket.cc",
    ] + [
        "can_lower_nice_to.cc",
    ],
)
