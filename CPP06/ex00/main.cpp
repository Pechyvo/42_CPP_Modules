#include "ScalarConverter.hpp"

#ifdef DEBUG
void runTest(const std::string& testName, const std::string& input) {
    std::cout << BOLD << YELLOW << "\n=== Testing: " << testName << " (\"" << input << "\") ===" << RESET << std::endl;
    ScalarConverter::convert(input);
}
#endif

int main(int argc, char **argv) {
#ifdef DEBUG
    std::cout << PURPLE << "[DEBUG] is defined - Running comprehensive tests\n" << RESET << std::endl;
    
    (void)argc;
    (void)argv;
    
    // Test 1: Normal integer
    runTest("Normal integer", "42");
    
    // Test 2: Normal float
    runTest("Normal float", "42.5f");
    
    // Test 3: Normal double
    runTest("Normal double", "42.5");
    
    // Test 4: Negative number
    runTest("Negative number", "-42.7");
    
    // Test 5: Zero
    runTest("Zero", "0");
    
    // Test 6: Single character
    runTest("Single character 'a'", "a");
    
    // Test 7: Single character digit
    runTest("Single character '5'", "5");
    
    // Test 8: Special values - NaN
    runTest("NaN", "nan");
    
    // Test 9: Special values - NaNf
    runTest("NaNf", "nanf");
    
    // Test 10: Special values - Infinity
    runTest("Positive infinity", "+inf");
    
    // Test 11: Special values - Negative infinity
    runTest("Negative infinity", "-inf");
    
    // Test 12: Special values - Infinity float
    runTest("Infinity float", "inff");
    
    // Test 13: Large numbers
    runTest("Large number", "123456789.123456789");
    
    // Test 14: Small decimal
    runTest("Small decimal", "0.001");
    
    // Test 15: Scientific notation (should fail)
    runTest("Scientific notation (invalid)", "1.23e4");
    
    // Test 16: Invalid string
    runTest("Invalid string", "abc123");
    
    // Test 17: Mixed invalid
    runTest("Mixed invalid", "123abc");
    
    // Test 18: Empty string
    runTest("Empty string", "");
    
    // Test 19: Just 'f'
    runTest("Just 'f'", "f");
    
    // Test 20: Multiple dots
    runTest("Multiple dots (invalid)", "1.2.3");
    
    // Test 21: Edge case - very large float
    runTest("Very large float", "340282346638528859811704183484516925440.0f");
    
    // Test 22: Edge case - very small float
    runTest("Very small float", "1.175494e-38f");
    
    std::cout << BOLD << GREEN << "\n=== All tests completed ===" << RESET << std::endl;
    
#else
    if (argc != 2) {
        std::cerr << RED << "Usage: " << argv[0] << " <literal>" << RESET << std::endl;
        std::cerr << "Example: " << argv[0] << " \"42.5f\"" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
#endif
    return 0;
}