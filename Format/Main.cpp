#include <version>

#include <iostream>

#ifdef __cpp_lib_format
#include <format>
#endif // __cpp_lib_format

int main()
{
#ifdef __cpp_lib_format
    std::cout << std::format("{} {}!", "Hello", "std::format") << std::endl;
#else
    std::cout << "std::format UNAVAILABLE!" << std::endl;
#endif // __cpp_lib_format
}
