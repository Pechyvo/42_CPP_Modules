#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);

    return intPtr;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* ptr = reinterpret_cast<Data*>(raw);

    return ptr;
}