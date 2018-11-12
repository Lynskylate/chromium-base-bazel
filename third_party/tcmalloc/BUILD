package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "CXXOPTS")

cc_library(
    name = "tcmalloc",
    srcs = glob(
        [
            "chromium/**/*.cc",
        ],
        exclude = [
            "chromium/src/windows/*",
            "chromium/src/solaris/*",
            "chromium/src/heap-checker*",
            "chromium/src/tests/*",
            "chromium/src/debugallocation.cc",
            "chromium/src/memfs_malloc.cc",
        ],
    ),
    hdrs = glob([
        "chromium/**/*.h",
    ]),
    copts = CXXOPTS + [
        "-fvisibility=default",
        "-Wno-sign-compare",
    ],
    defines = [
        "NO_HEAP_CHECK",
        "TCMALLOC_USE_DOUBLYLINKED_FREELIST",
        "TCMALLOC_DISABLE_HUGE_ALLOCATIONS",
        # On linux when we use the alloc shim
        #"TCMALLOC_DONT_REPLACE_SYSTEM_ALLOC",
    ],
    includes = [
        ".",
        "chromium/src",
        "chromium/src/base",
    ],
    licenses = [
        "permissive",
    ],
    linkopts = [
        # Don't let linker rip this symbol out, otherwise the heap&cpu
        # profilers will not initialize properly on startup.
        "-Wl,-uIsHeapProfilerRunning,-uProfilerStart",
        # Do the same for heap leak checker.
        "-Wl,-u_Z21InitialMallocHook_NewPKvj,-u_Z22InitialMallocHook_MMapPKvS0_jiiix,-u_Z22InitialMallocHook_SbrkPKvi",
        "-Wl,-u_Z21InitialMallocHook_NewPKvm,-u_Z22InitialMallocHook_MMapPKvS0_miiil,-u_Z22InitialMallocHook_SbrkPKvl",
        "-Wl,-u_ZN15HeapLeakChecker12IgnoreObjectEPKv,-u_ZN15HeapLeakChecker14UnIgnoreObjectEPKv",
    ],
    linkstatic = True,
    deps = [
        "//build:build_config",
        "//third_party/dynamic_annotations",
    ],
)
