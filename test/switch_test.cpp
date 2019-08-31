/*
 * switch_test.cpp
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
#include <type_traits>

#include "integral_switch.h"

namespace integral_switch {

template <std::size_t I> using size_constant = std::integral_constant<std::size_t, I>;

struct Visitor {
    template <std::size_t I> constexpr std::size_t operator()(size_constant<I>) const { return I; }
};

using switch_ =
    integral_switch<std::size_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                    19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
                    39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
                    59, 60, 61, 62, 63, 64, 65, 66, 67>;

TEST(switch_test, visit) {

    Visitor visitor;

    ASSERT_EQ(0, switch_::visit(visitor, 0));
    ASSERT_EQ(32, switch_::visit(visitor, 32));
    ASSERT_EQ(64, switch_::visit(visitor, 64));
    ASSERT_EQ(67, switch_::visit(visitor, 67));
    ASSERT_THROW(switch_::visit(visitor, 68), std::invalid_argument);
}

TEST(switch_test, visit_nothrow) {

    Visitor visitor;

    ASSERT_EQ(0, switch_::visit_nothrow(visitor, 0, -1));
    ASSERT_EQ(32, switch_::visit_nothrow(visitor, 32, -1));
    ASSERT_EQ(64, switch_::visit_nothrow(visitor, 64, -1));
    ASSERT_EQ(67, switch_::visit_nothrow(visitor, 67, -1));
    ASSERT_EQ(-1, switch_::visit_nothrow(visitor, 68, -1));
}

template <std::size_t I> constexpr int visit(size_constant<I>) { return I; }

#if __cpp_generic_lambdas

TEST(switch_test, genericlambda) {
    auto visitor = [](auto arg) { return visit(arg); };
    ASSERT_EQ(0, switch_::visit(visitor, 0));
    ASSERT_EQ(32, switch_::visit(visitor, 32));
    ASSERT_EQ(64, switch_::visit(visitor, 64));
    ASSERT_EQ(67, switch_::visit(visitor, 67));
    ASSERT_THROW(switch_::visit(visitor, 68), std::invalid_argument);
}

TEST(switch_test, genericlambda_nothrow) {
    auto visitor = [](auto arg) { return visit(arg); };
    ASSERT_EQ(0, switch_::visit_nothrow(visitor, 0, -1));
    ASSERT_EQ(32, switch_::visit_nothrow(visitor, 32, -1));
    ASSERT_EQ(64, switch_::visit_nothrow(visitor, 64, -1));
    ASSERT_EQ(67, switch_::visit_nothrow(visitor, 67, -1));
    ASSERT_EQ(-1, switch_::visit_nothrow(visitor, 68, -1));
}
#endif

#ifdef USE_CPP_14_CONSTEXPR
TEST(switch_test, staticassert) {
    Visitor visitor;
    static_assert(switch_::visit_nothrow(visitor, 0, -1) == static_cast<std::size_t>(0), "");
    static_assert(switch_::visit_nothrow(visitor, 32, -1) == static_cast<std::size_t>(32), "");
    static_assert(switch_::visit_nothrow(visitor, 64, -1) == static_cast<std::size_t>(64), "");
    static_assert(switch_::visit_nothrow(visitor, 67, -1) == static_cast<std::size_t>(67), "");
    static_assert(switch_::visit_nothrow(visitor, 68, -1) == static_cast<std::size_t>(-1), "");
}
#endif

} // namespace integral_switch
