import Regular;
import Partition;

int main()
{
    Regular::print();
    Implementation::print();
#if defined(__clang__) || defined(_MSC_VER)
    PMF::print();
#endif
    Partition::Interface::print();
    Partition::Implementation::print();
    return 0;
}
