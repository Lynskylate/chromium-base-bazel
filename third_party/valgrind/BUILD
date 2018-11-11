package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "COPTS")

cc_library(
    name = "valgrind",
    hdrs = [
        "memcheck.h",
        "valgrind.h",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    linkstatic = True,
)
