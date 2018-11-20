package(default_visibility = ["//base:__subpackages__"])

load("//build:buildflag_header.bzl", "buildflag_header")

# tcmalloc is the default allocator on linux x86/x64, other platforms do not use

# The debug CRT on Windows has some debug features that are incompatible with
# the shim. NaCl in particular does seem to link some binaries statically
# against the debug CRT with "is_nacl=false".
# causes all the allocations to be routed via allocator_shim.cc.
# default for linux x86/x64
use_allocator_shim = "true"

# For this build we always use the new tcmalloc fork
use_new_tcmalloc = "true"

buildflag_header(
    name = "allocator_buildflags",
    flags = {
        "USE_ALLOCATOR_SHIM": use_allocator_shim,
        "USE_NEW_TCMALLOC": use_new_tcmalloc,
    },
    header = "buildflags.h",
)

filegroup(
    name = "headers",
    srcs = [
        "allocator_check.h",
        "allocator_extension.h",
        ":allocator_buildflags",
    ] + [
        # POSIX / LINUX
        "allocator_shim.h",
        "allocator_shim_internals.h",
        "allocator_shim_override_cpp_symbols.h",
        "allocator_shim_override_glibc_weak_symbols.h",
        "allocator_shim_override_libc_symbols.h",
    ],
)

filegroup(
    name = "allocator",
    srcs = [
        "allocator_check.cc",
        "allocator_extension.cc",
    ] + [
        "allocator_shim.cc",
        "allocator_shim_default_dispatch_to_tcmalloc.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "allocator_shim_unittest.cc",
        "tcmalloc_unittest.cc",
    ],
)
