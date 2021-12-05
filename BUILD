load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "aoc_lib",
    srcs = glob(
        include = [
            "src/*.cpp",
            ],
        exclude = [
            "src/main.cpp"
            ]
        ),
    hdrs = glob([
        "src/**/*.h"
        ])
    )

cc_binary(
    name = "aoc",
    srcs = ["src/main.cpp"],
    deps = [":aoc_lib"]
    )

cc_test(
    name = "test",
    size = "small",
    srcs = glob(["test/**/*.cpp"]),
    includes = ["src"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":aoc_lib"
        ],
    )
