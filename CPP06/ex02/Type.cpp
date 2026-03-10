#include "Type.hpp"

Base* Type::generate(void) {
    int random = rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << GREEN << "A class was created" << std::endl;
            return new A();
        case 1:
            std::cout << CYAN << "B class was created" << std::endl;
            return new B();
        default:
            std::cout << PURPLE << "C class was created" << std::endl;
            return new C();
    }
}

void Type::indentify(Base* p) {
    if (p == NULL) {
        std::cout << YELLOW << "Null pointer provided" << std::endl;
        return;
    }
    
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << GREEN << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << CYAN << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << PURPLE << "C" << std::endl;
    } else {
        std::cout << RED << "Unknown type" << std::endl;
    }
}

void Type::indentify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << GREEN << "A" << std::endl;
        return;
    } catch (const std::bad_cast& e) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << CYAN << "B" << std::endl;
        return;
    } catch (const std::bad_cast& e) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << PURPLE << "C" << std::endl;
        return;
    } catch (const std::bad_cast& e) {}
    
    std::cout << RED << "Unknown type" << std::endl;
}
