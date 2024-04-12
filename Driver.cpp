#include <cstdlib>

#include <iostream>
#include <filesystem>
#include <string_view>
#include <vector>
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
    testBinary /= test;
    testBinary /= test;

    std::cout << '\n' << c_Delim << std::endl;
    std::cout << "Running Test: "sv << test << std::endl;
    std::system(testBinary.c_str());
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

    constexpr auto tests = std::array<std::string_view, 2>{
        "HelloWorld"sv,
        "Modules"sv };

    auto tester = Tester{ *argv,  tests };
    tester.run();

    return EXIT_SUCCESS;
}