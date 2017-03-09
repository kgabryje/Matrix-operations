#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <cmath>

int Matrix::count = 0;
//constructors
Matrix::Matrix(size_t dim, const double& init) //creates matrix with dim rowes and columns and sets all values at init
{
	i = ++count;
	values.resize(dim);

	for (size_t i = 0; i < values.size(); i++)
		values[i].resize(dim, init);

	dimension = dim;
	std::cout << "Creating Matrix object no: " << i << std::endl;
}

Matrix::Matrix(size_t dim) //creates matrix with dim rowes and columns and sets all values at 0
{
	i = ++count;
	values.resize(dim);

	for (size_t i = 0; i < values.size(); i++)
		values[i].resize(dim, 0);

	dimension = dim;
	std::cout << "Creating Matrix object no: " << i << std::endl;
}

Matrix::Matrix() //creates matrix with 0 rowes and columns (dim changes after initializing with vector or another matrix)
{
	i = ++count;
	values.resize(0);

	for (size_t i = 0; i < values.size(); i++)
		values[i].resize(0);

	dimension = 0;
	std::cout << "Creating Matrix object no: " << i << std::endl;
}

//destructor
Matrix::~Matrix()
{
	std::cout << "Destroying Matrix object no: " << i << std::endl;
}

//() overload for accessing matrix elements
const double& Matrix::operator()(size_t& row, size_t& column) const
{
	if (row >= this->getDim() || column >= this->getDim())
		throw OutOfRange();

	return this->values[row][column];
}

double& Matrix::operator()(size_t& row, size_t& column)
{
	if (row >= 0)
		if (row >= this->getDim() || column >= this->getDim())
			throw OutOfRange();

	return this->values[row][column];
}

double& Matrix::operator()(unsigned int row, unsigned int column)
{
	if (row >= 0)
		if (row >= this->getDim() || column >= this->getDim())
			throw OutOfRange();

	return this->values[row][column];
}

const double& Matrix::operator()(unsigned int row, unsigned int column) const
{
	if (row >= 0)
		if (row >= this->getDim() || column >= this->getDim())
			throw OutOfRange();

	return this->values[row][column];
}

//= overload for filling the matrix with values
Matrix& Matrix::operator= (const std::vector<std::vector<double> > vec)
{
	if (this->getDim() == 0)
		this->dimension = vec.size();

	if (vec.size() != this->getDim())
		throw WrongDim();

	for (size_t i = 0; i < vec.size(); i++)
		if (vec[i].size() != this->getDim())
			throw WrongDim();

	this->values = vec;

	return *this;
}

Matrix& Matrix::operator= (const Matrix& mat)
{
	this->values = mat.values;
	return (*this);
}

//Matrix+Matrix overload
Matrix Matrix::operator+ (const Matrix& mat)
{
	if (this->getDim() != mat.getDim())
		throw WrongDim();

	Matrix result(this->getDim());

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			result(i, j) = this->values[i][j] + mat(i, j);

	return result;
}

//Matrix-Matrix overload
Matrix Matrix::operator- (const Matrix& mat)
{
	if (this->getDim() != mat.getDim())
		throw WrongDim();

	Matrix result(this->getDim());

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			result(i, j) = this->values[i][j] - mat(i, j);

	return result;
}

//Matrix*Matrix overload
Matrix Matrix::operator* (const Matrix& mat)
{
	if (this->getDim() != mat.getDim())
		throw WrongDim();

	Matrix result(this->getDim());

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			for (size_t k = 0; k < this->getDim(); k++)
				result(i, j) += this->values[i][k] * mat(k, j);

	return result;
}

//Matrix+=Matrix overload
Matrix& Matrix::operator+= (const Matrix& mat)
{
	if (this->getDim() != mat.getDim())
		throw WrongDim();

	for (size_t i = 0; i < mat.getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			this->values[i][j] += mat(i, j);

	return *this;
}

//Matrix-=Matrix overload
Matrix& Matrix::operator-= (const Matrix& mat)
{
	if (this->getDim() != mat.getDim())
		throw WrongDim();

	for (size_t i = 0; i < mat.getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			this->values[i][j] -= mat(i, j);

	return *this;
}
//Matrix*=Matrix overload, using previously overloaded * operator
Matrix& Matrix::operator*= (const Matrix& mat)
{
	if (this->getDim() != mat.getDim())
		throw WrongDim();

	(*this) = (*this) * mat;

	return *this;
}

//Matrix+scalar overload
Matrix Matrix::operator+ (const double& a)
{
	Matrix result(this->getDim());

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			result(i, j) = this->values[i][j] + a;

	return result;
}

//Matrix-scalar overload
Matrix Matrix::operator- (const double& a)
{
	Matrix result(this->getDim());

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			result(i, j) = this->values[i][j] - a;

	return result;
}

//Matrix*scalar overload
Matrix Matrix::operator*(const double& a)
{
	Matrix result(this->getDim());

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			result(i, j) = this->values[i][j] * a;

	return result;
}

//Matrix/scalar overload
Matrix Matrix::operator/ (const double& a)
{
	if (a == 0)
		throw DivByZero();

	Matrix result(this->getDim());

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			result(i, j) = this->values[i][j] / a;

	return result;
}

//Matrix += scalar
Matrix& Matrix::operator+= (const double& a)
{
	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			this->values[i][j] += a;

	return *this;
}

//Matrix -= scalar
Matrix& Matrix::operator-= (const double& a)
{
	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			this->values[i][j] -= a;

	return *this;
}

//Matrix *= scalar
Matrix& Matrix::operator*= (const double& a)
{
	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			this->values[i][j] *= a;

	return *this;
}

//Matrix /= scalar
Matrix& Matrix::operator/= (const double& a)
{
	if (a == 0)
		throw DivByZero();

	for (size_t i = 0; i < this->getDim(); i++)
		for (size_t j = 0; j < this->getDim(); j++)
			this->values[i][j] /= a;

	return *this;
}

// << overloading
std::ostream& operator<< (std::ostream& out, Matrix& mat)
{
	for (size_t i = 0; i < mat.getDim(); i++)
	{
		for (size_t j = 0; j < mat.getDim(); j++)
			out << mat(i, j) << " ";
		out << std::endl;
	}

	return out;
}

//returns dimension
size_t Matrix::getDim() const
{
	return this->dimension;
}

//return minor
Matrix Matrix::getMinor(size_t row, size_t col)
{
	if (row >= this->getDim() || col >= this->getDim())
		throw OutOfRange();

	Matrix min(this->getDim() - 1);
	size_t colCount = 0, rowCount = 0;

	for (size_t i = 0; i < this->getDim(); i++)
	{
		if (i != row)
		{
			colCount = 0;
			for (size_t j = 0; j < this->getDim(); j++)
			{
				if (j != col)
				{
					min(rowCount, colCount) = this->values[i][j];
					colCount++;
				}
			}
			rowCount++;
		}
	}

	return min;
}

//matrix determinant
double Matrix::det()
{
	double determ = 0.0;

	switch (this->getDim())
	{
	case 1:
		return this->values[0][0];

	case 2:
		determ = this->values[0][0] * this->values[1][1] - this->values[0][1] * this->values[1][0];

		return determ;

	default:
		for (size_t j = 0; j < this->getDim(); j++)
			determ += (this->values[0][j])*pow(-1, j)*(this->getMinor(0, j)).det();

		return determ;
	}
}

//scalar+Matrix
Matrix operator+ (const double& a, const Matrix& mat)
{
	Matrix result(mat.getDim());

	for (size_t i = 0; i < mat.getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			result(i, j) = mat(i, j) + a;

	return result;
}

//scalar-Matrix
Matrix operator- (const double& a, const Matrix& mat)
{
	Matrix result(mat.getDim());

	for (size_t i = 0; i < mat.getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			result(i, j) = mat(i, j) - a;

	return result;
}

//scalar*Matrix
Matrix operator* (const double& a, const Matrix& mat)
{
	Matrix result(mat.getDim());

	for (size_t i = 0; i < mat.getDim(); i++)
		for (size_t j = 0; j < mat.getDim(); j++)
			result(i, j) = mat(i, j) * a;

	return result;
}