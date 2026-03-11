#pragma once
#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <exception>

template<typename T>
Array<T>::Array() : _size(0), _elements(NULL) {
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    if (n == 0)
        _elements = NULL;
    else
        _elements = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& other) : _size(other._size) {
    if (_size == 0)
        _elements = NULL;
    else {
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _elements[i] = other._elements[i];
        }
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _elements;
        _size = other._size;
        if (_size == 0)
            _elements = NULL;
        else {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] _elements;
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= _size)
        throw std::exception();
    return _elements[i];
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const {
    if (i >= _size)
        throw std::exception();
    return _elements[i];
}

template<typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}

#endif