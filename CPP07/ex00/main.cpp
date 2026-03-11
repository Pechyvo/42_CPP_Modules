#include "whatever.hpp"
#include <string>
#include <iostream>

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined - Running comprehensive tests\n" << RESET << std::endl;
    std::cout << CYAN << "=== Testing swap ===" << RESET << std::endl;
    int a = 2, b = 3;
    std::cout << "Before swap: " << YELLOW << "a = " << a << ", b = " << b << RESET << std::endl;
    ::swap(a, b);
    std::cout << "After swap:  " << GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
    
    std::cout << CYAN << "\n=== Testing min ===" << RESET << std::endl;
    std::cout << "min(2, 3) = " << GREEN << ::min(2, 3) << RESET << std::endl;
    std::cout << "min(3, 2) = " << GREEN << ::min(3, 2) << RESET << std::endl;
    std::cout << "min(5, 5) = " << GREEN << ::min(5, 5) << RESET << YELLOW << " (equal values)" << RESET << std::endl;
    
    std::cout << CYAN << "\n=== Testing max ===" << RESET << std::endl;
    std::cout << "max(2, 3) = " << GREEN << ::max(2, 3) << RESET << std::endl;
    std::cout << "max(3, 2) = " << GREEN << ::max(3, 2) << RESET << std::endl;
    std::cout << "max(5, 5) = " << GREEN << ::max(5, 5) << RESET << YELLOW << " (equal values)" << RESET << std::endl;
    
    std::cout << CYAN << "\n=== Testing with strings ===" << RESET << std::endl;
    std::string s1 = "hello";
    std::string s2 = "world";
    std::cout << "Before swap: " << YELLOW << "s1 = " << s1 << ", s2 = " << s2 << RESET << std::endl;
    ::swap(s1, s2);
    std::cout << "After swap:  " << GREEN << "s1 = " << s1 << ", s2 = " << s2 << RESET << std::endl;
    std::cout << "min(\"apple\", \"banana\") = " << GREEN << ::min(std::string("apple"), std::string("banana")) << RESET << std::endl;
    std::cout << "max(\"apple\", \"banana\") = " << GREEN << ::max(std::string("apple"), std::string("banana")) << RESET << std::endl;
    
    std::cout << CYAN << "\n=== Testing with floats ===" << RESET << std::endl;
    float f1 = 3.14f, f2 = 2.71f;
    std::cout << "min(" << f1 << ", " << f2 << ") = " << GREEN << ::min(f1, f2) << RESET << std::endl;
    std::cout << "max(" << f1 << ", " << f2 << ") = " << GREEN << ::max(f1, f2) << RESET << std::endl;
#else
    std::cout << BLUE << "Running evalsheet tests" << RESET << std::endl;
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << YELLOW << "a = " << a << ", b = " << b << RESET << std::endl;
    std::cout << "min( a, b ) = " << GREEN << ::min( a, b ) << RESET << std::endl;
    std::cout << "max( a, b ) = " << GREEN << ::max( a, b ) << RESET << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << YELLOW << "c = " << c << ", d = " << d << RESET << std::endl;
    std::cout << "min( c, d ) = " << GREEN << ::min( c, d ) << RESET << std::endl;
    std::cout << "max( c, d ) = " << GREEN << ::max( c, d ) << RESET << std::endl;
#endif
    return 0;
}