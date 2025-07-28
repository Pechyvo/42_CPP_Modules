#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << B_YELLOW << "=== ScavTrap Tests ===" << RESET << std::endl;
    
    // Test ScavTrap constructors
    std::cout << B_CYAN << "Test 1: ScavTrap Constructors" << RESET << std::endl;
    ScavTrap defaultScav;
    ScavTrap namedScav("Scavenger");
    std::cout << std::endl;

    // Test ScavTrap enhanced stats
    std::cout << B_CYAN << "Test 2: ScavTrap Enhanced Combat" << RESET << std::endl;
    namedScav.attack("Enemy");  // Should do 20 damage instead of 2
    namedScav.takeDamage(30);   // Should have 100 HP, so 70 left
    namedScav.beRepaired(20);   // Should heal to 90
    namedScav.attack("Enemy2"); // Should still have energy (50 vs 5)
    std::cout << std::endl;

    // Test special ScavTrap method
    std::cout << B_CYAN << "Test 3: ScavTrap Special Ability" << RESET << std::endl;
    namedScav.guardGate();
    defaultScav.guardGate();
    std::cout << std::endl;

    // Test energy differences
    std::cout << B_CYAN << "Test 4: Energy Comparison" << RESET << std::endl;
    std::cout << YELLOW << "ClapTrap Clapper energy test:" << RESET << std::endl;
    namedClap.attack("Target1");  // Should be low/no energy
    std::cout << YELLOW << "ScavTrap Scavenger energy test:" << RESET << std::endl;
    for (int i = 0; i < 5; i++) {
        namedScav.attack("Multiple targets");  // Should have plenty of energy
    }
    std::cout << std::endl;

    // Test damage resistance
    std::cout << B_CYAN << "Test 5: Damage Resistance" << RESET << std::endl;
    ScavTrap tank("Tank");
    tank.takeDamage(50);  // Big hit, should survive with 50 HP
    tank.attack("Attacker");  // Should still be fighting
    tank.takeDamage(60);  // Should be destroyed
    tank.attack("PostMortem");  // Should show dead message
    tank.takeDamage(1);  // Should be already dead
    std::cout << std::endl;

    std::cout << B_YELLOW << "=== FragTrap Tests ===" << RESET << std::endl;
    
    // Test FragTrap constructors
    std::cout << B_CYAN << "Test 1: FragTrap Constructors" << RESET << std::endl;
    FragTrap defaultFrag;
    FragTrap namedFrag("Fragmenter");
    std::cout << std::endl;

    // Test FragTrap enhanced stats
    std::cout << B_CYAN << "Test 2: FragTrap Enhanced Combat" << RESET << std::endl;
    namedFrag.attack("Enemy");  // Should do 30 damage
    namedFrag.takeDamage(40);   // Should have 100 HP, so 60 left
    namedFrag.beRepaired(25);   // Should heal to 85
    namedFrag.attack("Enemy2"); // Should still have energy (100 vs 10)
    std::cout << std::endl;

    // Test special FragTrap method
    std::cout << B_CYAN << "Test 3: FragTrap Special Ability" << RESET << std::endl;
    namedFrag.highFivesGuys();
    defaultFrag.highFivesGuys();
    std::cout << std::endl;

    // Test FragTrap vs others comparison
    std::cout << B_CYAN << "Test 4: FragTrap vs Others" << RESET << std::endl;
    std::cout << YELLOW << "Energy comparison (ClapTrap: 10, ScavTrap: 50, FragTrap: 100):" << RESET << std::endl;
    FragTrap energyTest("EnergyTester");
    for (int i = 0; i < 8; i++) {
        energyTest.attack("Multiple targets");  // Should have massive energy
    }
    std::cout << std::endl;

    // Test FragTrap durability
    std::cout << B_CYAN << "Test 5: FragTrap Durability" << RESET << std::endl;
    FragTrap fortress("Fortress");
    fortress.takeDamage(80);  // Big hit, should survive with 20 HP
    fortress.attack("Attacker");  // Should still be fighting
    fortress.takeDamage(25);  // Should be destroyed
    fortress.attack("PostMortem");  // Should show dead message
    std::cout << std::endl;

    // Test all three classes destruction
    std::cout << B_CYAN << "Test 6: Destruction Order Demo" << RESET << std::endl;
    {
        std::cout << YELLOW << "Creating all three types:" << RESET << std::endl;
        ClapTrap clapDemo("ClapDemo");
        ScavTrap scavDemo("ScavDemo");
        FragTrap fragDemo("FragDemo");
        std::cout << YELLOW << "About to destroy all..." << RESET << std::endl;
    } // All destructors called here in reverse order
    std::cout << YELLOW << "All three have been destroyed!" << RESET << std::endl;
    std::cout << std::endl;

    std::cout << B_GREEN << "=== All Tests Completed ===" << RESET << std::endl;

    return 0;
}
