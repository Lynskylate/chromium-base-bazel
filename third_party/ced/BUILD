package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "ced",
    srcs = [
        "src/compact_enc_det/compact_enc_det.cc",
        "src/compact_enc_det/compact_enc_det_generated_tables.h",
        "src/compact_enc_det/compact_enc_det_generated_tables2.h",
        "src/compact_enc_det/compact_enc_det_hint_code.cc",
        "src/compact_enc_det/compact_enc_det_hint_code.h",
        "src/util/basictypes.h",
        "src/util/case_insensitive_hash.h",
        "src/util/commandlineflags.h",
        "src/util/encodings/encodings.cc",
        "src/util/encodings/encodings.h",
        "src/util/encodings/encodings.pb.h",
        "src/util/languages/languages.cc",
        "src/util/languages/languages.h",
        "src/util/languages/languages.pb.h",
        "src/util/logging.h",
        "src/util/port.h",
        "src/util/string_util.h",
        "src/util/varsetter.h",
    ],
    hdrs = [
        "src/compact_enc_det/compact_enc_det.h",
    ],
    copts = CXXOPTS + [
        "-Wno-unused-function",
    ],
    defines = [
        "COMPILER_GCC",
        "HTML5_MODE",
    ],
    includes = ["src"],
    licenses = ["permissive"],
    linkstatic = True,
)

cc_test(
    name = "ced_unit_test",
    srcs = [
        "src/compact_enc_det/compact_enc_det_fuzz_test.cc",
        "src/compact_enc_det/compact_enc_det_unittest.cc",
        "src/compact_enc_det/detail_head_string.inc",
        "src/util/encodings/encodings_unittest.cc",
    ],
    copts = CXXOPTS,
    defines = [
        "COMPILER_GCC",
        "HTML5_MODE",
    ],
    licenses = ["permissive"],
    deps = [
        ":ced",
        "//third_party/googletest:gtest_main",
    ],
)
