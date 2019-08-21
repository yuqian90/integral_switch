#include <gtest/gtest.h>
#include <type_traits>

#include "integral_switch.h"

namespace integral_switch {

constexpr int visit(std::integral_constant<int, 0>) { return 10; }

constexpr int visit(std::integral_constant<int, 1>) { return 20; }

constexpr int visit(std::integral_constant<int, 2>) { return 30; }

#if __cpp_generic_lambdas

TEST(simple_test, genericlambda) // NOLINT
{
    using foo_switch = integral_switch<int, 0, 1, 2>;
    // generic lambda is c++14 only.
    auto visitor = [](auto arg) { return visit(arg); };
    ASSERT_EQ(10, foo_switch::visit(visitor, 0));
    ASSERT_EQ(20, foo_switch::visit(visitor, 1));
    ASSERT_EQ(30, foo_switch::visit(visitor, 2));
    ASSERT_THROW(foo_switch::visit(visitor, 3), std::invalid_argument);
    ASSERT_EQ(10, foo_switch::visit_nothrow(visitor, 0, -1));
    ASSERT_EQ(20, foo_switch::visit_nothrow(visitor, 1, -1));
    ASSERT_EQ(30, foo_switch::visit_nothrow(visitor, 2, -1));
    ASSERT_EQ(-1, foo_switch::visit_nothrow(visitor, 3, -1));
}

#endif

struct Visitor {
    constexpr int operator()(std::integral_constant<int, 0>) const { return 10; }

    constexpr int operator()(std::integral_constant<int, 1>) const { return 20; }

    constexpr int operator()(std::integral_constant<int, 2>) const { return 30; }
};

TEST(simple_test, calloperator) // NOLINT
{
    using foo_switch = integral_switch<int, 0, 1, 2>;
    Visitor visitor;
    ASSERT_EQ(10, foo_switch::visit(visitor, 0));
    ASSERT_EQ(20, foo_switch::visit(visitor, 1));
    ASSERT_EQ(30, foo_switch::visit(visitor, 2));
    ASSERT_THROW(foo_switch::visit(visitor, 3), std::invalid_argument);
    ASSERT_EQ(10, foo_switch::visit_nothrow(visitor, 0, -1));
    ASSERT_EQ(20, foo_switch::visit_nothrow(visitor, 1, -1));
    ASSERT_EQ(30, foo_switch::visit_nothrow(visitor, 2, -1));
    ASSERT_EQ(-1, foo_switch::visit_nothrow(visitor, 3, -1));
}

#ifdef USE_CPP_14_CONSTEXPR
TEST(simple_test, staticassert) // NOLINT
{
    using foo_switch = integral_switch<int, 0, 1, 2>;
    Visitor visitor;
    static_assert(foo_switch::visit_nothrow(visitor, 0, -1) == 10, "");
    static_assert(foo_switch::visit_nothrow(visitor, 1, -1) == 20, "");
    static_assert(foo_switch::visit_nothrow(visitor, 2, -1) == 30, "");
    static_assert(foo_switch::visit_nothrow(visitor, 3, -1) == -1, "");
}
#endif

} // namespace integral_switch
