package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "symbolize",
    srcs = [
        "demangle.cc",
        "glog/logging.h",
        "glog/raw_logging.h",
        "symbolize.cc",
    ],
    hdrs = [
        "config.h",
        "demangle.h",
        "symbolize.h",
        "utilities.h",
    ],
    copts = CXXOPTS,
    defines = select({
        "//build:config_enable_sanitizer": ["PRINT_UNSYMBOLIZED_STACK_TRACES"],
        "//conditions:default": [],
    }),
    licenses = ["permissive"],
    linkstatic = True,
)
