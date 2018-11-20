package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "modp_b64",
    srcs = [
        "modp_b64.cc",
    ],
    hdrs = [
        "modp_b64.h",
        "modp_b64_data.h",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    linkstatic = True,
    deps = [
        "//build:build_config",
    ],
)
