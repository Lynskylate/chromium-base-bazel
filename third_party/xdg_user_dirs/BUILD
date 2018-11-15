package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "xdg_user_dirs",
    srcs = [
        "xdg_user_dir_lookup.cc",
    ],
    hdrs = [
        "xdg_user_dir_lookup.h",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    linkstatic = True,
)
