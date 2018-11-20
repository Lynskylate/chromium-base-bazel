package(default_visibility = ["//base:__subpackages__"])

filegroup(
    name = "headers",
    srcs = [
        "char_traits.h",
        "latin1_string_conversions.h",
        "nullable_string16.h",
        "pattern.h",
        "safe_sprintf.h",
        "strcat.h",
        "string16.h",
        "string_number_conversions.h",
        "string_piece.h",
        "string_piece_forward.h",
        "string_split.h",
        "string_tokenizer.h",
        "string_util.h",
        "stringize_macros.h",
        "stringprintf.h",
        "sys_string_conversions.h",
        "utf_offset_string_conversions.h",
        "utf_string_conversion_utils.h",
        "utf_string_conversions.h",
    ] + [
        "string_util_posix.h",
    ],
)

filegroup(
    name = "strings",
    srcs = [
        "latin1_string_conversions.cc",
        "nullable_string16.cc",
        "pattern.cc",
        "safe_sprintf.cc",
        "strcat.cc",
        "string16.cc",
        "string_number_conversions.cc",
        "string_piece.cc",
        "string_split.cc",
        "string_util.cc",
        "string_util_constants.cc",
        "stringprintf.cc",
        "utf_offset_string_conversions.cc",
        "utf_string_conversion_utils.cc",
        "utf_string_conversions.cc",
    ] + [
        "sys_string_conversions_posix.cc",
    ],
)

filegroup(
    name = "unit_test",
    srcs = [
        "char_traits_unittest.cc",
        "nullable_string16_unittest.cc",
        "pattern_unittest.cc",
        "safe_sprintf_unittest.cc",
        "strcat_unittest.cc",
        "string16_unittest.cc",
        "string_number_conversions_unittest.cc",
        "string_piece_unittest.cc",
        "string_split_unittest.cc",
        "string_tokenizer_unittest.cc",
        "string_util_unittest.cc",
        "stringize_macros_unittest.cc",
        "stringprintf_unittest.cc",
        "sys_string_conversions_unittest.cc",
        "utf_offset_string_conversions_unittest.cc",
        "utf_string_conversions_unittest.cc",
    ],
)
