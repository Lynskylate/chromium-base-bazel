package(default_visibility = ["//visibility:public"])

cc_library(
    name = "build_config",
    hdrs = [
        "build_config.h",
        "buildflag.h",
    ],
    linkstatic = True,
)

# Enable sanitizers for debugging
config_setting(
    name = "config_enable_sanitizer",
    define_values = {
        "sanitizer": "true",
    },
)
