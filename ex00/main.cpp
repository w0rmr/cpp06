#include "ScalarConverter.hpp"

int main(int ac , char **av)
{
    if(ac != 2)
        std::cout << "Usage : " << av[0] << " \"chi hja\"" << std::endl;
    else
        ScalarConverter::convert(av[1]); 
    return 0;
}
