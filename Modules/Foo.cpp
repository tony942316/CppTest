module;

#include <iostream>

export module Foo;

export class Foo
{
public:
    static void print() noexcept;

private:
};

void Foo::print() noexcept
{
    std::cout << "Hello Modules!" << std::endl;
}
