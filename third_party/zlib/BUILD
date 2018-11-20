package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "COPTS")

# TODO native optimisations etc
cc_library(
    name = "zlib",
    srcs = [
        "adler32.c",
        "compress.c",
        "crc32.c",
        "crc32.h",
        "deflate.c",
        "gzclose.c",
        "gzlib.c",
        "gzread.c",
        "gzwrite.c",
        "infback.c",
        "inffast.c",
        "inftrees.c",
        "trees.c",
        "uncompr.c",
        "zutil.c",
    ],
    hdrs = [
        "deflate.h",
        "gzguts.h",
        "inffast.h",
        "inffixed.h",
        "inflate.h",
        "inftrees.h",
        "names.h",
        "trees.h",
        "x86.h",
        "zconf.h",
        "zlib.h",
        "zutil.h",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    linkstatic = True,
)
