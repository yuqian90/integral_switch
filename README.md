# integral_switch
integral_switch can be used to dispatch a visitor to the right static type based on a runtime integral value. The performance is comparable to that of a hand-rolled switch-case statement.

Example usage:

```
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
