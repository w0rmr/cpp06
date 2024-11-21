#include "Data.hpp"

Data::Data(){
    std::cout << "data :(" << std::endl;
}
Data::Data(std::string user , int id):user(user),id(id){
    std::cout << "data :(" << std::endl;
}

Data::~Data(){}
std::string &Data::get_user(){return user;}
int Data::get_id(){return id;}
Data::Data(const Data &ref) : user(ref.user), id(ref.id) {
}

Data &Data::operator=(const Data &data) {
    if (this != &data) {
        this->user = data.user;
        this->id = data.id;
    }
    return *this;
}