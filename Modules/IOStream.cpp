module;

#include <iostream>

export module IOStream;

export using std::operator<<;

export namespace std
{
    using std::cout;
    using std::endl;
}
