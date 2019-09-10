# integral_switch

> __integral_switch__ maps a runtime integral value to a compile-time static type. The performance is comparable to that of a hand-rolled __switch-case__ statement.

[![travis](https://travis-ci.com/yuqian90/integral_switch.svg?branch=master)](https://travis-ci.com/yuqian90/integral_switch)
[![godbolt](https://img.shields.io/badge/try%20it-on%20godbolt-222266.svg)](https://godbolt.org/z/qplpQg)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## Introduction
__integral_switch__ makes it possible to write the following construct in a reusable manner without sacrificing performance. Such __switch-case__ constructs are often written to map a runtime integral value to a static type in scenarios such as factory function, state machine or deserialization. __switch-case__ statements are efficient but they are hard to reuse. There is no easy way around them without resorting to techniques such as x-macros.
```c++
switch(msg.msg_id())
{
    case MsgId::type0:
        return MsgType0::deserialize(msg);
    case MsgId::type1:
        return MsgType1::deserialize(msg);
    case MsgId::type2:
        return MsgType2::deserialize(msg);
    ...
}
```
__integral_switch__ offers an alternative that is equally fast and much more reusable. The underlying implementation uses recursive compile-time __switch-case__ generation that is easy for compilers to optimize, making it as fast as hand-rolled __switch-case__ statement.
- Works for arbitrarily large number of elements
- No code generation
- No macro magic
- No extra dependencies
- No heap allocation
- As fast as __switch-case__ statements. See [benchmark](./script/benchmark.md)
- Continuously tested against several versions of [__clang/gcc/xcode__](https://travis-ci.com/yuqian90/integral_switch) for __C++11__/__14__/__17__
- Single-header

## Examples
### Example 1
__integral_switch::visit()__ maps integeral values to the corresponding __std::integral_constant__ type.
```c++
#include <iostream>

#include "integral_switch.h"

using IntegralSwitch = integral_switch::integral_switch<int, 0, 1, 2>;

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

int main()
{
    Visitor visitor;

    for (int i = 0; i <= 2; ++i) {
        IntegralSwitch::visit(visitor, i);
    }
}
```
Output:
```
0: std::integral_constant<int, 0>

1: std::integral_constant<int, 1>

2: std::integral_constant<int, 2>

```

### Example 2
__variadic_switch::visit()__ offers a slightly different interface that maps a runtime index value to the type corresponding to that index in a variadic type list.

```c++
#include <iostream>

#include "integral_switch.h"

struct Type0 {
    void print() const { std::cout << "Type0" << '\n'; }
};

struct Type1 {
    void print() const { std::cout << "Type1" << '\n'; }
};

struct Type2 {
    void print() const { std::cout << "Type2" << '\n'; }
};

using VariadicSwitch = variadic_switch<Type0, Type1, Type2>;

struct Printer {
    template <typename T> void operator()(type<T>) const { T{}.print(); }
};

int main()
{
    Printer visitor;

    for (int i = 0; i <= 2; ++i) {
        VariadicSwitch::visit(visitor, i);
    }
}
```
Output:
```
Type0
Type1
Type2
```
