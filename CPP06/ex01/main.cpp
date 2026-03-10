#include "Serializer.hpp"
#include <iostream>

int main() {
    // Test 1: Basic serialization
    Data* test = new Data(42);
    
    std::cout << test << " Original address of the data struct" << std::endl;
    uintptr_t testRaw = Serializer::serialize(test);
    std::cout << testRaw << " Serialized value of data ptr" << std::endl;
    Data* testCopy = Serializer::deserialize(testRaw);
    std::cout << testCopy << " Deserialized value of data ptr" << std::endl;
    
    if (test == testCopy)
        std::cout << "Success: addresses match!" << std::endl;
    else
        std::cout << "Error: addresses don't match!" << std::endl;
    
    delete test;
    
    std::cout << std::endl;
    
    // Test 2: Another simple test with different value
    Data* test2 = new Data(-100);
    
    std::cout << test2 << " Original address of second data struct" << std::endl;
    uintptr_t test2Raw = Serializer::serialize(test2);
    std::cout << test2Raw << " Serialized value of second data ptr" << std::endl;
    Data* test2Copy = Serializer::deserialize(test2Raw);
    std::cout << test2Copy << " Deserialized value of second data ptr" << std::endl;
    
    if (test2 == test2Copy)
        std::cout << "Success: addresses match!" << std::endl;
    else
        std::cout << "Error: addresses don't match!" << std::endl;
    
    delete test2;
    
    return 0;
}