#include "Type.hpp"
#include <ctime>

int main() {
    srand(time(NULL));
    
    for (int i = 0; i < 10; ++i) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        Base* ptr = Type::generate();
        
        std::cout << "Pointer identification: ";
        Type::indentify(ptr);
        
        std::cout << "Reference identification: ";
        Type::indentify(*ptr);
        
        delete ptr;
        std::cout << std::endl;
    }
    
    return 0;
}
