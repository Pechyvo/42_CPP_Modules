#include "MutantStack.hpp"
#include <list>

int main() {
    std::cout << BOLD << CYAN << "=== Original test ===" << RESET << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << YELLOW << "Top: " << RESET << mstack.top() << std::endl;

    mstack.pop();

    std::cout << YELLOW << "Size: " << RESET << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << YELLOW << "Stack contents: " << RESET;
    while (it != ite)
    {
        std::cout << GREEN << *it << RESET << " ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);

    std::cout << "\n" << BOLD << PURPLE << "=== Additional tests ===" << RESET << std::endl;
    
    // Test 1: Empty stack behavior
    MutantStack<int> empty_stack;
    std::cout << YELLOW << "Empty stack size: " << RESET << GREEN << empty_stack.size() << RESET << std::endl;
    std::cout << YELLOW << "Empty stack is empty: " << RESET << GREEN << (empty_stack.empty() ? "true" : "false") << RESET << std::endl;
    
    // Test 2: Copy constructor
    MutantStack<int> copied_stack(mstack);
    std::cout << YELLOW << "Copied stack size: " << RESET << GREEN << copied_stack.size() << RESET << std::endl;
    std::cout << YELLOW << "Copied stack contents: " << RESET;
    for (MutantStack<int>::iterator it = copied_stack.begin(); it != copied_stack.end(); ++it) {
        std::cout << GREEN << *it << RESET << " ";
    }
    std::cout << std::endl;
    
    // Test 3: Assignment operator
    MutantStack<int> assigned_stack;
    assigned_stack = mstack;
    std::cout << YELLOW << "Assigned stack size: " << RESET << GREEN << assigned_stack.size() << RESET << std::endl;
    
    // Test 4: Const iterator test
    const MutantStack<int>& const_stack = mstack;
    std::cout << YELLOW << "Const iterator traversal: " << RESET;
    for (MutantStack<int>::const_iterator cit = const_stack.begin(); cit != const_stack.end(); ++cit) {
        std::cout << GREEN << *cit << RESET << " ";
    }
    std::cout << std::endl;
    
    // Test 5: String stack
    std::cout << "\n" << BOLD << BLUE << "=== String stack test ===" << RESET << std::endl;
    MutantStack<std::string> str_stack;
    str_stack.push("Hello");
    str_stack.push("World");
    str_stack.push("42");
    
    std::cout << YELLOW << "String stack contents: " << RESET;
    for (MutantStack<std::string>::iterator sit = str_stack.begin(); sit != str_stack.end(); ++sit) {
        std::cout << BLUE << *sit << RESET << " ";
    }
    std::cout << std::endl;
    
    // Test 6: Comparison with std::list (same output)
    std::cout << "\n" << BOLD << RED << "=== Comparison with std::list ===" << RESET << std::endl;
    std::cout << CYAN << "MutantStack output: " << RESET;
    MutantStack<int> test_stack;
    test_stack.push(42);
    test_stack.push(21);
    test_stack.push(84);
    
    for (MutantStack<int>::iterator it = test_stack.begin(); it != test_stack.end(); ++it) {
        std::cout << CYAN << *it << RESET << " ";
    }
    std::cout << std::endl;
    
    std::cout << PURPLE << "std::list output:   " << RESET;
    std::list<int> test_list;
    test_list.push_back(42);
    test_list.push_back(21);
    test_list.push_back(84);
    
    for (std::list<int>::iterator it = test_list.begin(); it != test_list.end(); ++it) {
        std::cout << PURPLE << *it << RESET << " ";
    }
    std::cout << std::endl;
    
    // Test 7: Iterator manipulation
    std::cout << "\n" << BOLD << GREEN << "=== Iterator manipulation ===" << RESET << std::endl;
    MutantStack<int> manip_stack;
    manip_stack.push(1);
    manip_stack.push(2);
    manip_stack.push(3);
    manip_stack.push(4);
    manip_stack.push(5);
    
    MutantStack<int>::iterator iter = manip_stack.begin();
    std::cout << YELLOW << "First element: " << RESET << GREEN << *iter << RESET << std::endl;
    ++iter;
    std::cout << YELLOW << "Second element: " << RESET << GREEN << *iter << RESET << std::endl;
    --iter;
    std::cout << YELLOW << "Back to first: " << RESET << GREEN << *iter << RESET << std::endl;
    
    // Modify through iterator
    *iter = 99;
    std::cout << YELLOW << "Modified stack: " << RESET;
    for (MutantStack<int>::iterator it = manip_stack.begin(); it != manip_stack.end(); ++it) {
        std::cout << GREEN << *it << RESET << " ";
    }
    std::cout << std::endl;

    return 0;
}
