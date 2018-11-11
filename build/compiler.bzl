# Compiler options

COPTS = [
    "-fno-exceptions",
    "-Wno-unused-result",
    "-Wno-unused-function",
    "-Wno-unused-local-typedefs",
    "-Wno-unused-variable",
]

CXXOPTS = COPTS + [
    "-std=c++14",
]
