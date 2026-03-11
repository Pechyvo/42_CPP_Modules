#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

// Color definitions
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{
	std::cout << BOLD << CYAN << "=== Testing easyfind with std::vector ===" << RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(42);
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(42);

	try {
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << GREEN << "Found value " << YELLOW << "42" << GREEN << " at position: " << MAGENTA << std::distance(vec.begin(), it) << RESET << std::endl;
		std::cout << GREEN << "Value: " << YELLOW << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "  Testing non-existent value..." << RESET << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 999);
		std::cout << GREEN << "Found value " << YELLOW << "999" << GREEN << ": " << YELLOW << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BOLD << CYAN << "=== Testing easyfind with std::list ===" << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);

	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << GREEN << "Found value " << YELLOW << "20" << GREEN << " in list" << RESET << std::endl;
		std::cout << GREEN << "Value: " << YELLOW << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "  Testing non-existent value..." << RESET << std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 50);
		std::cout << GREEN << "Found value " << YELLOW << "50" << GREEN << ": " << YELLOW << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BOLD << CYAN << "=== Testing easyfind with std::deque ===" << RESET << std::endl;
	std::deque<int> deq;
	deq.push_back(5);
	deq.push_back(15);
	deq.push_back(25);

	try {
		std::deque<int>::iterator it = easyfind(deq, 15);
		std::cout << GREEN << "Found value " << YELLOW << "15" << GREEN << " at position: " << MAGENTA << std::distance(deq.begin(), it) << RESET << std::endl;
		std::cout << GREEN << "Value: " << YELLOW << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "  Testing non-existent value..." << RESET << std::endl;
	try {
		std::deque<int>::iterator it = easyfind(deq, 35);
		std::cout << GREEN << "Found value " << YELLOW << "35" << GREEN << ": " << YELLOW << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << "\n" << BOLD << CYAN << "=== Testing with empty container ===" << RESET << std::endl;
	std::vector<int> empty_vec;
	try {
		std::vector<int>::iterator it = easyfind(empty_vec, 1);
		std::cout << GREEN << "Found value " << YELLOW << "1" << GREEN << ": " << YELLOW << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	return 0;
}