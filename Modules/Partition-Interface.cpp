module;

#include <iostream>

export module Partition:Interface;

namespace Partition
{
    export class Interface
    {
    public:
        static void print() noexcept;

    private:
    };

    void Interface::print() noexcept
    {
        std::cout << "Hello Partition Module Interface Units!" << std::endl;
    }
}
