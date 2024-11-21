#include"Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"
#include"identify.hpp"

int main() {
    try {
        Base* basePtr = generate();
        identify(basePtr);
        identify(*basePtr);

        delete basePtr;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}