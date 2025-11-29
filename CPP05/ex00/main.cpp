#include "Bureaucrat.hpp"

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    std::cout << BOLD << CYAN << "=== Testing Bureaucrat Class ===" << RESET << std::endl << std::endl;

    // Test 1: Valid constructors
    std::cout << YELLOW << "Test 1: Valid Constructors" << RESET << std::endl;
    try {
        Bureaucrat defaultBur;
        std::cout << "Default: " << defaultBur << std::endl;
        
        Bureaucrat alice("Alice", 1);
        std::cout << "Alice: " << alice << std::endl;
        
        Bureaucrat bob("Bob", 150);
        std::cout << "Bob: " << bob << std::endl;
        
        Bureaucrat charlie("Charlie", 75);
        std::cout << "Charlie: " << charlie << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Grade too high exception
    std::cout << YELLOW << "Test 2: Grade Too High Exception (grade 0)" << RESET << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << "This should not print!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Grade too low exception
    std::cout << YELLOW << "Test 3: Grade Too Low Exception (grade 151)" << RESET << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << "This should not print!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Copy constructor and assignment
    std::cout << YELLOW << "Test 4: Copy Constructor and Assignment" << RESET << std::endl;
    try {
        Bureaucrat original("Original", 50);
        std::cout << "Original: " << original << std::endl;
        
        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        Bureaucrat assigned("Assigned", 100);
        std::cout << "Before assignment: " << assigned << std::endl;
        assigned = original;
        std::cout << "After assignment: " << assigned << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Increment grade (valid)
    std::cout << YELLOW << "Test 5: Increment Grade (valid)" << RESET << std::endl;
    try {
        Bureaucrat dave("Dave", 5);
        std::cout << "Before increment: " << dave << std::endl;
        dave.incrementGrade(2);
        std::cout << "After increment by 2: " << dave << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Increment grade (exception)
    std::cout << YELLOW << "Test 6: Increment Grade Exception" << RESET << std::endl;
    try {
        Bureaucrat eve("Eve", 2);
        std::cout << "Before increment: " << eve << std::endl;
        eve.incrementGrade(5); // Should throw exception
        std::cout << "This should not print!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Decrement grade (valid)
    std::cout << YELLOW << "Test 7: Decrement Grade (valid)" << RESET << std::endl;
    try {
        Bureaucrat frank("Frank", 145);
        std::cout << "Before decrement: " << frank << std::endl;
        frank.decrementGrade(3);
        std::cout << "After decrement by 3: " << frank << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 8: Decrement grade (exception)
    std::cout << YELLOW << "Test 8: Decrement Grade Exception" << RESET << std::endl;
    try {
        Bureaucrat grace("Grace", 148);
        std::cout << "Before decrement: " << grace << std::endl;
        grace.decrementGrade(5); // Should throw exception
        std::cout << "This should not print!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 9: Getters
    std::cout << YELLOW << "Test 9: Getter Functions" << RESET << std::endl;
    try {
        Bureaucrat henry("Henry", 42);
        std::cout << "Name: " << henry.getName() << std::endl;
        std::cout << "Grade: " << henry.getGrade() << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BOLD << CYAN << "=== All Tests Complete ===" << RESET << std::endl;

    return 0;
}