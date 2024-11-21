#include "Serializer.hpp"

int main(){

    Data originalData("test",6 );
    Data* originalPtr = &originalData;

    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(raw);

    if (deserializedPtr == originalPtr) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Original Data: id = " << originalPtr->get_id() << ", user = " << originalPtr->get_user() << std::endl;
        std::cout << "Deserialized Data: id = " << deserializedPtr->get_id() << ", user = " << deserializedPtr->get_user() << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
    
}