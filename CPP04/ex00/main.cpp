#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    /* Default Tests */
    std::cout << YELLOW << "Default Tests" << RESET << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    std::cout << std::endl;

    /* Additional Tests */
    std::cout << YELLOW << "Additional Tests" << RESET << std::endl;

    const Animal* customAnim = new Animal("Something in the bushes");
    const Animal* customDog = new Dog("Doggy");
    const Animal* customCat = new Cat("Kitty");

    customAnim->makeSound();
    customCat->makeSound();
    customDog->makeSound();
    
    delete customAnim;
    delete customDog;
    delete customCat;
    
    /* Wrong Animal/Cat Tests - Demonstrating incorrect polymorphism */
    std::cout << YELLOW << "Wrong Animal/Cat Tests" << RESET << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();  // This is the key test case!
    
    std::cout << "Type: " << wrongMeta->getType() << std::endl;
    std::cout << "Type: " << wrongCat->getType() << std::endl;
    
    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();  // Will call WrongAnimal::makeSound()
    
    std::cout << "WrongCat through WrongAnimal pointer: ";
    wrongCat->makeSound();   // Will call WrongAnimal::makeSound() - WRONG behavior!
    
    // For comparison, direct WrongCat call:
    const WrongCat* directWrongCat = new WrongCat();
    std::cout << "Direct WrongCat call: ";
    directWrongCat->makeSound(); // Will call WrongCat::makeSound() - correct behavior
    
    delete wrongMeta;
    delete wrongCat;
    delete directWrongCat;
    
    return 0;
}
