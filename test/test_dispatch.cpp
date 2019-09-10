/*
 * test_dispatch.cpp
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
struct Type0 {
    constexpr int id() const { return 0; }
};

struct Type1 {
    constexpr int id() const { return 1; }
};

struct Type2 {
    constexpr int id() const { return 2; }
};

struct GetId {
    template <typename T> constexpr int operator()(type<T>) const { return T{}.id(); }
};

using Switch = variadic_switch<Type0, Type1, Type2>;

TEST(test_dispatch, dispatch) {
    GetId visitor;

    ASSERT_EQ(0, Switch::visit(visitor, 0));
    ASSERT_EQ(1, Switch::visit(visitor, 1));
    ASSERT_EQ(2, Switch::visit(visitor, 2));
    ASSERT_THROW(Switch::visit(visitor, 3), std::invalid_argument);

    ASSERT_EQ(0, Switch::visit_nothrow(visitor, 0, -1));
    ASSERT_EQ(1, Switch::visit_nothrow(visitor, 1, -1));
    ASSERT_EQ(2, Switch::visit_nothrow(visitor, 2, -1));
    ASSERT_EQ(-1, Switch::visit_nothrow(visitor, 3, -1));
}

#ifdef USE_CPP_14_CONSTEXPR

TEST(test_dispatch, staticassert) {
    GetId visitor;

    static_assert(0 == Switch::visit_nothrow(visitor, 0, -1), "");
    static_assert(1 == Switch::visit_nothrow(visitor, 1, -1), "");
    static_assert(2 == Switch::visit_nothrow(visitor, 2, -1), "");
    static_assert(-1 == Switch::visit_nothrow(visitor, 3, -1), "");
}

#endif

} // namespace integral_switch
