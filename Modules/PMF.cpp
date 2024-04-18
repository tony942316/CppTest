module;

#include <iostream>

export module PMF;

export class PMF
{
public:
    static void print() noexcept;

private:
};

module : private;

void PMF::print() noexcept
{
    std::cout << "Hello Private Module Fragments!" << std::endl;
}
