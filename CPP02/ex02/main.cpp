#include "Fixed.hpp"

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

#ifdef DEBUG
    std::cout << CYAN << "[DEBUG] Starting comprehensive Fixed class testing" << RESET << std::endl;
    
    // Test constructors
    std::cout << YELLOW << "\n=== Testing Constructors ===" << RESET << std::endl;
    Fixed a;                    // Default constructor
    Fixed b(42);               // Int constructor
    Fixed c(3.14f);            // Float constructor
    Fixed d(c);                // Copy constructor
    
    std::cout << "Default constructor: " << a << std::endl;
    std::cout << "Int constructor (42): " << b << std::endl;
    std::cout << "Float constructor (3.14f): " << c << std::endl;
    std::cout << "Copy constructor: " << d << std::endl;
    
    // Test assignment operator
    std::cout << YELLOW << "\n=== Testing Assignment Operator ===" << RESET << std::endl;
    Fixed e;
    e = b;
    std::cout << "Assignment (e = b): " << e << std::endl;
    
    // Test comparison operators
    std::cout << YELLOW << "\n=== Testing Comparison Operators ===" << RESET << std::endl;
    Fixed f(10);
    Fixed g(20);
    Fixed h(10);
    
    std::cout << "f = " << f << ", g = " << g << ", h = " << h << std::endl;
    std::cout << "f > g: " << (f > g) << std::endl;
    std::cout << "g > f: " << (g > f) << std::endl;
    std::cout << "f >= h: " << (f >= h) << std::endl;
    std::cout << "f < g: " << (f < g) << std::endl;
    std::cout << "g < f: " << (g < f) << std::endl;
    std::cout << "f <= h: " << (f <= h) << std::endl;
    std::cout << "f == h: " << (f == h) << std::endl;
    std::cout << "f != g: " << (f != g) << std::endl;
    
    // Test arithmetic operators
    std::cout << YELLOW << "\n=== Testing Arithmetic Operators ===" << RESET << std::endl;
    Fixed i(5);
    Fixed j(3);
    
    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << "i + j = " << (i + j) << std::endl;
    std::cout << "i - j = " << (i - j) << std::endl;
    std::cout << "i * j = " << (i * j) << std::endl;
    std::cout << "i / j = " << (i / j) << std::endl;
    
    // Test increment/decrement operators
    std::cout << YELLOW << "\n=== Testing Increment/Decrement Operators ===" << RESET << std::endl;
    Fixed k(10);
    std::cout << "k = " << k << std::endl;
    std::cout << "++k = " << ++k << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << "k++ = " << k++ << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << "--k = " << --k << std::endl;
    std::cout << "k = " << k << std::endl;
    std::cout << "k-- = " << k-- << std::endl;
    std::cout << "k = " << k << std::endl;
    
    // Test conversion functions
    std::cout << YELLOW << "\n=== Testing Conversion Functions ===" << RESET << std::endl;
    Fixed l(42.42f);
    std::cout << "l = " << l << std::endl;
    std::cout << "l.toInt() = " << l.toInt() << std::endl;
    std::cout << "l.toFloat() = " << l.toFloat() << std::endl;
    std::cout << "l.getRawBits() = " << l.getRawBits() << std::endl;
    
    // Test setRawBits
    Fixed m;
    m.setRawBits(1024);
    std::cout << "After setRawBits(1024): " << m << std::endl;
    
    // Test min/max functions
    std::cout << YELLOW << "\n=== Testing Min/Max Functions ===" << RESET << std::endl;
    Fixed n(15);
    Fixed o(25);
    
    std::cout << "n = " << n << ", o = " << o << std::endl;
    std::cout << "Fixed::min(n, o) = " << Fixed::min(n, o) << std::endl;
    std::cout << "Fixed::max(n, o) = " << Fixed::max(n, o) << std::endl;
    
    // Test const versions of min/max
    const Fixed p(8);
    const Fixed q(12);
    std::cout << "const p = " << p << ", const q = " << q << std::endl;
    std::cout << "Fixed::min(p, q) = " << Fixed::min(p, q) << std::endl;
    std::cout << "Fixed::max(p, q) = " << Fixed::max(p, q) << std::endl;
    
    // Test edge cases
    std::cout << YELLOW << "\n=== Testing Edge Cases ===" << RESET << std::endl;
    Fixed zero(0);
    Fixed negative(-5.5f);
    Fixed small(0.00390625f); // 1/256, should be exact
    
    std::cout << "Zero: " << zero << std::endl;
    std::cout << "Negative (-5.5f): " << negative << std::endl;
    std::cout << "Small (0.00390625f): " << small << std::endl;
    std::cout << "Zero + negative: " << (zero + negative) << std::endl;
    std::cout << "Negative * negative: " << (negative * negative) << std::endl;
    
    // Test zero division
    std::cout << YELLOW << "\n=== Testing Zero Division ===" << RESET << std::endl;
    Fixed dividend(10);
    Fixed divisor(0);
    
    std::cout << "Dividend: " << dividend << std::endl;
    std::cout << "Divisor: " << divisor << std::endl;
    std::cout << "Attempting division by zero..." << std::endl;
    try {
        Fixed result = dividend / divisor;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    } catch (...) {
        std::cout << RED << "Unknown exception caught during division by zero" << RESET << std::endl;
    }
    
    // Test chain operations
    std::cout << YELLOW << "\n=== Testing Chain Operations ===" << RESET << std::endl;
    Fixed r(2);
    Fixed s(3);
    Fixed t(4);
    
    std::cout << "r = " << r << ", s = " << s << ", t = " << t << std::endl;
    std::cout << "r + s * t = " << (r + s * t) << std::endl;
    std::cout << "(r + s) * t = " << ((r + s) * t) << std::endl;
    
#else
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
#endif

    return 0;
}
