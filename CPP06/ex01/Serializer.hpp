#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include "../Formatting.hpp"
#include "Data.hpp"
#include <stdint.h>

class Serializer {
    private:
        Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif