#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include "exceptions.h"

class Matrix {

	std::vector<std::vector<double> > values;
	size_t dimension;
	static int count;
	unsigned int i = 0;

public:
	//constructors of square matrices
	Matrix(size_t dim, const double& init); //creates matrix with dim rowes and columns and sets all values at init
	Matrix(size_t dim); //creates matrix with dim rowes and columns and sets all values at 0
	Matrix(); //creates matrix with 0 rowes and columns (dim changes after initializing with vector or another matrix)
			  //destructor
	~Matrix();

	//() overloading, gives access to specified field
	double& operator() (size_t& row, size_t& column);
	const double& operator() (size_t& row, size_t& column) const;
	double& operator()(unsigned int row, unsigned int column);
	const double& operator()(unsigned int row, unsigned int column) const;
	//= overloading, allows initializing matrix with a vector
	Matrix& operator= (const std::vector<std::vector<double> > vec);
	Matrix& operator= (const Matrix& mat);

	//arithmetic operators overloading for matrices
	Matrix operator+ (const Matrix& mat);
	Matrix operator- (const Matrix& mat);
	Matrix operator* (const Matrix& mat);

	Matrix& operator+= (const Matrix& mat);
	Matrix& operator-= (const Matrix& mat);
	Matrix& operator*= (const Matrix& mat);

	Matrix operator+ (const double& a);
	Matrix operator- (const double& a);
	Matrix operator* (const double& a);
	Matrix operator/ (const double& a);

	Matrix& operator+= (const double& a);
	Matrix& operator-= (const double& a);
	Matrix& operator*= (const double& a);
	Matrix& operator/= (const double& a);

	size_t getDim() const; //returns dimension of matrix
	Matrix getMinor(size_t row, size_t col); //returns specified minor of matrix
	double det(); //returns determinant of matrix

	friend std::ostream& operator<< (std::ostream &out, Matrix &mat); //<< overloading, allows Matrix objects to be arguments of ostream objects
};

//overloading operators for double as the left operand
Matrix operator+ (const double& a, const Matrix& mat);
Matrix operator- (const double& a, const Matrix& mat);
Matrix operator* (const double& a, const Matrix& mat);

#endif
