package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "nspr",
    srcs = [
        "prtime.cc",
    ],
    hdrs = [
        "prtime.h",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    linkstatic = True,
    deps = [
        "//build:build_config",
    ],
)

cc_test(
    name = "nspr_unit_test",
    testonly = True,
    srcs = [
        "pr_time_unittest.cc",
    ],
    copts = CXXOPTS,
    licenses = ["permissive"],
    deps = [
        ":nspr",
        "//third_party/googletest:gtest_main",
    ],
)
