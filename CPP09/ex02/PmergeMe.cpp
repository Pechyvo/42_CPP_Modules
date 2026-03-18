#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: _vectorTimeUs(0.0), _dequeTimeUs(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _input(other._input),
	  _sortedVector(other._sortedVector),
	  _sortedDeque(other._sortedDeque),
	  _vectorTimeUs(other._vectorTimeUs),
	  _dequeTimeUs(other._dequeTimeUs) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_input = other._input;
		_sortedVector = other._sortedVector;
		_sortedDeque = other._sortedDeque;
		_vectorTimeUs = other._vectorTimeUs;
		_dequeTimeUs = other._dequeTimeUs;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parseOneNumber(const char *raw) const {
	if (!raw || *raw == '\0') {
		throw PmergeMeInvalidNumberException();
	}

	char *end = NULL;
	long value = std::strtol(raw, &end, 10);
	if (*end != '\0' || value <= 0 || value > INT_MAX) {
		throw PmergeMeInvalidNumberException();
	}
	return static_cast<int>(value);
}

bool PmergeMe::isDuplicate(int value) const {
	for (std::size_t i = 0; i < _input.size(); ++i) {
		if (_input[i] == value) {
			return true;
		}
	}
	return false;
}

void PmergeMe::parseArguments(int argc, char **argv) {
	if (argc < 2) {
		throw PmergeMeBadArgumentsException();
	}

	_input.clear();
	for (int i = 1; i < argc; ++i) {
		int value = parseOneNumber(argv[i]);
		if (isDuplicate(value)) {
			throw PmergeMeDuplicateValueException();
		}
		_input.push_back(value);
	}
}

void PmergeMe::mergePairsVector(std::vector<Pair> &left, std::vector<Pair> &right,
	std::vector<Pair> &out) const {
	out.clear();
	out.reserve(left.size() + right.size());

	std::size_t i = 0;
	std::size_t j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].large <= right[j].large) {
			out.push_back(left[i++]);
		} else {
			out.push_back(right[j++]);
		}
	}
	while (i < left.size()) {
		out.push_back(left[i++]);
	}
	while (j < right.size()) {
		out.push_back(right[j++]);
	}
}

void PmergeMe::mergeSortPairsVector(std::vector<Pair> &pairs) const {
	if (pairs.size() <= 1) {
		return;
	}

	std::size_t mid = pairs.size() / 2;
	std::vector<Pair> left(pairs.begin(), pairs.begin() + mid);
	std::vector<Pair> right(pairs.begin() + mid, pairs.end());

	mergeSortPairsVector(left);
	mergeSortPairsVector(right);
	mergePairsVector(left, right, pairs);
}

void PmergeMe::mergePairsDeque(std::deque<Pair> &left, std::deque<Pair> &right,
	std::deque<Pair> &out) const {
	out.clear();

	std::size_t i = 0;
	std::size_t j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].large <= right[j].large) {
			out.push_back(left[i++]);
		} else {
			out.push_back(right[j++]);
		}
	}
	while (i < left.size()) {
		out.push_back(left[i++]);
	}
	while (j < right.size()) {
		out.push_back(right[j++]);
	}
}

void PmergeMe::mergeSortPairsDeque(std::deque<Pair> &pairs) const {
	if (pairs.size() <= 1) {
		return;
	}

	std::size_t mid = pairs.size() / 2;
	std::deque<Pair> left(pairs.begin(), pairs.begin() + mid);
	std::deque<Pair> right(pairs.begin() + mid, pairs.end());

	mergeSortPairsDeque(left);
	mergeSortPairsDeque(right);
	mergePairsDeque(left, right, pairs);
}

std::vector<int> PmergeMe::buildJacobOrderVector(std::size_t size) const {
	std::vector<int> order;
	if (size == 0) {
		return order;
	}

	order.push_back(1);
	std::size_t prev = 1;
	std::size_t j0 = 1;
	std::size_t j1 = 1;

	while (true) {
		std::size_t jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;
		if (jn > size) {
			break;
		}
		for (std::size_t i = jn; i > prev; --i) {
			order.push_back(static_cast<int>(i));
		}
		prev = jn;
	}

	for (std::size_t i = size; i > prev; --i) {
		order.push_back(static_cast<int>(i));
	}

	return order;
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &src) const {
	if (src.size() <= 1) {
		return src;
	}

	std::vector<Pair> pairs;
	pairs.reserve(src.size() / 2);
	bool hasStraggler = (src.size() % 2 != 0);
	int straggler = 0;

	for (std::size_t i = 0; i + 1 < src.size(); i += 2) {
		Pair p;
		if (src[i] < src[i + 1]) {
			p.small = src[i];
			p.large = src[i + 1];
		} else {
			p.small = src[i + 1];
			p.large = src[i];
		}
		pairs.push_back(p);
	}

	if (hasStraggler) {
		straggler = src.back();
	}

	mergeSortPairsVector(pairs);

	std::vector<int> mainChain;
	mainChain.reserve(src.size());
	std::vector<int> pend;
	pend.reserve(pairs.size());

	mainChain.push_back(pairs[0].small);
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].large);
		if (i > 0) {
			pend.push_back(pairs[i].small);
		}
	}

	std::vector<int> order = buildJacobOrderVector(pend.size());
	for (std::size_t i = 0; i < order.size(); ++i) {
		int value = pend[order[i] - 1];
		std::vector<int>::iterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(pos, value);
	}

	if (hasStraggler) {
		std::vector<int>::iterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &src) const {
	if (src.size() <= 1) {
		return src;
	}

	std::deque<Pair> pairs;
	bool hasStraggler = (src.size() % 2 != 0);
	int straggler = 0;

	for (std::size_t i = 0; i + 1 < src.size(); i += 2) {
		Pair p;
		if (src[i] < src[i + 1]) {
			p.small = src[i];
			p.large = src[i + 1];
		} else {
			p.small = src[i + 1];
			p.large = src[i];
		}
		pairs.push_back(p);
	}

	if (hasStraggler) {
		straggler = src.back();
	}

	mergeSortPairsDeque(pairs);

	std::deque<int> mainChain;
	std::deque<int> pend;

	mainChain.push_back(pairs[0].small);
	for (std::size_t i = 0; i < pairs.size(); ++i) {
		mainChain.push_back(pairs[i].large);
		if (i > 0) {
			pend.push_back(pairs[i].small);
		}
	}

	std::vector<int> order = buildJacobOrderVector(pend.size());
	for (std::size_t i = 0; i < order.size(); ++i) {
		int value = pend[order[i] - 1];
		std::deque<int>::iterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(pos, value);
	}

	if (hasStraggler) {
		std::deque<int>::iterator pos = std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	return mainChain;
}

void PmergeMe::printSequence(const std::vector<int> &seq, const std::string &label) const {
	std::cout << label;
	for (std::size_t i = 0; i < seq.size(); ++i) {
		if (i > 0) {
			std::cout << ' ';
		}
		std::cout << seq[i];
	}
	std::cout << std::endl;
}

void PmergeMe::run(int argc, char **argv) {
	parseArguments(argc, argv);

	printSequence(_input, std::string(BI_YELLOW) + "Before:" + RESET + " ");

	clock_t startVec = std::clock();
	std::vector<int> vecData(_input.begin(), _input.end());
	_sortedVector = fordJohnsonVector(vecData);
	clock_t endVec = std::clock();
	_vectorTimeUs = static_cast<double>(endVec - startVec) * 1000000.0 / CLOCKS_PER_SEC;

	clock_t startDeq = std::clock();
	std::deque<int> deqData(_input.begin(), _input.end());
	_sortedDeque = fordJohnsonDeque(deqData);
	clock_t endDeq = std::clock();
	_dequeTimeUs = static_cast<double>(endDeq - startDeq) * 1000000.0 / CLOCKS_PER_SEC;

	printSequence(_sortedVector, std::string(BI_GREEN) + "After:" + RESET + " ");

	std::cout << std::fixed << std::setprecision(5);
	std::cout << BI_CYAN << "Time to process a range of " << _input.size()
		<< " elements with std::vector : " << _vectorTimeUs << " us" << RESET << std::endl;
	std::cout << BI_BLUE << "Time to process a range of " << _input.size()
		<< " elements with std::deque  : " << _dequeTimeUs << " us" << RESET << std::endl;
}
