package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "COPTS")

cc_library(
    name = "dynamic_annotations",
    srcs = [
        "dynamic_annotations.c",
    ],
    hdrs = [
        "dynamic_annotations.h",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    linkstatic = True,
    deps = [
        "//third_party/valgrind",
    ],
)
