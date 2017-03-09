#include <iostream>
#include <vector>
#include "matrix.h"
#include "exceptions.h"

int main()
{
	Matrix mat1(4, 2.0);
	Matrix mat2(4, 3.0);
	Matrix mat3;
	Matrix mat4(4);
	Matrix mat5(3);

	mat3 = { { 1,2,3 },{ 5,6,10 },{ 3,0,15 } };
	mat5 = { { 3,1,5 },{ 4,9,11 },{ 6,3,1 } };

	std::cout << mat3 << std::endl;
	std::cout << "Determinant: " << mat3.det() << std::endl;

	mat4 = mat1 + mat2;
	std::cout << "mat1 + mat2" << std::endl << mat4 << std::endl;

	mat3 /= 2;
	std::cout << "mat3/=2" << std::endl << mat3 << std::endl;

	mat3 *= mat5;
	std::cout << "mat3 *= mat5" << std::endl << mat3 << std::endl;

	mat3 -= 2;
	std::cout << "mat3 -= 2" << std::endl << mat3 << std::endl;

	std::cout << "mat3(2,1) " << mat3(2, 1) << std::endl;

	try
	{
		mat3 = { { 1,2 },{ 1,2,3 } };
	}
	catch (WrongDim) {}

	try
	{
		mat3 /= 0;
	}
	catch (DivByZero) {}

	try
	{
		mat5(1, 1) = 5;
	}
	catch (OutOfRange) {}

	return 0;
}