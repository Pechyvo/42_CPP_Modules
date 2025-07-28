#include "ClapTrap.hpp"

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    std::cout << B_YELLOW << "=== ClapTrap Tests ===" << RESET << std::endl;
    
    // Test ClapTrap constructors
    std::cout << B_CYAN << "Test 1: ClapTrap Constructors" << RESET << std::endl;
    ClapTrap defaultClap;
    ClapTrap namedClap("Clapper");
    std::cout << std::endl;

    // Test basic ClapTrap functionality
    std::cout << B_CYAN << "Test 2: ClapTrap Basic Combat" << RESET << std::endl;
    namedClap.attack("Enemy");     // 0 damage, 9 energy left
    namedClap.takeDamage(3);       // 7 HP left
    namedClap.beRepaired(2);       // 9 HP, 8 energy left
    std::cout << std::endl;

    // Test ClapTrap energy limits
    std::cout << B_CYAN << "Test 3: ClapTrap Energy Limits" << RESET << std::endl;
    namedClap.attack("Target1");   // 7 energy left
    namedClap.attack("Target2");   // 6 energy left
    namedClap.attack("Target3");   // 5 energy left
    namedClap.attack("Target4");   // 4 energy left
    namedClap.attack("Target5");   // 3 energy left
    namedClap.attack("Target6");   // 2 energy left
    namedClap.attack("Target7");   // 1 energy left
    namedClap.attack("Target8");   // 0 energy left
    namedClap.attack("Target9");   // Should show no energy message
    namedClap.beRepaired(1);       // Should show no energy message
    std::cout << std::endl;

    std::cout << B_GREEN << "=== All Tests Completed ===" << RESET << std::endl;

    return 0;
}
