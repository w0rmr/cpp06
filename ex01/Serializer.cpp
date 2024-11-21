#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(const Serializer &ref){
    static_cast<void>(ref);
}
Serializer &Serializer::operator=(const Serializer &ser){
    static_cast<void>(ser);
    return *this;
}
uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);    
}
Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}