#include "ScalarConverter.hpp"
#include <climits>



std::string toString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

bool isvalid(std::string &input) {
    if (input.empty())
        return false;
    if (input == "+inff" || input == "-inff" || input == "+inf" || input == "-inf")
        return true;
    if (input.length() == 1) {
        if (!isdigit(input[0]))
            input = toString(input[0]);
        return true;
    }
    std::size_t pos = input.find(".");
    std::size_t i = (input[0] == '-' || input[0] == '+') ? 1 : 0;
    if (pos == std::string::npos) {
        for (; i < input.length(); i++)
            if (!isdigit(input[i]))
                return false;
    } else {
        for (; i < pos; i++)
            if (!isdigit(input[i]))
                return false;
        i++;
        for (; i < input.length(); i++)
            if (input[i] == 'f' && i == input.length() - 1)
                break;
            else if (!isdigit(input[i]))
                return false;
    }
    return true;
}

std::size_t get_after_dot_length(std::string &nbr) {
    std::size_t pos = nbr.find(".");
    if (pos == std::string::npos || (nbr.length() - pos - 1) == 0)
        return 1;
    else
        return (nbr.length() - pos - 1);
}

void print_char(const std::string &input) {
    
    long nbr = std::atol(input.c_str());
    if (nbr < 0 || nbr > 127)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(static_cast<unsigned char>(nbr)))
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    else 
        std::cout << "char: Non displayable" << std::endl;
}

void print_int(const std::string &input) {
    long nbr = std::atol(input.c_str());
    if (nbr > std::numeric_limits<int>::max())
         std::cout << "int: +inff" << std::endl;
    else if( nbr < std::numeric_limits<int>::min())
         std::cout << "int: -inff" << std::endl;
    else 
        std::cout << "int: " << static_cast<int>(nbr) << std::endl;
}

void print_float(std::string &input) {
    float floatValue = std::strtof(input.c_str(), NULL);
     if (floatValue == std::numeric_limits<float>::infinity() || floatValue == HUGE_VALF) 
        std::cout << "float: +inff" << std::endl;
     else if (floatValue == -std::numeric_limits<float>::infinity() || floatValue == -HUGE_VALF) 
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(get_after_dot_length(input)) << static_cast<float>(floatValue) << "f" << std::endl;

}

void print_double(std::string &input) {
    double doubleValue = std::strtod(input.c_str(), NULL);
    if (doubleValue == std::numeric_limits<double>::infinity() || doubleValue == HUGE_VAL) 
        std::cout << "double: +inf" << std::endl;
    else if (doubleValue == -std::numeric_limits<double>::infinity() || doubleValue == HUGE_VAL) 
        std::cout << "double: -inf" << std::endl;
     else 
        std::cout << "double: " << std::fixed << std::setprecision(get_after_dot_length(input)) << static_cast<double>(doubleValue) << std::endl;
    
}
void inff(std::string &input){
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if(input == "+inff" || input == "+inf")
        std::cout << "float: " << "+inff" << std::endl;
    else
        std::cout << "float: " << "-inff" << std::endl;
    if(input == "+inff" || input == "+inf")
        std::cout << "double: " << "+inf" << std::endl;
    else
        std::cout << "double: " << "-inf" << std::endl;
}
void print(std::string &input) {

    if (input == "+inff" || input == "-inff" || input == "+inf" || input == "-inf") {
        inff(input);
        return;
    }
    print_char(input);
    print_int(input);
    print_double(input);
    print_float(input);
    // inff(input);
}

void impossible() {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: nanf\n";
    std::cout << "double: nan\n";
}

void ScalarConverter::convert(std::string input) {
    if (!isvalid(input))
        impossible();
    else
        print(input);
}