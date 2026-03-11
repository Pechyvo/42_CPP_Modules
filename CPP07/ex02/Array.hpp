#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "../Formatting.hpp"
#include <string>
#include <iostream>

template<typename T>
class Array {
    private:
        unsigned int _size;
        T* _elements;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;
        unsigned int size(void) const;
};

#include "Array.tpp"
#endif