export module Partition:Interface;

import IOStream;

namespace Partition
{
    export class Interface
    {
    public:
        static void print() noexcept
        {
            std::cout << "Hello Partition Module Interface Units!" << std::endl;
        }

    private:
    };

    export class Implementation
    {
    public:
        static void print() noexcept;

    private:
    };
}
