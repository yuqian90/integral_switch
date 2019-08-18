#ifndef INTEGRAL_SWITCH_H_
#define INTEGRAL_SWITCH_H_

#include <type_traits>

namespace integral_switch{

template<typename T, T... v>
struct integral_switch
{
    template<typename Visitor>
    using return_type = std::common_type<decltype(std::declval<Visitor>()(std::integral_constant<T, v>{}))...>;

    template<typename Visitor>
    static typename return_type<Visitor>::type visit(Visitor&& visitor, T value)
    {
        switch(value)
        {
            case 0:
                return std::forward<Visitor>(visitor)(std::integral_constant<T, 0>{});
            case 1:
                return std::forward<Visitor>(visitor)(std::integral_constant<T, 1>{});
            case 2:
                return std::forward<Visitor>(visitor)(std::integral_constant<T, 2>{});
        }

        throw std::invalid_argument("value");
    }
};
}

#endif
