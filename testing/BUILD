package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "testing",
    testonly = True,
    srcs = [
        "multiprocess_func_list.cc",
    ],
    hdrs = [
        "multiprocess_func_list.h",
        "platform_test.h",
    ],
    copts = CXXOPTS,
    linkstatic = True,
    deps = [
        "//third_party/googletest:gtest",
    ],
)
