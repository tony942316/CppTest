#include <cstdlib>

#include <iostream>
#include <filesystem>
#include <string_view>
#include <vector>
#include <array>
#include <span>

using namespace std::literals;

constexpr auto c_Delim = "============================"sv;

class Tester
{
public:
    Tester(const std::string_view binaryRoot,
        std::span<const std::string_view> tests) noexcept;

    void run() const noexcept;

private:
    void runTest(const std::string_view test) const noexcept;

    std::filesystem::path m_BinaryRoot;
    std::span<const std::string_view> m_Tests;
};

Tester::Tester(const std::string_view binaryRoot,
    std::span<const std::string_view> tests) noexcept
    :
    m_BinaryRoot(binaryRoot),
    m_Tests(tests)
{
}

void Tester::run() const noexcept
{
    for (const std::string_view str : m_Tests)
    {
        runTest(str);
    }
}

void Tester::runTest(const std::string_view test) const noexcept
{
    auto testBinary = m_BinaryRoot;
    testBinary.remove_filename();
#ifdef _WIN32
    testBinary /= ".."sv
#endif // _WIN32
    testBinary /= test;
#ifdef _WIN32
#ifdef NDEBUG
    testBinary /= "Release"sv;
#else
    testBinary /= "Debug"sv;
#endif// _NDEBUG
#endif // _WIN32
    testBinary /= test;

    std::cout << '\n' << c_Delim << std::endl;
    std::cout << "Running Test: "sv << test << std::endl;
    std::system(testBinary.string().c_str());
    std::cout << "Test Complete!"sv << std::endl;
    std::cout << c_Delim << '\n' << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc > 1) [[unlikely]]
    {
        std::cerr << "Do not provide command line args!"sv << std::endl;
        return EXIT_FAILURE;
    }

    if (argc != 1) [[unlikely]]
    {
        std::cerr << "Execution Failure!"sv << std::endl;
        return EXIT_FAILURE;
    }

    constexpr auto tests = std::array<const std::string_view, 3>{
        "Format"sv,
        "HelloWorld"sv,
        "Modules"sv };

    auto tester = Tester{ *argv,  tests };
    tester.run();

    std::cout << "Exit: ";
    std::cin.get();

    return EXIT_SUCCESS;
}
