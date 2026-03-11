#pragma once
#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include "../Formatting.hpp"

template<typename T>
void swap(T& val1, T& val2) {
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template<typename T>
const T& min(const T& val1, const T& val2) {
    return (val1 < val2) ? val1 : val2;
}

template<typename T>
const T& max(const T& val1, const T& val2) {
    return (val1 > val2) ? val1 : val2;
}

#endif