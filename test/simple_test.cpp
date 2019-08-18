#include <type_traits>
#include <gtest/gtest.h>

#include "integral_switch.h"

namespace integral_switch{

constexpr int visit(std::integral_constant<int, 0>)
{
    return 10;
}

constexpr int visit(std::integral_constant<int, 1>)
{
    return 20;
}

constexpr int visit(std::integral_constant<int, 2>)
{
    return 30;
}

#if __cpp_generic_lambdas

TEST(simple_test, genericlambda) // NOLINT
{
    using foo_switch = integral_switch<int, 0, 1, 2>;
    // generic lambda is c++14 only.
    auto visitor = [](auto arg){
        return visit(arg);
    };
    ASSERT_EQ(10, foo_switch::visit(visitor, 0));
    ASSERT_EQ(20, foo_switch::visit(visitor, 1));
    ASSERT_EQ(30, foo_switch::visit(visitor, 2));
}

#endif

struct Visitor
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

TEST(simple_test, calloperator) // NOLINT
{
    using foo_switch = integral_switch<int, 0, 1, 2>;
    Visitor visitor;
    ASSERT_EQ(10, foo_switch::visit(visitor, 0));
    ASSERT_EQ(20, foo_switch::visit(visitor, 1));
    ASSERT_EQ(30, foo_switch::visit(visitor, 2));
}

}
