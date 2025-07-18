#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 0)
        return NULL;
    
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] Creating a horde of " << U_PURPLE << N << PURPLE << " Unknown zombies " << std::endl;
#endif
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
#ifdef DEBUG
        std::cout << PURPLE << "[DEBUG] Zombie " << U_PURPLE << i << PURPLE << " is renamed to " << U_PURPLE << name << RESET << std::endl;
#endif
        horde[i] = Zombie(name);
    }
    return horde;
}
