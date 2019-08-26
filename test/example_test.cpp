#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <type_traits>

#include "integral_switch.h"

namespace integral_switch {

using foo_switch = integral_switch<int, 0, 1, 2>;

struct Visitor {
    void operator()(std::integral_constant<int, 0>) const {
        std::cout << "0: std::integral_constant<int, 0>" << '\n';
    }

    void operator()(std::integral_constant<int, 1>) const {
        std::cout << "1: std::integral_constant<int, 1>" << '\n';
    }

    void operator()(std::integral_constant<int, 2>) const {
        std::cout << "2: std::integral_constant<int, 2>" << '\n';
    }
};

TEST(example_test, example) // NOLINT
{
    Visitor visitor;
    testing::internal::CaptureStdout();
    for (int i = 0; i <= 2; ++i) {
        foo_switch::visit(visitor, i);
    }
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "0: std::integral_constant<int, 0>\n"
                      "1: std::integral_constant<int, 1>\n"
                      "2: std::integral_constant<int, 2>\n");
}

} // namespace integral_switch
