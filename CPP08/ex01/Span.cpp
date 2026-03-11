#include "Span.hpp"

Span::Span() : _maxSize(0) {
}

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {
}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_numbers = other._numbers;
        this->_maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {
}

void Span::addNumber(int num) {
    if (this->_numbers.size() >= this->_maxSize) {
        throw SpanFullException();
    }
    this->_numbers.push_back(num);
}

int Span::shortestSpan() {
    if (this->_numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sorted_numbers = this->_numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    
    int min_span = std::numeric_limits<int>::max();
    
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        int current_span = sorted_numbers[i] - sorted_numbers[i - 1];
        if (current_span < min_span) {
            min_span = current_span;
        }
    }
    
    return min_span;
}

int Span::longestSpan() {
    if (this->_numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int>::iterator min_it = std::min_element(this->_numbers.begin(), this->_numbers.end());
    std::vector<int>::iterator max_it = std::max_element(this->_numbers.begin(), this->_numbers.end());
    
    return *max_it - *min_it;
}


