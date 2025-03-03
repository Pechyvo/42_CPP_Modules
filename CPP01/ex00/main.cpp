#include "Zombie.hpp"

int main(){
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
#endif

    std::string zombies[] = {"Walker","Crawler","Ghoul","Biter","Rotter","Stalker","Lurker","Shambler","Wanderer","Creeper"};
    for (int i = 0; i < 10; i++) {
        std::cout << std::endl << YELLOW << "newZombie: " << zombies[i] << std::endl;
        Zombie *zombie = newZombie(zombies[i]);
        zombie->announce();
        delete zombie;
        std::cout << std::endl << YELLOW << "randomChump: " << zombies[i] << std::endl;
        randomChump(zombies[i]);
    }
    
    return 0;
}
