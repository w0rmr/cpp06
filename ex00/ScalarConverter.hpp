#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cerrno>
#include <cmath>
class ScalarConverter {
    private:
        ScalarConverter();
    public:
        static void convert(std::string input );
};