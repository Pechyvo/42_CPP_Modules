#include "Type.hpp"

Base* Type::generate(void) {
    int random = rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << GREEN << "A class was created" << RESET << std::endl;
            return new A();
        case 1:
            std::cout << CYAN << "B class was created" << RESET << std::endl;
            return new B();
        default:
            std::cout << PURPLE << "C class was created" << RESET << std::endl;
            return new C();
    }
}

void Type::indentify(Base* p) {
    if (p == NULL) {
        std::cout << YELLOW << "Null pointer provided" << RESET << std::endl;
        return;
    }
    
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << GREEN << "A" << RESET << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << CYAN << "B" << RESET << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << PURPLE << "C" << RESET << std::endl;
    } else {
        std::cout << RED << "Unknown type" << RESET << std::endl;
    }
}

void Type::indentify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << GREEN << "A" << RESET << std::endl;
        return;
    } catch (const std::exception& e) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << CYAN << "B" << RESET << std::endl;
        return;
    } catch (const std::exception& e) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << PURPLE << "C" << RESET << std::endl;
        return;
    } catch (const std::exception& e) {}
    
    std::cout << RED << "Unknown type" << RESET << std::endl;
}
