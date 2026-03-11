#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP
#include "../Formatting.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
    public:
        Span();
        Span(unsigned int maxSize);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        template<typename Iterator>
        void addMultipleNumbers(Iterator begin, Iterator end);

        class SpanFullException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Span is already full, cannot add more numbers";
                }
        };
        class NoSpanException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Cannot calculate span: need at least 2 numbers";
                }
        };
};

template<typename Iterator>
void Span::addMultipleNumbers(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
        if (_numbers.size() >= _maxSize) {
            throw SpanFullException();
        }
        _numbers.push_back(*it);
    }
}

#endif