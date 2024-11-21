#pragma once
#include <iostream>
// #define unsigned long uintptr_t
#include<stdint.h>
#include "Data.hpp"
class Serializer{
    private:
    Serializer();
    Serializer(const Serializer &ref);
    Serializer &operator=(const Serializer &ser);
    Serializer(Serializer &ref);
    ~Serializer();
    public:

    static uintptr_t serialize(Data* ptr);
    // It takes a pointer and converts it to the unsigned integer type uintptr_t.
    static Data* deserialize(uintptr_t raw);
    // It takes an unsigned integer parameter and converts it to a pointer to Data.
};  