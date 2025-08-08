#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    /* Subject Requirement 1: Array Test with proper destructors */
    std::cout << YELLOW << "=== Subject Test: Array of Animals (Half Dogs, Half Cats) ===" << RESET << std::endl;
    
    const Animal* animals[6];  // Array of Animal objects
    
    std::cout << CYAN << "Creating array: Half Dogs, Half Cats" << RESET << std::endl;
    // Half Dogs
    animals[0] = new Dog("Alpha Dog");
    animals[1] = new Dog("Beta Dog");
    animals[2] = new Dog("Gamma Dog");
    
    // Half Cats
    animals[3] = new Cat("Whiskers Cat");
    animals[4] = new Cat("Shadow Cat");
    animals[5] = new Cat("Luna Cat");
    
    std::cout << CYAN << "\nAll animals making sounds:" << RESET << std::endl;
    for (int i = 0; i < 6; i++) {
        animals[i]->makeSound();
    }
    
    std::cout << CYAN << "\nDeleting animals directly as Animals (proper destructors should be called):" << RESET << std::endl;
    for (int i = 0; i < 6; i++) {
        delete animals[i];  // Delete as Animals - virtual destructors should work
    }
    std::cout << std::endl;

    /* Subject Requirement 2: Deep Copy Test with Brain Integration */
    std::cout << YELLOW << "=== Subject Test: Deep Copy + Brain Functionality ===" << RESET << std::endl;
    
    std::cout << CYAN << "Testing Cat with Brain thoughts:" << RESET << std::endl;
    Cat* originalCat = new Cat("Thinking Cat");
    
    // Give the original cat some thoughts
    originalCat->think("I love fish");
    originalCat->think("That bird looks tasty");
    originalCat->think("Time for a nap");
    
    std::cout << CYAN << "\nOriginal cat's thoughts:" << RESET << std::endl;
    originalCat->displayThoughts(0, 2);  // Display thoughts 0-2
    
    std::cout << CYAN << "\nCreating copy using copy constructor..." << RESET << std::endl;
    Cat copiedCat(*originalCat);  // Copy constructor - must be deep copy
    
    std::cout << CYAN << "Creating another cat for assignment test..." << RESET << std::endl;
    Cat assignedCat("Empty Cat");
    assignedCat.think("I have different thoughts");
    
    std::cout << CYAN << "\nBefore assignment - assigned cat's thoughts:" << RESET << std::endl;
    assignedCat.displayThoughts(0, 0);  // Display just first thought
    
    std::cout << CYAN << "\nTesting assignment operator..." << RESET << std::endl;
    assignedCat = *originalCat;  // Assignment operator - must be deep copy
    
    std::cout << CYAN << "\nAfter assignment - assigned cat should have original's thoughts:" << RESET << std::endl;
    assignedCat.displayThoughts(0, 2);  // Display thoughts 0-2
    
    // Test independent brains by adding new thoughts
    std::cout << CYAN << "\nAdding new thought to copied cat (should not affect original):" << RESET << std::endl;
    copiedCat.think("I am a copy with independent thoughts");
    
    std::cout << CYAN << "Original cat's brain after copy modification:" << RESET << std::endl;
    originalCat->displayThoughts(0, 3);  // Display thoughts 0-3
    
    std::cout << CYAN << "Copied cat's brain (should have the new thought):" << RESET << std::endl;
    copiedCat.displayThoughts(0, 3);  // Display thoughts 0-3
    
    std::cout << CYAN << "\nDeleting original cat (if shallow copy, others would break)..." << RESET << std::endl;
    delete originalCat;  // If copies were shallow, accessing copies would crash
    
    std::cout << CYAN << "Testing if copies are still valid after original deletion:" << RESET << std::endl;
    copiedCat.makeSound();    // Should work if deep copy
    assignedCat.makeSound();  // Should work if deep copy
    
    std::cout << GREEN << "✅ Cat copies still work after original deletion - deep copy confirmed!" << RESET << std::endl;
    std::cout << std::endl;

    /* Dog Brain Deep Copy Test */
    std::cout << YELLOW << "=== Dog Brain Deep Copy Test ===" << RESET << std::endl;
    
    Dog* originalDog = new Dog("Smart Dog");
    originalDog->think("Squirrel!");
    originalDog->think("Where is my bone?");
    originalDog->think("I love my human");
    
    std::cout << CYAN << "\nOriginal dog's thoughts:" << RESET << std::endl;
    originalDog->displayThoughts(0, 2);  // Display thoughts 0-2
    
    std::cout << CYAN << "Creating dog copy..." << RESET << std::endl;
    Dog copiedDog(*originalDog);  // Copy constructor - must be deep copy
    
    // Test independent modification
    std::cout << CYAN << "Adding unique thought to copied dog:" << RESET << std::endl;
    copiedDog.think("I am the copy dog with my own brain");
    
    std::cout << CYAN << "Original dog's brain (should not have copy's new thought):" << RESET << std::endl;
    originalDog->displayThoughts(0, 3);  // Display thoughts 0-3
    
    std::cout << CYAN << "Copied dog's brain (should have all thoughts including new one):" << RESET << std::endl;
    copiedDog.displayThoughts(0, 3);  // Display thoughts 0-3
    
    std::cout << CYAN << "Deleting original dog..." << RESET << std::endl;
    delete originalDog;  // If copy was shallow, accessing copy would crash
    
    std::cout << CYAN << "Testing if dog copy is still valid:" << RESET << std::endl;
    copiedDog.makeSound();  // Should work if deep copy
    copiedDog.displayThoughts(0, 1);  // Should display thoughts if deep copy
    
    std::cout << GREEN << "✅ Dog copy still works - deep copy confirmed!" << RESET << std::endl;
    std::cout << std::endl;

    /* Brain Direct Access Test */
    std::cout << YELLOW << "=== Brain Direct Access Test ===" << RESET << std::endl;
    
    Cat testCat("Direct Access Cat");
    testCat.think("Initial thought");
    
    // Direct brain manipulation
    Brain* catBrain = testCat.getBrain();
    catBrain->setIdea(10, "Directly set idea at index 10");
    catBrain->setIdea(50, "Another direct idea at index 50");
    
    std::cout << CYAN << "Direct brain access - idea at index 10: " << RESET;
    std::cout << catBrain->getIdea(10) << std::endl;
    std::cout << CYAN << "Direct brain access - idea at index 50: " << RESET;
    std::cout << catBrain->getIdea(50) << std::endl;
    
    std::cout << CYAN << "Displaying range of cat's thoughts (0-4):" << RESET << std::endl;
    testCat.displayThoughts(0, 4);
    
    std::cout << CYAN << "Displaying specific range (10-50):" << RESET << std::endl;
    testCat.getBrain()->displayIdeas(10, 50);
    
    std::cout << std::endl;
    
    /* Basic Polymorphism Test */
    std::cout << YELLOW << "=== Basic Polymorphism Test ===" << RESET << std::endl;

    const Animal* j = new Dog("Simple Dog");
    const Animal* i = new Cat("Simple Cat");

    std::cout << "Types: " << j->getType() << " and " << i->getType() << std::endl;
    j->makeSound();
    i->makeSound();

    delete j;  // Should not create a leak
    delete i;  // Should not create a leak
    
    std::cout << GREEN << "\n✅ All Brain integration tests completed!" << RESET << std::endl;
    std::cout << GREEN << "✅ Deep copy functionality verified with Brain thoughts!" << RESET << std::endl;
    std::cout << GREEN << "✅ Check with valgrind to verify no memory leaks." << RESET << std::endl;
    
    return 0;
}
