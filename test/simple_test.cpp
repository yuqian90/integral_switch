#include <type_traits>
#include <gtest/gtest.h>

#include "integral_switch.h"

namespace integral_switch{

struct FooVisitor
{
    constexpr int operator()(std::integral_constant<int, 0>) const
    {
        return 10;
    }

    constexpr int operator()(std::integral_constant<int, 1>) const
    {
        return 20;
    }

    constexpr int operator()(std::integral_constant<int, 2>) const
    {
        return 30;
    }
};

TEST(simple_test, test0) // NOLINT
{
    using foo_switch = integral_switch<int, 0, 1, 2>;

    FooVisitor visitor;
    ASSERT_EQ(10, foo_switch::visit(visitor, 0));
    ASSERT_EQ(20, foo_switch::visit(visitor, 1));
    ASSERT_EQ(30, foo_switch::visit(visitor, 2));
}
}
