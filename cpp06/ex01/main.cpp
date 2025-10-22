#include "Serializer.hpp"
#include <iostream>


int main()
{
    Data secret;
    secret.number = 333;
    secret.text = "Milan likes ****";

    std::cout << "Original pointer to data:\t\t\t" << &secret << std::endl;

    uintptr_t info = Serializer::serialize(&secret);

    std::cout << "Data pointer got serialized to:\t\t\t" << info << std::endl;
    
    Data *arrived = Serializer::deserialize(info);

    std::cout << "serialized Data gets deserialized back to:\t" << arrived << std::endl;

    std::cout << "\nReading the data after serialization and desirialization:" << std::endl;

    std::cout << "secret number: " << arrived->number << "\nsecret text: " << arrived->text << std::endl;
    return 0;
}