# integral_switch

> integral_switch "maps" a runtime integral value to a static type. The performance is comparable to that of a hand-rolled switch-case statement.

[![travis][badge.travis]][travis]

[badge.travis]: https://travis-ci.com/yuqian90/integral_switch.svg?branch=master

[travis]: https://travis-ci.com/yuqian90/integral_switch

- Works for arbitrarily large number of elements
- No code generation
- No macro magic
- No extra dependencies
- Single-header
- As fast as switch-case statements
- Continuously tested against several versions of __clang/gcc/xcode__ for __C++11__/__14__/__17__

Example usage:

```c++
#include <iostream>
#include <type_traits>

#include "integral_switch.h"

using foo_switch = integral_switch<int, 0, 1, 2>;

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

    for (int i = 0; i <= 2; ++i)
        foo_switch::visit(visitor, i);
}
```
