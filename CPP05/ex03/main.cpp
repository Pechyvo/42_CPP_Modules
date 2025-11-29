#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    std::cout << BOLD << CYAN << "=== Testing Intern and Form Creation ===" << RESET << std::endl << std::endl;

    // Test 1: Intern creates all form types successfully
    std::cout << YELLOW << "Test 1: Intern Creates All Form Types" << RESET << std::endl;
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        
        std::cout << "Creating forms through Intern:" << std::endl;
        
        // Create ShrubberyCreationForm
        AForm* shrub = intern.makeForm("shrubbery creation", "garden");
        if (shrub) {
            std::cout << "Created: " << *shrub << std::endl;
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
            delete shrub;
        }
        std::cout << std::endl;
        
        // Create RobotomyRequestForm  
        AForm* robot = intern.makeForm("robotomy request", "Bender");
        if (robot) {
            std::cout << "Created: " << *robot << std::endl;
            boss.signForm(*robot);
            boss.executeForm(*robot);
            delete robot;
        }
        std::cout << std::endl;
        
        // Create PresidentialPardonForm
        AForm* pardon = intern.makeForm("presidential pardon", "Snowden");
        if (pardon) {
            std::cout << "Created: " << *pardon << std::endl;
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Invalid form name (should fail)
    std::cout << YELLOW << "Test 2: Invalid Form Name (Should Fail)" << RESET << std::endl;
    try {
        Intern intern;
        
        std::cout << "Attempting to create unknown form type..." << std::endl;
        AForm* invalidForm = intern.makeForm("invalid form", "target");
        
        if (invalidForm == NULL) {
            std::cout << GREEN << "Correctly returned NULL for invalid form" << RESET << std::endl;
        } else {
            std::cout << RED << "ERROR: Should have returned NULL!" << RESET << std::endl;
            delete invalidForm;
        }
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Case sensitivity and variations
    std::cout << YELLOW << "Test 3: Case Sensitivity and Variations" << RESET << std::endl;
    try {
        Intern intern;
        
        // Test different case variations
        std::cout << "Testing case variations:" << std::endl;
        
        AForm* form1 = intern.makeForm("SHRUBBERY CREATION", "test1");
        if (form1) {
            std::cout << GREEN << "Uppercase works: " << form1->getName() << RESET << std::endl;
            delete form1;
        } else {
            std::cout << RED << "Uppercase failed" << RESET << std::endl;
        }
        
        AForm* form2 = intern.makeForm("Robotomy Request", "test2");
        if (form2) {
            std::cout << GREEN << "Mixed case works: " << form2->getName() << RESET << std::endl;
            delete form2;
        } else {
            std::cout << RED << "Mixed case failed" << RESET << std::endl;
        }
        
        AForm* form3 = intern.makeForm("presidential pardon", "test3");
        if (form3) {
            std::cout << GREEN << "Lowercase works: " << form3->getName() << RESET << std::endl;
            delete form3;
        } else {
            std::cout << RED << "Lowercase failed" << RESET << std::endl;
        }
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Complete workflow with Intern-created forms
    std::cout << YELLOW << "Test 4: Complete Workflow with Different Bureaucrat Levels" << RESET << std::endl;
    try {
        Intern intern;
        Bureaucrat highLevel("HighLevel", 1);
        Bureaucrat midLevel("MidLevel", 50);
        Bureaucrat lowLevel("LowLevel", 140);
        
        // High level can handle all forms
        std::cout << "=== High Level Bureaucrat ===" << std::endl;
        AForm* presidentialForm = intern.makeForm("presidential pardon", "VIP");
        if (presidentialForm) {
            std::cout << highLevel << std::endl;
            std::cout << *presidentialForm << std::endl;
            highLevel.signForm(*presidentialForm);
            highLevel.executeForm(*presidentialForm);
            delete presidentialForm;
        }
        std::cout << std::endl;
        
        // Mid level can handle robotomy but not presidential
        std::cout << "=== Mid Level Bureaucrat ===" << std::endl;
        AForm* robotForm = intern.makeForm("robotomy request", "Android");
        if (robotForm) {
            std::cout << midLevel << std::endl;
            std::cout << *robotForm << std::endl;
            midLevel.signForm(*robotForm);
            midLevel.executeForm(*robotForm);
            delete robotForm;
        }
        std::cout << std::endl;
        
        // Low level can only handle shrubbery
        std::cout << "=== Low Level Bureaucrat ===" << std::endl;
        AForm* shrubForm = intern.makeForm("shrubbery creation", "backyard");
        if (shrubForm) {
            std::cout << lowLevel << std::endl;
            std::cout << *shrubForm << std::endl;
            lowLevel.signForm(*shrubForm);
            lowLevel.executeForm(*shrubForm);
            delete shrubForm;
        }
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Multiple forms creation and batch processing
    std::cout << YELLOW << "Test 5: Batch Form Creation and Processing" << RESET << std::endl;
    try {
        Intern intern;
        Bureaucrat superman("Superman", 1);
        
        // Create multiple forms
        AForm* forms[6];
        forms[0] = intern.makeForm("shrubbery creation", "park1");
        forms[1] = intern.makeForm("shrubbery creation", "park2"); 
        forms[2] = intern.makeForm("robotomy request", "Robot1");
        forms[3] = intern.makeForm("robotomy request", "Robot2");
        forms[4] = intern.makeForm("presidential pardon", "Person1");
        forms[5] = intern.makeForm("presidential pardon", "Person2");
        
        std::cout << "Batch processing " << sizeof(forms)/sizeof(forms[0]) << " forms:" << std::endl;
        
        for (int i = 0; i < 6; i++) {
            if (forms[i]) {
                std::cout << "Processing form " << (i+1) << ": " << forms[i]->getName() << std::endl;
                superman.signForm(*forms[i]);
                superman.executeForm(*forms[i]);
                delete forms[i];
                std::cout << std::endl;
            }
        }
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Edge cases and error conditions
    std::cout << YELLOW << "Test 6: Edge Cases and Error Conditions" << RESET << std::endl;
    try {
        Intern intern;
        
        // Empty form name
        std::cout << "Testing empty form name:" << std::endl;
        AForm* emptyForm = intern.makeForm("", "target");
        if (!emptyForm) {
            std::cout << GREEN << "Correctly rejected empty form name" << RESET << std::endl;
        }
        
        // Close but wrong form names
        std::cout << "Testing close but incorrect form names:" << std::endl;
        AForm* wrongForm1 = intern.makeForm("shrubbery", "target");
        AForm* wrongForm2 = intern.makeForm("robotomy", "target");
        AForm* wrongForm3 = intern.makeForm("pardon", "target");
        
        if (!wrongForm1 && !wrongForm2 && !wrongForm3) {
            std::cout << GREEN << "Correctly rejected partial form names" << RESET << std::endl;
        } else {
            std::cout << RED << "ERROR: Should reject partial form names!" << RESET << std::endl;
        }
        
    } catch (std::exception &e) {
        std::cerr << RED << "[Exception] " << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << BOLD << CYAN << "=== All Intern Tests Complete ===" << RESET << std::endl;
    return 0;
}