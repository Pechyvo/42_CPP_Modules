#include "Array.hpp"
#include <iostream>
#include <string>

void test_default_constructor() {
    std::cout << "\n" << BRIGHT_BLUE << "=== Testing Default Constructor ===" << RESET << "\n";
    Array<int> empty;
    std::cout << CYAN << "Empty array size: " << RESET << YELLOW << empty.size() << RESET << std::endl;
    
    try {
        std::cout << CYAN << "Accessing empty array[0]: " << RESET;
        std::cout << empty[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << BRIGHT_GREEN << "Exception caught (expected)" << RESET << std::endl;
    }
}

void test_parametrized_constructor() {
    std::cout << "\n" << BRIGHT_BLUE << "=== Testing Parametrized Constructor ===" << RESET << "\n";
    
    // Test the tip: int * a = new int(); then display *a
    int* a = new int();
    std::cout << CYAN << "new int() default value: " << RESET << YELLOW << *a << RESET << std::endl;
    delete a;
    
    Array<int> arr(5);
    std::cout << CYAN << "Array of size 5 created, size: " << RESET << YELLOW << arr.size() << RESET << std::endl;
    std::cout << CYAN << "Default initialized values: " << RESET;
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << YELLOW << arr[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // Test with strings
    Array<std::string> strArr(3);
    std::cout << CYAN << "String array default values: " << RESET;
    for (unsigned int i = 0; i < strArr.size(); i++) {
        std::cout << YELLOW << "\"" << strArr[i] << "\" " << RESET;
    }
    std::cout << std::endl;
}

void test_copy_constructor() {
    std::cout << "\n" << BRIGHT_BLUE << "=== Testing Copy Constructor ===" << RESET << "\n";
    
    Array<int> original(4);
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i * 10;
    }
    
    Array<int> copy(original);
    
    std::cout << CYAN << "Original: " << RESET;
    for (unsigned int i = 0; i < original.size(); i++) {
        std::cout << YELLOW << original[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    std::cout << CYAN << "Copy: " << RESET;
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << YELLOW << copy[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // Modify original to test deep copy
    original[0] = 999;
    std::cout << PURPLE << "After modifying original[0] to 999:" << RESET << "\n";
    std::cout << CYAN << "Original[0]: " << RESET << YELLOW << original[0] << RESET << std::endl;
    std::cout << CYAN << "Copy[0]: " << RESET << YELLOW << copy[0] << RESET << GREEN << " (should be unchanged)" << RESET << std::endl;
}

void test_assignment_operator() {
    std::cout << "\n" << BRIGHT_BLUE << "=== Testing Assignment Operator ===" << RESET << "\n";
    
    Array<int> arr1(3);
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i + 1;
    }
    
    Array<int> arr2(5);
    for (unsigned int i = 0; i < arr2.size(); i++) {
        arr2[i] = i * 2;
    }
    
    std::cout << PURPLE << "Before assignment:" << RESET << "\n";
    std::cout << CYAN << "arr1 size: " << RESET << YELLOW << arr1.size() << RESET << CYAN << ", values: " << RESET;
    for (unsigned int i = 0; i < arr1.size(); i++) {
        std::cout << YELLOW << arr1[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    std::cout << CYAN << "arr2 size: " << RESET << YELLOW << arr2.size() << RESET << CYAN << ", values: " << RESET;
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << YELLOW << arr2[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    arr2 = arr1;
    
    std::cout << PURPLE << "After arr2 = arr1:" << RESET << "\n";
    std::cout << CYAN << "arr2 size: " << RESET << YELLOW << arr2.size() << RESET << CYAN << ", values: " << RESET;
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << YELLOW << arr2[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // Test self-assignment
    Array<int>& ref = arr1;
    arr1 = ref;
    std::cout << BRIGHT_GREEN << "Self-assignment test passed" << RESET << std::endl;
}

void test_bounds_checking() {
    std::cout << "\n" << BRIGHT_BLUE << "=== Testing Bounds Checking ===" << RESET << "\n";
    
    Array<int> arr(3);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    std::cout << CYAN << "Valid access arr[1]: " << RESET << YELLOW << arr[1] << RESET << std::endl;
    
    try {
        std::cout << CYAN << "Invalid access arr[3]: " << RESET;
        std::cout << arr[3] << std::endl;
    } catch (const std::exception& e) {
        std::cout << BRIGHT_GREEN << "Exception caught (expected)" << RESET << std::endl;
    }
    
    try {
        std::cout << CYAN << "Invalid access arr[100]: " << RESET;
        std::cout << arr[100] << std::endl;
    } catch (const std::exception& e) {
        std::cout << BRIGHT_GREEN << "Exception caught (expected)" << RESET << std::endl;
    }
}

void test_const_array() {
    std::cout << "\n" << BRIGHT_BLUE << "=== Testing Const Array ===" << RESET << "\n";
    
    Array<int> arr(3);
    arr[0] = 42;
    arr[1] = 84;
    arr[2] = 126;
    
    const Array<int> constArr(arr);
    
    std::cout << CYAN << "Const array values: " << RESET;
    for (unsigned int i = 0; i < constArr.size(); i++) {
        std::cout << YELLOW << constArr[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    try {
        std::cout << CYAN << "Invalid const access constArr[5]: " << RESET;
        std::cout << constArr[5] << std::endl;
    } catch (const std::exception& e) {
        std::cout << BRIGHT_GREEN << "Exception caught (expected)" << RESET << std::endl;
    }
}

void test_different_types() {
    std::cout << "\n" << BRIGHT_BLUE << "=== Testing Different Types ===" << RESET << "\n";
    
    // Test with double
    Array<double> doubleArr(3);
    doubleArr[0] = 3.14;
    doubleArr[1] = 2.71;
    doubleArr[2] = 1.41;
    
    std::cout << CYAN << "Double array: " << RESET;
    for (unsigned int i = 0; i < doubleArr.size(); i++) {
        std::cout << YELLOW << doubleArr[i] << " " << RESET;
    }
    std::cout << std::endl;
    
    // Test with char
    Array<char> charArr(5);
    charArr[0] = 'H';
    charArr[1] = 'e';
    charArr[2] = 'l';
    charArr[3] = 'l';
    charArr[4] = 'o';
    
    std::cout << CYAN << "Char array: " << RESET << YELLOW;
    for (unsigned int i = 0; i < charArr.size(); i++) {
        std::cout << charArr[i];
    }
    std::cout << RESET << std::endl;
}

int main() {
    std::cout << BOLD << BRIGHT_BLUE << "\n🎯 === Array Class Template Tests ===" << RESET << std::endl;
    
    test_default_constructor();
    test_parametrized_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_bounds_checking();
    test_const_array();
    test_different_types();
    
    std::cout << "\n" << BOLD << BRIGHT_GREEN << "✅ === All tests completed ===" << RESET << std::endl;
    
    return 0;
}