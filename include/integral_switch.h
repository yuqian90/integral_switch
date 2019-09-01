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

#include <tuple>
#include <type_traits>

namespace integral_switch {

#if defined(__cpp_constexpr) && __cpp_constexpr >= 201304
#define USE_CPP_14_CONSTEXPR
#endif

#ifndef __has_attribute
#define __has_attribute(x) 0
#endif

#if __has_attribute(always_inline) || defined(__GNUC__)
#define INTEGRAL_SWITCH_ALWAYS_INLINE __attribute__((__always_inline__)) inline
#elif defined(_MSC_VER)
#define INTEGRAL_SWITCH_ALWAYS_INLINE __forceinline
#else
#define INTEGRAL_SWITCH_ALWAYS_INLINE inline
#endif

namespace detail {

// Some helper utilities
template <bool... Bs> struct bool_sequence {};

template <bool... Is>
using all = std::is_same<bool_sequence<true, Is...>, bool_sequence<Is..., true>>;

template <typename... Ts> using first_t = typename std::tuple_element<0, std::tuple<Ts...>>::type;

template <typename...> struct integral_switch_impl; // undefined

template <> struct integral_switch_impl<> {
    template <typename Ret, typename Visitor, typename T>
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&, T &&) {
        throw std::invalid_argument("value");
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&, T &&,
                                                                        U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&, T &&, U &&default_ret)
#endif
    {
        return std::forward<U>(default_ret);
    }
};

template <typename IHead0> struct integral_switch_impl<IHead0> {
    template <typename Ret, typename Visitor, typename T>
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        default:
            return integral_switch_impl<>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

template <typename IHead0, typename IHead1> struct integral_switch_impl<IHead0, IHead1> {
    template <typename Ret, typename Visitor, typename T>
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
        case IHead31::value:
            return visitor(IHead31{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
        case IHead31::value:
            return visitor(IHead31{});
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
          typename IHead30, typename IHead31, typename IHead32>
struct integral_switch_impl<IHead0, IHead1, IHead2, IHead3, IHead4, IHead5, IHead6, IHead7, IHead8,
                            IHead9, IHead10, IHead11, IHead12, IHead13, IHead14, IHead15, IHead16,
                            IHead17, IHead18, IHead19, IHead20, IHead21, IHead22, IHead23, IHead24,
                            IHead25, IHead26, IHead27, IHead28, IHead29, IHead30, IHead31,
                            IHead32> {
    template <typename Ret, typename Visitor, typename T>
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
        case IHead31::value:
            return visitor(IHead31{});
        case IHead32::value:
            return visitor(IHead32{});
        default:
            return integral_switch_impl<>::template dispatch<Ret>(std::forward<Visitor>(visitor),
                                                                  std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
        case IHead31::value:
            return visitor(IHead31{});
        case IHead32::value:
            return visitor(IHead32{});
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
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch(Visitor &&visitor, T &&value) {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
        case IHead31::value:
            return visitor(IHead31{});
        default:
            return integral_switch_impl<ITail...>::template dispatch<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value));
        }
    }

    template <typename Ret, typename Visitor, typename T, typename U>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr Ret dispatch_nothrow(Visitor &&visitor,
                                                                        T &&value, U &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE Ret dispatch_nothrow(Visitor &&visitor, T &&value,
                                                              U &&default_ret)
#endif
    {
        switch (value) {
        case IHead0::value:
            return visitor(IHead0{});
        case IHead1::value:
            return visitor(IHead1{});
        case IHead2::value:
            return visitor(IHead2{});
        case IHead3::value:
            return visitor(IHead3{});
        case IHead4::value:
            return visitor(IHead4{});
        case IHead5::value:
            return visitor(IHead5{});
        case IHead6::value:
            return visitor(IHead6{});
        case IHead7::value:
            return visitor(IHead7{});
        case IHead8::value:
            return visitor(IHead8{});
        case IHead9::value:
            return visitor(IHead9{});
        case IHead10::value:
            return visitor(IHead10{});
        case IHead11::value:
            return visitor(IHead11{});
        case IHead12::value:
            return visitor(IHead12{});
        case IHead13::value:
            return visitor(IHead13{});
        case IHead14::value:
            return visitor(IHead14{});
        case IHead15::value:
            return visitor(IHead15{});
        case IHead16::value:
            return visitor(IHead16{});
        case IHead17::value:
            return visitor(IHead17{});
        case IHead18::value:
            return visitor(IHead18{});
        case IHead19::value:
            return visitor(IHead19{});
        case IHead20::value:
            return visitor(IHead20{});
        case IHead21::value:
            return visitor(IHead21{});
        case IHead22::value:
            return visitor(IHead22{});
        case IHead23::value:
            return visitor(IHead23{});
        case IHead24::value:
            return visitor(IHead24{});
        case IHead25::value:
            return visitor(IHead25{});
        case IHead26::value:
            return visitor(IHead26{});
        case IHead27::value:
            return visitor(IHead27{});
        case IHead28::value:
            return visitor(IHead28{});
        case IHead29::value:
            return visitor(IHead29{});
        case IHead30::value:
            return visitor(IHead30{});
        case IHead31::value:
            return visitor(IHead31{});
        default:
            return integral_switch_impl<ITail...>::template dispatch_nothrow<Ret>(
                std::forward<Visitor>(visitor), std::forward<T>(value),
                std::forward<U>(default_ret));
        }
    }
};

} // namespace detail

template <typename T, T... v> class integral_switch {
    template <typename Visitor, typename U>
    using return_type_of = decltype(std::declval<Visitor>()(std::declval<U>()));

    template <typename Visitor>
    using return_type = return_type_of<Visitor, detail::first_t<std::integral_constant<T, v>...>>;

    template <typename Visitor> struct check_return_type {
        using expected_type = return_type<Visitor>;

        template <T u> using actual_type = return_type_of<Visitor, std::integral_constant<T, u>>;

        static constexpr bool check() {
            static_assert(detail::all<std::is_same<expected_type, actual_type<v>>::value...>::value,
                          "All return types must be equal");
            return true;
        }
    };

  public:
    template <typename Visitor, typename U>
    static INTEGRAL_SWITCH_ALWAYS_INLINE return_type<Visitor> visit(Visitor &&visitor, U &&value) {
        check_return_type<Visitor>::check();
        return detail::integral_switch_impl<std::integral_constant<T, v>...>::template dispatch<
            return_type<Visitor>>(std::forward<Visitor>(visitor), std::forward<U>(value));
    }

    template <typename Visitor, typename U, typename R>
#ifdef USE_CPP_14_CONSTEXPR
    static INTEGRAL_SWITCH_ALWAYS_INLINE constexpr return_type<Visitor>
    visit_nothrow(Visitor &&visitor, U &&value, R &&default_ret)
#else
    static INTEGRAL_SWITCH_ALWAYS_INLINE return_type<Visitor>
    visit_nothrow(Visitor &&visitor, U &&value, R &&default_ret)
#endif
    {
        check_return_type<Visitor>::check();
        return detail::integral_switch_impl<std::integral_constant<T, v>...>::
            template dispatch_nothrow<return_type<Visitor>>(std::forward<Visitor>(visitor),
                                                            std::forward<U>(value),
                                                            std::forward<R>(default_ret));
    }
};

} // namespace integral_switch

#endif
