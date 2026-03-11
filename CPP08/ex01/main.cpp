#include "Span.hpp"
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void printSeparator(const std::string& testName) {
    std::cout << "\n" << YELLOW << "════════════════════════════════════" << RESET << std::endl;
    std::cout << BLUE << "    " << testName << RESET << std::endl;
    std::cout << YELLOW << "════════════════════════════════════" << RESET << std::endl;
}

void testBasicEvalSheet() {
    printSeparator("EVAL SHEET TEST");
    
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << PURPLE << "Numbers added: " << CYAN << "6, 3, 17, 9, 11" << RESET << std::endl;
    std::cout << PURPLE << "Shortest span: " << GREEN << sp.shortestSpan() << RESET << std::endl;
    std::cout << PURPLE << "Longest span: " << GREEN << sp.longestSpan() << RESET << std::endl;
}

void testExceptions() {
    printSeparator("EXCEPTION TESTS");
    
    // Test NoSpanException with empty container
    try {
        Span sp(5);
        sp.shortestSpan();
        std::cout << RED << "ERROR: Should have thrown NoSpanException" << RESET << std::endl;
    } catch (const Span::NoSpanException& e) {
        std::cout << GREEN << "✓ NoSpanException (empty): " << e.what() << RESET << std::endl;
    }
    
    // Test NoSpanException with single element
    try {
        Span sp(5);
        sp.addNumber(42);
        sp.longestSpan();
        std::cout << RED << "ERROR: Should have thrown NoSpanException" << RESET << std::endl;
    } catch (const Span::NoSpanException& e) {
        std::cout << GREEN << "✓ NoSpanException (single element): " << e.what() << RESET << std::endl;
    }
    
    // Test SpanFullException
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // This should throw
        std::cout << RED << "ERROR: Should have thrown SpanFullException" << RESET << std::endl;
    } catch (const Span::SpanFullException& e) {
        std::cout << GREEN << "✓ SpanFullException: " << e.what() << RESET << std::endl;
    }
}

void testIteratorBasedAddition() {
    printSeparator("ITERATOR-BASED ADDITION TESTS");
    
    // Test with vector
    Span sp(10);
    std::vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    vec.push_back(150);
    vec.push_back(250);
    
    try {
        sp.addMultipleNumbers(vec.begin(), vec.end());
        std::cout << GREEN << "✓ Vector iterator addition successful" << RESET << std::endl;
        std::cout << PURPLE << "  Numbers: " << CYAN << "100, 200, 300, 150, 250" << RESET << std::endl;
        std::cout << PURPLE << "  Shortest span: " << YELLOW << sp.shortestSpan() << RESET << std::endl;
        std::cout << PURPLE << "  Longest span: " << YELLOW << sp.longestSpan() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
    }
    
    // Test with array
    Span sp2(5);
    int arr[] = {5, 1, 9, 3, 7};
    
    try {
        sp2.addMultipleNumbers(arr, arr + 5);
        std::cout << GREEN << "✓ Array iterator addition successful" << RESET << std::endl;
        std::cout << PURPLE << "  Numbers: " << CYAN << "5, 1, 9, 3, 7" << RESET << std::endl;
        std::cout << PURPLE << "  Shortest span: " << YELLOW << sp2.shortestSpan() << RESET << std::endl;
        std::cout << PURPLE << "  Longest span: " << YELLOW << sp2.longestSpan() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
    }
    
    // Test with list
    Span sp3(4);
    std::list<int> lst;
    lst.push_back(50);
    lst.push_back(10);
    lst.push_back(30);
    lst.push_back(20);
    
    try {
        sp3.addMultipleNumbers(lst.begin(), lst.end());
        std::cout << GREEN << "✓ List iterator addition successful" << RESET << std::endl;
        std::cout << PURPLE << "  Numbers: " << CYAN << "50, 10, 30, 20" << RESET << std::endl;
        std::cout << PURPLE << "  Shortest span: " << YELLOW << sp3.shortestSpan() << RESET << std::endl;
        std::cout << PURPLE << "  Longest span: " << YELLOW << sp3.longestSpan() << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "ERROR: " << e.what() << RESET << std::endl;
    }
}

void testLargeDataset() {
    printSeparator("LARGE DATASET TEST (10,000+ numbers)");
    
    const unsigned int SIZE = 15000;
    Span sp(SIZE);
    
    // Generate random numbers using C++98 compatible method
    srand(static_cast<unsigned int>(time(0)));
    
    std::vector<int> numbers;
    numbers.reserve(SIZE);
    
    for (unsigned int i = 0; i < SIZE; ++i) {
        int random_num = (rand() % 100000) + 1; // Random number 1-100000
        numbers.push_back(random_num);
    }
    
    try {
        // Use iterator-based addition for efficiency
        sp.addMultipleNumbers(numbers.begin(), numbers.end());
        
        int shortest = sp.shortestSpan();
        int longest = sp.longestSpan();
        
        std::cout << GREEN << "✓ Large dataset test successful!" << RESET << std::endl;
        std::cout << PURPLE << "Dataset size: " << CYAN << SIZE << " numbers" << RESET << std::endl;
        std::cout << PURPLE << "Shortest span: " << YELLOW << shortest << RESET << std::endl;
        std::cout << PURPLE << "Longest span: " << YELLOW << longest << RESET << std::endl;
        std::cout << PURPLE << "Random generation: " << GREEN << "Successful" << RESET << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << RED << "ERROR in large dataset test: " << e.what() << RESET << std::endl;
    }
}

void testEdgeCases() {
    printSeparator("EDGE CASE TESTS");
    
    // Test with negative numbers
    Span sp1(4);
    sp1.addNumber(-10);
    sp1.addNumber(-5);
    sp1.addNumber(0);
    sp1.addNumber(5);
    
    std::cout << CYAN << "Negative numbers test:" << RESET << std::endl;
    std::cout << PURPLE << "  Numbers: " << YELLOW << "-10, -5, 0, 5" << RESET << std::endl;
    std::cout << PURPLE << "  Shortest span: " << GREEN << sp1.shortestSpan() << RESET << std::endl;
    std::cout << PURPLE << "  Longest span: " << GREEN << sp1.longestSpan() << RESET << std::endl;
    
    // Test with identical numbers
    Span sp2(3);
    sp2.addNumber(42);
    sp2.addNumber(42);
    sp2.addNumber(42);
    
    std::cout << CYAN << "Identical numbers test:" << RESET << std::endl;
    std::cout << PURPLE << "  Numbers: " << YELLOW << "42, 42, 42" << RESET << std::endl;
    std::cout << PURPLE << "  Shortest span: " << GREEN << sp2.shortestSpan() << RESET << std::endl;
    std::cout << PURPLE << "  Longest span: " << GREEN << sp2.longestSpan() << RESET << std::endl;
    
    // Test with two elements only
    Span sp3(2);
    sp3.addNumber(1000000);
    sp3.addNumber(-1000000);
    
    std::cout << CYAN << "Two elements (extreme values) test:" << RESET << std::endl;
    std::cout << PURPLE << "  Numbers: " << YELLOW << "1000000, -1000000" << RESET << std::endl;
    std::cout << PURPLE << "  Shortest span: " << GREEN << sp3.shortestSpan() << RESET << std::endl;
    std::cout << PURPLE << "  Longest span: " << GREEN << sp3.longestSpan() << RESET << std::endl;
}

void testIteratorExceptions() {
    printSeparator("ITERATOR EXCEPTION TESTS");
    
    // Test iterator addition overflow
    try {
        Span sp(3);
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5); // 5 elements, but span only holds 3
        sp.addMultipleNumbers(vec.begin(), vec.end());
        std::cout << RED << "ERROR: Should have thrown SpanFullException" << RESET << std::endl;
    } catch (const Span::SpanFullException& e) {
        std::cout << GREEN << "✓ Iterator SpanFullException: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << PURPLE << "╔══════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << PURPLE << "║" << CYAN << "  🧪 COMPREHENSIVE SPAN TESTING SUITE 🧪  " << PURPLE << "║" << RESET << std::endl;
    std::cout << PURPLE << "╚══════════════════════════════════════════╝" << RESET << std::endl;
    
    testBasicEvalSheet();
    testExceptions();
    testIteratorBasedAddition();
    testEdgeCases();
    testIteratorExceptions();
    testLargeDataset();
    
    std::cout << "\n" << PURPLE << "╔════════════════════════════════════╗" << RESET << std::endl;
    std::cout << PURPLE << "║" << GREEN << "  🎉 ALL TESTS COMPLETED! 🎉       " << PURPLE << "║" << RESET << std::endl;
    std::cout << PURPLE << "╚════════════════════════════════════╝" << RESET << std::endl;
    
    return 0;
}