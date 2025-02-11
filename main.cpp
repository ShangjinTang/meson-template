#include <iostream>

// #define ENABLE_FMT
// #define ENABLE_SPDLOG
// #define ENABLE_MSGSL_EXAMPLES
// #define ENABLE_CLI11
// #define ENABLE_DOCTEST
// #define ENABLE_GTEST

#ifdef ENABLE_FMT
#include "fmt/core.h"
#endif

#ifdef ENABLE_SPDLOG
#include "spdlog/spdlog.h"
#endif

#ifdef ENABLE_DOCTEST
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"

TEST_CASE("Addition") {
    int a = 2;
    int b = 3;
    CHECK(a + b == 5);
}
#endif

#ifdef ENABLE_GTEST
#include "gtest/gtest.h"

// NOLINTNEXTLINE
TEST(Subtraction, Integers) {
    int a = 5;
    int b = 3;
    EXPECT_EQ(a - b, 2);
}
#endif

#ifdef ENABLE_CLI11
#include "CLI/App.hpp"
#include "CLI/CLI.hpp"
#endif

#ifdef ENABLE_MSGSL_EXAMPLES
#include "gsl/pointers"
size_t getStringLength(gsl::not_null<std::string *> strPtr) {
    return strPtr->length();
}
#endif

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
#ifdef ENABLE_CLI11
    CLI::App app{"A demo program of cmake-template"};
    argv = app.ensure_utf8(argv);
    std::string powered_by = "cli11";
    app.add_option("-p, --powered_by", powered_by, "Powered-By Information");
    CLI11_PARSE(app, argc, argv);
    std::cout << "Support parse flags, powered by: " << powered_by << std::endl;
#endif

    std::cout << "----------------------------------------------------------------------\n";

#ifdef ENABLE_DOCTEST
    doctest::Context context;
    int doctest_res = context.run();
    context.applyCommandLine(argc, argv);
    if (context.shouldExit()) {
        return doctest_res;
    }
#endif

#ifdef ENABLE_GTEST
    ::testing::InitGoogleTest(&argc, argv);
    int gtest_res = RUN_ALL_TESTS();
    if (static_cast<bool>(gtest_res)) {
        return gtest_res;
    }
#endif

#ifdef ENABLE_MSGSL_EXAMPLES
    std::string str = "ms-gsl";
    fmt::print("Length of string '{}' is: {}\n", str, getStringLength(&str));
#endif

#ifdef ENABLE_SPDLOG
    spdlog::info("Welcome to spdlog!");
#endif

#ifdef ENABLE_FMT
    fmt::print("{}, {}!\n", "Hello", "{fmt}");
#endif

    std::cout << "----------------------------------------------------------------------\n";

    return 0;
}
