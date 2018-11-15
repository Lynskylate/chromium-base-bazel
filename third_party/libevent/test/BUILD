package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "COPTS")

cc_test(
    name = "regress",
    srcs = [
        "regress.c",
        "regress.gen.c",
        "regress.gen.h",
        "regress.h",
        "regress_dns.c",
        "regress_http.c",
        "regress_rpc.c",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    deps = ["//third_party/libevent"],
)

cc_test(
    name = "test_init",
    srcs = [
        "test-init.c",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    deps = ["//third_party/libevent"],
)

cc_test(
    name = "test_eof",
    srcs = [
        "test-eof.c",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    deps = ["//third_party/libevent"],
)

cc_test(
    name = "test_weof",
    srcs = [
        "test-weof.c",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    deps = ["//third_party/libevent"],
)

cc_test(
    name = "test_time",
    srcs = [
        "test-time.c",
    ],
    copts = COPTS,
    licenses = ["permissive"],
    deps = ["//third_party/libevent"],
)
