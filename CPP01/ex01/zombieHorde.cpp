#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    if (N <= 0)
        return NULL;
    
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] Creating a horde of " << N << " Unknown zombies " << std::endl;
#endif
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
#ifdef DEBUG
        std::cout << PURPLE << "[DEBUG] Zombie " << i << " is renamed to " << name << std::endl;
#endif
        horde[i] = Zombie(name);
    }
    return horde;
}
