#include <limits>

int main()
{
    auto x = std::numeric_limits<int>::max(); // NOLINT
    x++;
    return 0;
}
