#include "iter.hpp"
#include <string>

// Function that takes const reference
void printInt(const int& n) {
    std::cout << n << " ";
}

// Function that takes non-const reference (modifies elements)
void incrementInt(int& n) {
    n++;
}

// Function template
template <typename T>
void printElement(const T& element) {
    std::cout << "[" << element << "] ";
}

// Function with different return type
bool isPositive(const int& n) {
    return n > 0;
}

// Function that prints positivity check
void printPositivity(const int& n) {
    std::cout << n << (n > 0 ? " is positive" : (n < 0 ? " is negative" : " is zero")) << "; ";
}

// Function for strings
void printString(const std::string& str) {
    std::cout << "\"" << str << "\" ";
}

int main() {
    std::cout << BLUE << "=== Testing iter function template ===" << RESET << std::endl;
    
    // Test 1: Basic int array with const function
    std::cout << GREEN << "\nTest 1: Int array with const function" << RESET << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numbersSize = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "Original: ";
    iter(numbers, numbersSize, printInt);
    std::cout << std::endl;
    
    // Test 2: Non-const function (modifying elements)
    std::cout << GREEN << "\nTest 2: Modifying elements with non-const function" << RESET << std::endl;
    std::cout << "After increment: ";
    iter(numbers, numbersSize, incrementInt);
    iter(numbers, numbersSize, printInt);
    std::cout << std::endl;
    
    // Test 3: Function template instantiation
    std::cout << GREEN << "\nTest 3: Using function template" << RESET << std::endl;
    double doubles[] = {3.14, 2.71, 1.41};
    size_t doublesSize = sizeof(doubles) / sizeof(doubles[0]);
    std::cout << "Doubles: ";
    iter(doubles, doublesSize, printElement<double>);
    std::cout << std::endl;
    
    // Test 4: String array
    std::cout << GREEN << "\nTest 4: String array" << RESET << std::endl;
    std::string words[] = {"Hello", "World", "Template"};
    size_t wordsSize = sizeof(words) / sizeof(words[0]);
    std::cout << "Words: ";
    iter(words, wordsSize, printString);
    std::cout << std::endl;
    
    // Test 5: Const array
    std::cout << GREEN << "\nTest 5: Const array" << RESET << std::endl;
    const char chars[] = {'A', 'B', 'C', 'D'};
    size_t charsSize = sizeof(chars) / sizeof(chars[0]);
    std::cout << "Chars: ";
    iter(chars, charsSize, printElement<char>);
    std::cout << std::endl;
    
    // Test 6: Function with different return type
    std::cout << GREEN << "\nTest 6: Function with different return type" << RESET << std::endl;
    int mixed[] = {-2, -1, 0, 1, 2};
    size_t mixedSize = sizeof(mixed) / sizeof(mixed[0]);
    std::cout << "Testing positivity: ";
    iter(mixed, mixedSize, printPositivity); // Now we can see the results!
    std::cout << std::endl;
    
    std::cout << CYAN << "\n=== All tests completed successfully! ===" << RESET << std::endl;

    return 0;
}