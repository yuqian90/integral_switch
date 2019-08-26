/*
 * example_test.cpp
 * Copyright (C) 2019  Qian Yu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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
