/*
 * integral_switch.h
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

#ifndef INTEGRAL_SWITCH_H_
#define INTEGRAL_SWITCH_H_

#include <type_traits>

namespace integral_switch {

#if defined(__cpp_constexpr) && __cpp_constexpr >= 201304
#define USE_CPP_14_CONSTEXPR
#endif

namespace detail {
template <typename...> struct integral_switch_impl; // undefined

template <> struct integral_switch_impl<> {
    template <typename Ret, typename Visitor, typename T> static Ret dispatch(Visitor &&, T &&) {
        throw std::invalid_argument("value");
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&, T &&, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&, T &&, U &&default_ret)
#endif
    {
        return std::forward<U>(default_ret);
    }
};

template <typename IHead0> struct integral_switch_impl<IHead0> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1> struct integral_switch_impl<IHead0, IHead1> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2>
struct integral_switch_impl<IHead0, IHead1, IHead2> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7,
                            IHead8> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23,
                            IHead24> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25, typename IHead26>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25, typename IHead26, typename IHead27>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26, IHead27> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25, typename IHead26, typename IHead27, typename IHead28>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26, IHead27, IHead28> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25, typename IHead26, typename IHead27, typename IHead28, typename IHead29>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26, IHead27, IHead28, IHead29> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25, typename IHead26, typename IHead27, typename IHead28, typename IHead29,
          typename IHead30>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26, IHead27, IHead28, IHead29, IHead30> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        case IHead30::value:
            return std::forward<Visitor>(visitor)(IHead30{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        case IHead30::value:
            return std::forward<Visitor>(visitor)(IHead30{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25, typename IHead26, typename IHead27, typename IHead28, typename IHead29,
          typename IHead30, typename IHead31>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26, IHead27, IHead28, IHead29, IHead30, IHead31> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        case IHead30::value:
            return std::forward<Visitor>(visitor)(IHead30{});
        case IHead31::value:
            return std::forward<Visitor>(visitor)(IHead31{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        case IHead30::value:
            return std::forward<Visitor>(visitor)(IHead30{});
        case IHead31::value:
            return std::forward<Visitor>(visitor)(IHead31{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1, typename IHead2, typename IHead3, typename IHead4,
          typename IHead5, typename IHead6, typename IHead7, typename IHead8, typename IHead9,
          typename IHead10, typename IHead11, typename IHead12, typename IHead13, typename IHead14,
          typename IHead15, typename IHead16, typename IHead17, typename IHead18, typename IHead19,
          typename IHead20, typename IHead21, typename IHead22, typename IHead23, typename IHead24,
          typename IHead25, typename IHead26, typename IHead27, typename IHead28, typename IHead29,
          typename IHead30, typename IHead31, typename... ITail>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26, IHead27, IHead28, IHead29, IHead30, IHead31,
                            ITail...> {
    template <typename Ret, typename Visitor, typename T>
    static Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        case IHead30::value:
            return std::forward<Visitor>(visitor)(IHead30{});
        case IHead31::value:
            return std::forward<Visitor>(visitor)(IHead31{});
        default:
            return integral_switch_impl<ITail...>::template dispatch<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#else
    static Ret dispatch_nothrow(Visitor &&visitor, T &&value, U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return std::forward<Visitor>(visitor)(IHead0{});
        case IHead1::value:
            return std::forward<Visitor>(visitor)(IHead1{});
        case IHead2::value:
            return std::forward<Visitor>(visitor)(IHead2{});
        case IHead3::value:
            return std::forward<Visitor>(visitor)(IHead3{});
        case IHead4::value:
            return std::forward<Visitor>(visitor)(IHead4{});
        case IHead5::value:
            return std::forward<Visitor>(visitor)(IHead5{});
        case IHead6::value:
            return std::forward<Visitor>(visitor)(IHead6{});
        case IHead7::value:
            return std::forward<Visitor>(visitor)(IHead7{});
        case IHead8::value:
            return std::forward<Visitor>(visitor)(IHead8{});
        case IHead9::value:
            return std::forward<Visitor>(visitor)(IHead9{});
        case IHead10::value:
            return std::forward<Visitor>(visitor)(IHead10{});
        case IHead11::value:
            return std::forward<Visitor>(visitor)(IHead11{});
        case IHead12::value:
            return std::forward<Visitor>(visitor)(IHead12{});
        case IHead13::value:
            return std::forward<Visitor>(visitor)(IHead13{});
        case IHead14::value:
            return std::forward<Visitor>(visitor)(IHead14{});
        case IHead15::value:
            return std::forward<Visitor>(visitor)(IHead15{});
        case IHead16::value:
            return std::forward<Visitor>(visitor)(IHead16{});
        case IHead17::value:
            return std::forward<Visitor>(visitor)(IHead17{});
        case IHead18::value:
            return std::forward<Visitor>(visitor)(IHead18{});
        case IHead19::value:
            return std::forward<Visitor>(visitor)(IHead19{});
        case IHead20::value:
            return std::forward<Visitor>(visitor)(IHead20{});
        case IHead21::value:
            return std::forward<Visitor>(visitor)(IHead21{});
        case IHead22::value:
            return std::forward<Visitor>(visitor)(IHead22{});
        case IHead23::value:
            return std::forward<Visitor>(visitor)(IHead23{});
        case IHead24::value:
            return std::forward<Visitor>(visitor)(IHead24{});
        case IHead25::value:
            return std::forward<Visitor>(visitor)(IHead25{});
        case IHead26::value:
            return std::forward<Visitor>(visitor)(IHead26{});
        case IHead27::value:
            return std::forward<Visitor>(visitor)(IHead27{});
        case IHead28::value:
            return std::forward<Visitor>(visitor)(IHead28{});
        case IHead29::value:
            return std::forward<Visitor>(visitor)(IHead29{});
        case IHead30::value:
            return std::forward<Visitor>(visitor)(IHead30{});
        case IHead31::value:
            return std::forward<Visitor>(visitor)(IHead31{});
        default:
            return integral_switch_impl<ITail...>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

} // namespace detail

template <typename T, T... v> struct integral_switch {
    template <typename Visitor>
    using return_type = typename std::common_type<decltype(
        std::declval<Visitor>()(std::integral_constant<T, v>{}))...>::type;

    template <typename Visitor, typename U>
    static return_type<Visitor> visit(Visitor &&visitor, U &&value) {
        return detail::integral_switch_impl<std::integral_constant<T, v>...>::template dispatch<
            return_type<Visitor>>(std::forward<Visitor>(visitor), std::forward<U>(value));
    }

    template <typename Visitor, typename U, typename R>
#ifdef USE_CPP_14_CONSTEXPR
    static constexpr return_type<Visitor> visit_nothrow(Visitor &&visitor, U &&value,
                                                        R &&default_ret)
#else
    static return_type<Visitor> visit_nothrow(Visitor &&visitor, U &&value, R &&default_ret)
#endif
    {
        return detail::integral_switch_impl<std::integral_constant<T, v>...>::
            template dispatch_nothrow<return_type<Visitor>>(std::forward<Visitor>(visitor),
                                                            std::forward<U>(value),
                                                            std::forward<R>(default_ret));
    }
};

} // namespace integral_switch

#endif
