package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "COPTS")

cc_library(
    name = "xdg_mime",
    srcs = [
        "xdgmime.c",
        "xdgmimealias.c",
        "xdgmimecache.c",
        "xdgmimeglob.c",
        "xdgmimeicon.c",
        "xdgmimeint.c",
        "xdgmimemagic.c",
        "xdgmimeparent.c",
    ],
    hdrs = [
        "xdgmime.h",
        "xdgmimealias.h",
        "xdgmimecache.h",
        "xdgmimeglob.h",
        "xdgmimeicon.h",
        "xdgmimeint.h",
        "xdgmimemagic.h",
        "xdgmimeparent.h",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    linkstatic = True,
)
