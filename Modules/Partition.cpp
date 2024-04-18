export module Partition;

export import :Interface;
import :Implementation;

namespace Partition
{
    export class Implementation
    {
    public:
        static void print() noexcept;

    private:
    };

    void Implementation::print() noexcept
    {
        printImpl();
    }
}
