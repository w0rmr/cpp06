#pragma once
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> 
#include <exception>
#include <iostream>
#include <string>
#include <fstream>
Base * generate(void);
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.