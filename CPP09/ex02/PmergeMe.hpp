#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "../Formatting.hpp"
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
	private:
		struct Pair {
			int small;
			int large;
		};

		std::vector<int> _input;
		std::vector<int> _sortedVector;
		std::deque<int> _sortedDeque;
		double _vectorTimeUs;
		double _dequeTimeUs;

		void parseArguments(int argc, char **argv);
		int parseOneNumber(const char *raw) const;
		bool isDuplicate(int value) const;

		std::vector<int> fordJohnsonVector(const std::vector<int> &src) const;
		std::deque<int> fordJohnsonDeque(const std::deque<int> &src) const;

		void mergeSortPairsVector(std::vector<Pair> &pairs) const;
		void mergePairsVector(std::vector<Pair> &left, std::vector<Pair> &right,
			std::vector<Pair> &out) const;

		void mergeSortPairsDeque(std::deque<Pair> &pairs) const;
		void mergePairsDeque(std::deque<Pair> &left, std::deque<Pair> &right,
			std::deque<Pair> &out) const;

		std::vector<int> buildJacobOrderVector(std::size_t size) const;

		void printSequence(const std::vector<int> &seq, const std::string &label) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		class PmergeMeBadArgumentsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: bad arguments";
				}
		};

		class PmergeMeInvalidNumberException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: invalid token (only positive integers are allowed)";
				}
		};

		class PmergeMeDuplicateValueException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: duplicate values are not allowed";
				}
		};

		void run(int argc, char **argv);
};

#endif