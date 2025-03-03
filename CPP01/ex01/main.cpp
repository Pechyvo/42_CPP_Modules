#include "Zombie.hpp"
#ifdef DEBUG
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
#endif

int main() {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined" << std::endl << std::endl;
    srand(time(0));
#endif

    int N = 10;

#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] Creating a horde with random name" << std::endl;
    std::string zombies[] = {"Walker","Crawler","Ghoul","Biter","Rotter","Stalker","Lurker","Shambler","Wanderer","Creeper"};
    Zombie* horde = zombieHorde(N, zombies[getRandomNumber(0, 9)]);
#else
    Zombie* horde = zombieHorde(N, "Hoarder");
#endif
    if (!horde)
        return (std::cout << RED << "Error during allocation of the horde" << std::endl, 0);
    for (int i = 0; i < N; i++){
        horde[i].announce();
    }
    delete[] horde;

    return 0;
}
