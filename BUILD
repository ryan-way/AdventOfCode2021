load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

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
    name = "hello_test",
    size = "small",
    srcs = ["hello_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":aoc_lib"
        ],
    )
