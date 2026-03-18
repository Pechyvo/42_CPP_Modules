#include "RPN.hpp"

#ifdef DEBUG

void runTests(void) {
	struct TestCase {
		std::string input;
		bool shouldPass;
		std::string description;
	};

	TestCase tests[] = {
		{"3 4 +", true, "Simple addition"},
		{"5 2 -", true, "Simple subtraction"},
		{"3 4 *", true, "Simple multiplication"},
		{"8 2 /", true, "Simple division"},
		{"1 2 + 3 *", true, "Complex: (1 + 2) * 3 = 9"},
		{"5 1 2 + 4 * + 3 -", true, "Complex: 5 + (1 + 2) * 4 - 3 = 14"},
		{"5 0 /", false, "Division by zero"},
		{"5 +", false, "Too few operands"},
		{"1 2 3 +", false, "Too many operands"},
		{"1 a +", false, "Invalid token (letter)"},
	};

	int testCount = sizeof(tests) / sizeof(tests[0]);
	int passCount = 0;

	std::cout << B_CYAN << "╔═══════════════════════════════════════╗" << RESET << std::endl;
	std::cout << B_CYAN << "║   RPN Calculator Debug Tests          ║" << RESET << std::endl;
	std::cout << B_CYAN << "╚═══════════════════════════════════════╝" << RESET << std::endl << std::endl;

	for (int i = 0; i < testCount; i++) {
		std::cout << B_BLUE << "[" << (i + 1) << "/" << testCount << "]" << RESET << " " << CYAN << tests[i].description << RESET << std::endl;
		std::cout << "  Input:  " << YELLOW << tests[i].input << RESET << std::endl;
		
		try {
			RPN rpn(tests[i].input);
			if (tests[i].shouldPass) {
				std::cout << "  Result: " << B_GREEN << "✓ PASSED" << RESET << std::endl;
				passCount++;
			} else {
				std::cout << "  Result: " << B_RED << "✗ FAILED (expected exception)" << RESET << std::endl;
			}
		} catch (const std::exception& e) {
			if (!tests[i].shouldPass) {
				std::cout << "  Result: " << B_GREEN << "✓ PASSED (caught: " << I_YELLOW << "✗ " << e.what() << B_GREEN << ")" << RESET << std::endl;
				passCount++;
			} else {
				std::cout << "  Result: " << B_RED << "✗ FAILED (unexpected: " << I_YELLOW << e.what() << B_RED << ")" << RESET << std::endl;
			}
		}
		std::cout << std::endl;
	}

	std::cout << B_CYAN << "╔═══════════════════════════════════════╗" << RESET << std::endl;
	if (passCount == testCount) {
		std::cout << GREEN << "║ Results: " << passCount << "/" << testCount << " tests passed ✓            ║" << RESET << std::endl;
	} else {
		std::cout << RED << "║ Results: " << passCount << "/" << testCount << " tests passed ✗            ║" << RESET << std::endl;
	}
	std::cout << B_CYAN << "╚═══════════════════════════════════════╝" << RESET << std::endl;
}

#endif

int main(int argc, char **argv) {
#ifdef DEBUG
	if (argc == 1) {
		runTests();
		return 0;
	}
#endif

	if (argc != 2) {
		std::cerr << B_RED << "✗ Error: bad arguments" << RESET << std::endl;
		std::cerr << YELLOW << "Usage: " << RESET << "./RPN " << CYAN << "<expression>" << RESET << std::endl;
		std::cerr << std::endl << I_WHITE << "Examples:" << RESET << std::endl;
		std::cerr << "  ./RPN \"3 4 +\"" << std::endl;
		std::cerr << "  ./RPN \"5 1 2 + 4 * +\"" << std::endl;
		return 1;
	}

	try {
		std::cout << B_GREEN << "Result: " << RESET;
		RPN rpn(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << B_RED << "✗ " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
