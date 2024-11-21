#include"identify.hpp"
int absolut_random(void){
    unsigned int r_nbr;
    std::ifstream urandom("/dev/urandom", std::ios::in | std::ios::binary);
    // - std::ios::in: Opens the file for reading.
    // - std::ios::binary: Opens the file in binary mode.
    urandom.read(reinterpret_cast<char*>(&r_nbr), sizeof(r_nbr));
    srand(r_nbr);
    return rand();
}



Base * generate(void){
    int random_nbr ;
    random_nbr = absolut_random() % 3  ;
    if (random_nbr == 0) {
        std::cout << "randomly generate A" << std::endl;
        return new A;
    } else if (random_nbr == 1) {
        std::cout << "randomly generate B" << std::endl;
        return new B;
    } else {
        std::cout << "randomly generate C" << std::endl;
        return new C;
    }
}


void identify(Base* p){
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }    
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}
