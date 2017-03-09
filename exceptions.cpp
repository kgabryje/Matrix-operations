#include "exceptions.h"
#include <iostream>

WrongDim::WrongDim()
{
	std::cout << "Dimensions don't match" << std::endl;
}

OutOfRange::OutOfRange()
{
	std::cout << "Out of range" << std::endl;
}

DivByZero::DivByZero()
{
	std::cout << "Division by 0 not permitted" << std::endl;
}
