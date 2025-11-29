#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    std::cout << BOLD << CYAN << "=== Testing AForm and Execution ===" << RESET << std::endl << std::endl;

    // Test 1: ShrubberyCreationForm - Successful execution
    std::cout << YELLOW << "Test 1: ShrubberyCreationForm - Successful Execution" << RESET << std::endl;
    try {
        Bureaucrat alice("Alice", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << "Form: " << shrub << std::endl;
        std::cout << "Bureaucrat: " << alice << std::endl;
        
        alice.signForm(shrub);
        alice.executeForm(shrub);
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Execute unsigned form
    std::cout << YELLOW << "Test 2: Execute Unsigned Form (Should Fail)" << RESET << std::endl;
    try {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub2("garden");
        
        std::cout << "Attempting to execute unsigned form..." << std::endl;
        bob.executeForm(shrub2); // Should fail - not signed
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Execute with insufficient grade
    std::cout << YELLOW << "Test 3: Execute with Insufficient Grade (Should Fail)" << RESET << std::endl;
    try {
        Bureaucrat charlie("Charlie", 130);
        Bureaucrat dave("Dave", 150);
        ShrubberyCreationForm shrub3("office");
        
        charlie.signForm(shrub3);
        std::cout << "Attempting execution with insufficient grade..." << std::endl;
        dave.executeForm(shrub3); // Should fail - grade too low (need 137 to execute)
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 4: RobotomyRequestForm tests
    std::cout << YELLOW << "Test 4: RobotomyRequestForm Tests" << RESET << std::endl;
    try {
        Bureaucrat eve("Eve", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << "Form: " << robot << std::endl;
        std::cout << "Bureaucrat: " << eve << std::endl;
        
        eve.signForm(robot);
        eve.executeForm(robot);
        std::cout << std::endl;
        
        // Try multiple executions to see randomness
        std::cout << "Executing again to test 50% success rate:" << std::endl;
        eve.executeForm(robot);
        std::cout << "One more time:" << std::endl;
        eve.executeForm(robot);
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 5: PresidentialPardonForm tests
    std::cout << YELLOW << "Test 5: PresidentialPardonForm Tests" << RESET << std::endl;
    try {
        Bureaucrat lowLevel("LowLevel", 50);
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << "Form: " << pardon << std::endl;
        std::cout << "Low level bureaucrat: " << lowLevel << std::endl;
        
        // Low level can't sign (needs grade 25 or better)
        std::cout << "Low level bureaucrat tries to sign:" << std::endl;
        lowLevel.signForm(pardon);
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon2("Whistleblower");
        
        std::cout << "President: " << president << std::endl;
        std::cout << "Form: " << pardon2 << std::endl;
        
        // President can sign and execute
        std::cout << "President tries to sign and execute:" << std::endl;
        president.signForm(pardon2);
        president.executeForm(pardon2);
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Edge cases - exact grade matches
    std::cout << YELLOW << "Test 6: Edge Cases - Exact Grade Matches" << RESET << std::endl;
    try {
        // ShrubberyCreationForm requires 145 to sign, 137 to execute
        Bureaucrat signer("Signer", 145);     // Exactly can sign
        Bureaucrat executor("Executor", 137); // Exactly can execute
        ShrubberyCreationForm shrub4("exact_match");
        
        std::cout << "Testing exact grade requirements:" << std::endl;
        std::cout << "Signer (grade 145): " << signer << std::endl;
        std::cout << "Executor (grade 137): " << executor << std::endl;
        std::cout << "Form: " << shrub4 << std::endl;
        
        signer.signForm(shrub4);
        executor.executeForm(shrub4);
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 7: All forms with high-level bureaucrat
    std::cout << YELLOW << "Test 7: High-Level Bureaucrat Handles All Forms" << RESET << std::endl;
    try {
        Bureaucrat superman("Superman", 1); // Can do everything
        
        ShrubberyCreationForm shrub5("superman_garden");
        RobotomyRequestForm robot2("C3PO");
        PresidentialPardonForm pardon3("Prisoner");
        
        std::cout << "Superman (grade 1) handling all form types:" << std::endl;
        std::cout << "Bureaucrat: " << superman << std::endl;
        std::cout << std::endl;
        
        std::cout << "=== Shrubbery Form ===" << std::endl;
        std::cout << shrub5 << std::endl;
        superman.signForm(shrub5);
        superman.executeForm(shrub5);
        std::cout << std::endl;
        
        std::cout << "=== Robotomy Form ===" << std::endl;
        std::cout << robot2 << std::endl;
        superman.signForm(robot2);
        superman.executeForm(robot2);
        std::cout << std::endl;
        
        std::cout << "=== Presidential Pardon Form ===" << std::endl;
        std::cout << pardon3 << std::endl;
        superman.signForm(pardon3);
        superman.executeForm(pardon3);
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 8: Grade boundary failures
    std::cout << YELLOW << "Test 8: Grade Boundary Failures" << RESET << std::endl;
    try {
        // Test signing failures
        Bureaucrat weakSigner("WeakSigner", 146); // One grade too low for Shrubbery (needs 145)
        ShrubberyCreationForm shrub6("boundary_test");
        
        std::cout << "Testing sign boundary (needs 145, has 146):" << std::endl;
        std::cout << "Bureaucrat: " << weakSigner << std::endl;
        std::cout << "Form: " << shrub6 << std::endl;
        weakSigner.signForm(shrub6);
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    
    try {
        // Test execution failures
        Bureaucrat weakExecutor("WeakExecutor", 138); // One grade too low for execution (needs 137)
        Bureaucrat goodSigner("GoodSigner", 130);
        ShrubberyCreationForm shrub7("exec_boundary_test");
        
        std::cout << "Testing execution boundary (needs 137, has 138):" << std::endl;
        goodSigner.signForm(shrub7);
        std::cout << "Weak executor: " << weakExecutor << std::endl;
        weakExecutor.executeForm(shrub7);
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BOLD << CYAN << "=== All Tests Complete ===" << RESET << std::endl;
    return 0;
}