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

TEST(switch_test, visit) // NOLINT
{

    Visitor visitor;

    ASSERT_EQ(0, switch_::visit(visitor, 0));
    ASSERT_EQ(32, switch_::visit(visitor, 32));
    ASSERT_EQ(64, switch_::visit(visitor, 64));
    ASSERT_EQ(67, switch_::visit(visitor, 67));
    ASSERT_THROW(switch_::visit(visitor, 68), std::invalid_argument);
}

TEST(switch_test, visit_nothrow) // NOLINT
{

    Visitor visitor;

    ASSERT_EQ(0, switch_::visit_nothrow(visitor, 0, -1));
    ASSERT_EQ(32, switch_::visit_nothrow(visitor, 32, -1));
    ASSERT_EQ(64, switch_::visit_nothrow(visitor, 64, -1));
    ASSERT_EQ(67, switch_::visit_nothrow(visitor, 67, -1));
    ASSERT_EQ(-1, switch_::visit_nothrow(visitor, 68, -1));
}

template <std::size_t I> constexpr int visit(size_constant<I>) { return I; }

#if __cpp_generic_lambdas

TEST(switch_test, genericlambda) // NOLINT
{
    auto visitor = [](auto arg) { return visit(arg); };
    ASSERT_EQ(0, switch_::visit(visitor, 0));
    ASSERT_EQ(32, switch_::visit(visitor, 32));
    ASSERT_EQ(64, switch_::visit(visitor, 64));
    ASSERT_EQ(67, switch_::visit(visitor, 67));
    ASSERT_THROW(switch_::visit(visitor, 68), std::invalid_argument);
}

TEST(switch_test, genericlambda_nothrow) // NOLINT
{
    auto visitor = [](auto arg) { return visit(arg); };
    ASSERT_EQ(0, switch_::visit_nothrow(visitor, 0, -1));
    ASSERT_EQ(32, switch_::visit_nothrow(visitor, 32, -1));
    ASSERT_EQ(64, switch_::visit_nothrow(visitor, 64, -1));
    ASSERT_EQ(67, switch_::visit_nothrow(visitor, 67, -1));
    ASSERT_EQ(-1, switch_::visit_nothrow(visitor, 68, -1));
}

TEST(switch_test, staticassert) // NOLINT
{
    Visitor visitor;
    static_assert(switch_::visit_nothrow(visitor, 0, -1) == 0, "");
    static_assert(switch_::visit_nothrow(visitor, 32, -1) == 32, "");
    static_assert(switch_::visit_nothrow(visitor, 64, -1) == 64, "");
    static_assert(switch_::visit_nothrow(visitor, 67, -1) == 67, "");
    static_assert(switch_::visit_nothrow(visitor, 68, -1) == -1, "");
}
#endif

} // namespace integral_switch
