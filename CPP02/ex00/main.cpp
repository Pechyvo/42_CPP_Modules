#include "Fixed.hpp"

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
