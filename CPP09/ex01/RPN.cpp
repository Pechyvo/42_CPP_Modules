#include "RPN.hpp"

#include <cctype>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const std::string& input) : _input(input) {
	execute();
}

RPN::RPN(const RPN& other) : _stack(other._stack), _input(other._input) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
		_input = other._input;
	}

	return *this;
}

RPN::~RPN() {}

namespace {
	bool isOperator(const std::string& token) {
		return token.length() == 1
			&& (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
	}

	int applyOperation(int left, int right, char operation) {
		switch (operation) {
			case '+':
				return left + right;
			case '-':
				return left - right;
			case '*':
				return left * right;
			case '/':
				if (right == 0) {
					throw RPN::RPNCannotDivideException();
				}
				return left / right;
			default:
				throw RPN::RPNInvalidOperatorException();
		}
	}
}

void RPN::execute() {
	std::stringstream stream(this->_input);
	std::string token;

	while (stream >> token) {
		if (isOperator(token)) {
			if (this->_stack.size() < 2) {
				throw RPNInsufficientOperandsException();
			}

			int right = this->_stack.top();
			this->_stack.pop();
			int left = this->_stack.top();
			this->_stack.pop();

			this->_stack.push(applyOperation(left, right, token[0]));
			continue;
		}

		if (token.length() != 1 || !std::isdigit(static_cast<unsigned char>(token[0]))) {
			throw RPNInvalidTokenException();
		}

		this->_stack.push(token[0] - '0');
	}

	if (this->_stack.size() != 1) {
		throw RPNIncorrectStackSizeException();
	}

	std::cout << B_CYAN << this->_stack.top() << RESET << std::endl;
}
