# integral_switch
integral_switch can be used to dispatch a visitor to the right static integral_constant type based on a runtime integral value.

Example usage:

```
using foo_switch = integral_switch<0, 1, 2>;

void visitor(std::integral_constant<0>)
{
    std::cout << "print 0" << std::endl;
}

void visitor(std::integral_constant<1>);
{
    std::cout << "print 1" << std::endl;
}

void visitor(std::integral_constant<2>);
{
    std::cout << "print 2" << std::endl;
}

// i is a runtime value here.
for(int i = 0; i <=2; ++i)
    foo_switch::visit(visitor, i);
```
