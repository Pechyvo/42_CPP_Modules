#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include "../Formatting.hpp"
#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

class RPN {
	private:
		std::stack<int> _stack;
		std::string _input;
		void execute();
	public:
		RPN();
		RPN(const std::string& input);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		class RPNCannotDivideException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: cannot divide by 0";
				}
		};
		class RPNInvalidOperatorException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: invalid operator";
				}
		};
		class RPNInsufficientOperandsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: too little amount of operands";
				}
		};
		class RPNInvalidTokenException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: invalid token";
				}
		};
		class RPNIncorrectStackSizeException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: incorrect amount of operands and operators";
				}
		};
};

#endif