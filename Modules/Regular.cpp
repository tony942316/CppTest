module;

#include <iostream>

export module Regular;

export class Regular
{
public:
    static void print() noexcept;

private:
};

void Regular::print() noexcept
{
    std::cout << "Hello Regular Modules!" << std::endl;
}
