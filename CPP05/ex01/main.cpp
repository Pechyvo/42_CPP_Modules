#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    std::cout << BOLD << CYAN << "=== Testing Form and Bureaucrat Signing ===" << RESET << std::endl << std::endl;

    // Test 1: Form constructors
    std::cout << YELLOW << "Test 1: Form Constructors" << RESET << std::endl;
    try {
        Form defaultForm;
        std::cout << "Default: " << defaultForm << std::endl;
        
        Form taxForm("Tax Form", 50, 25);
        std::cout << "Tax Form: " << taxForm << std::endl;
        
        Form easyForm("Easy Form", 150, 150);
        std::cout << "Easy Form: " << easyForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Form with invalid grades
    std::cout << YELLOW << "Test 2: Form Invalid Grades" << RESET << std::endl;
    try {
        Form invalidForm("Invalid Form", 0, 50); // Too high grade
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    
    try {
        Form invalidForm2("Invalid Form 2", 50, 151); // Too low grade
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Successful form signing
    std::cout << YELLOW << "Test 3: Successful Form Signing" << RESET << std::endl;
    try {
        Bureaucrat alice("Alice", 25);
        Form contract("Contract", 50, 30);
        
        std::cout << "Before signing: " << contract << std::endl;
        alice.signForm(contract);
        std::cout << "After signing: " << contract << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Failed form signing (grade too low)
    std::cout << YELLOW << "Test 4: Failed Form Signing (Grade Too Low)" << RESET << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form importantForm("Important Form", 25, 10);
        
        std::cout << "Before signing attempt: " << importantForm << std::endl;
        bob.signForm(importantForm);
        std::cout << "After signing attempt: " << importantForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Edge case - exact grade match
    std::cout << YELLOW << "Test 5: Edge Case - Exact Grade Match" << RESET << std::endl;
    try {
        Bureaucrat charlie("Charlie", 42);
        Form preciseForm("Precise Form", 42, 20);
        
        std::cout << "Bureaucrat: " << charlie << std::endl;
        std::cout << "Form: " << preciseForm << std::endl;
        charlie.signForm(preciseForm);
        std::cout << "Result: " << preciseForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Multiple bureaucrats, different outcomes
    std::cout << YELLOW << "Test 6: Multiple Bureaucrats, Different Outcomes" << RESET << std::endl;
    try {
        Form application("Application", 75, 50);
        Bureaucrat highRank("High Rank", 30);
        Bureaucrat midRank("Mid Rank", 75);
        Bureaucrat lowRank("Low Rank", 120);
        
        std::cout << "Form: " << application << std::endl;
        std::cout << std::endl;
        
        std::cout << "High rank bureaucrat attempts to sign:" << std::endl;
        highRank.signForm(application);
        std::cout << std::endl;
        
        // Reset form for next test (create new one)
        Form application2("Application Copy", 75, 50);
        std::cout << "Mid rank bureaucrat attempts to sign:" << std::endl;
        midRank.signForm(application2);
        std::cout << std::endl;
        
        Form application3("Application Copy 2", 75, 50);
        std::cout << "Low rank bureaucrat attempts to sign:" << std::endl;
        lowRank.signForm(application3);
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Copy constructor and assignment for forms
    std::cout << YELLOW << "Test 7: Form Copy Constructor and Assignment" << RESET << std::endl;
    try {
        Form original("Original", 60, 40);
        Bureaucrat signer("Signer", 50);
        
        signer.signForm(original);
        std::cout << "Original after signing: " << original << std::endl;
        
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        Form assigned("Assigned", 100, 80);
        std::cout << "Before assignment: " << assigned << std::endl;
        assigned = original;
        std::cout << "After assignment: " << assigned << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] Error: " << U_RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BOLD << CYAN << "=== All Tests Complete ===" << RESET << std::endl;

    return 0;
}