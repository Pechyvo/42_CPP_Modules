#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
#ifdef DEBUG
    {
        Weapon sword = Weapon("sharp sword");
        HumanA alice("Alice", sword);
        alice.attack();
        sword.setType("dull sword");
        alice.attack();
    }
    {
        Weapon axe = Weapon("battle axe");
        HumanB charlie("Charlie");
        charlie.setWeapon(axe);
        charlie.attack();
        axe.setType("rusty axe");
        charlie.attack();
    }
    {
        Weapon spear = Weapon("long spear");
        HumanA dave("Dave", spear);
        dave.attack();
        spear.setType("short spear");
        dave.attack();
    }
    {
        Weapon bow = Weapon("longbow");
        HumanB eve("Eve");
        eve.setWeapon(bow);
        eve.attack();
        bow.setType("crossbow");
        eve.attack();
    }
#else
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
#endif

    return 0;
}
