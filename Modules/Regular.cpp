export module Regular;

import IOStream;

export class Regular
{
public:
    static void print() noexcept;

private:
};

void Regular::print() noexcept
{
    std::cout << "Hello Primary Module Interface Units!" << std::endl;
}

export class Implementation
{
public:
    static void print() noexcept;

private:
};

export class PMF
{
public:
    static void print() noexcept;

private:
};

#if defined(__clang__) || defined(_MSC_VER)
module : private;

void PMF::print() noexcept
{
    std::cout << "Hello Private Module Fragments!" << std::endl;
}
#endif
