#pragma once 
#include <string>
#include <iostream>
class Data{
    private:
        std::string user;
        int id ;
    public:
        Data();
        Data(std::string user , int id);
        std::string &get_user();
        int get_id();
        Data(const Data &ref);
        Data &operator=(const Data &data);
        ~Data();
};