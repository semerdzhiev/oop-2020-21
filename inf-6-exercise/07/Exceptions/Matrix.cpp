#include "Matrix.h"

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

Matrix::Matrix(size_t n, size_t m)  
{
	//guarding if the allocation fails 
	try 
	{
		initialize(n, m);
	}
	catch (std::bad_alloc& e) 
	{
		//if bad_alloc caught, then cleaning everything
		if (matrix != nullptr)
			clean();

		//throwing the same exception again
		throw;
	}
}

void Matrix::initialize(size_t n, size_t m) 
{
	//standard allocation of matrix with n rows è m columns
	this->rows = n;
	this->cols = m;

	// all pointers are initialized with nullptr
	// it is necessary in case an exception is thrown
	matrix = new int* [this->rows] {nullptr};

	//allocating rows
	for (size_t i = 0; i < this->rows; i++)
		matrix[i] = new int[this->cols]{ 0 };

	//if exception is thrown we can't get here
}

Matrix::Matrix(const Matrix& other)
{
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other) 
{
	//self assignment check
	if (this != &other) 
	{
		//cleaning the old content
		clean();
		//copy the values from the other matrix
		copy(other);
	}

	return *this;
}

Matrix::Matrix(Matrix&& other) noexcept
	: matrix(other.matrix), rows(other.rows), cols(other.cols)
{
	other.matrix = nullptr;
	other.rows = 0;
	other.cols = 0;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	if (this != &other)
	{
		//cleaning the old content
		clean();

		this->matrix = other.matrix;
		this->rows = other.rows;
		this->cols = other.cols;

		other.matrix = nullptr;
		other.rows = 0;
		other.cols = 0;
	}

	return *this;
}

Matrix::~Matrix() 
{
	clean();
}

void Matrix::clean() 
{
	for (size_t i = 0; i < this->rows; i++)
		delete[] this->matrix[i];

	delete[] this->matrix;

	this->matrix = nullptr;
	this->rows = 0;
	this->cols = 0;
}

void Matrix::copy(const Matrix& other) 
{
	try 
	{
		initialize(other.getRows(), other.getCols());
	}
	catch (std::bad_alloc&)
	{
		if (matrix != nullptr)
			clean();

		throw;
	}

	for (size_t i = 0; i < this->rows; i++)
		for (size_t j = 0; j < this->cols; j++)
			matrix[i][j] = other.matrix[i][j];
}

//fills the matrix with random values
void Matrix::randomize() 
{
	for (size_t i = 0; i < this->rows; i++)
		for (size_t j = 0; j < this->cols; j++)
			matrix[i][j] = rand() % MAXVAL;
}

bool Matrix::isValid(size_t x, size_t y) const 
{
	return (x < rows&& y < cols);
}

void Matrix::print() const 
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cols; j++)
			std::cout << std::setw(6) << matrix[i][j];

		std::cout << std::endl;
	}
}

int Matrix::getRows() const {

	return rows;
}

int Matrix::getCols() const 
{
	return cols;
}

int& Matrix::getAt(size_t x, size_t y) 
{
	if (!isValid(x, y))
		throw std::out_of_range("The specified position can't be reached!");

	return matrix[x][y];
}

void Matrix::setAt(size_t x, size_t y, int val) 
{
	if (!isValid(x, y))
		throw std::out_of_range("The specified position can't be reached!");

	matrix[x][y] = val;
}

//we MUST return a copy, not reference, why?
Matrix Matrix::getTranspose() const 
{
	Matrix t(this->cols, this->rows);

	for (size_t i = 0; i < this->cols; i++)
		for (size_t j = 0; j < this->rows; j++)
			t.matrix[i][j] = this->matrix[j][i];

	// a copy is returned!
	return t;
}

Matrix Matrix::getMultipliedBy(const Matrix& other)const 
{
	if (this->cols != other.rows)
		throw std::logic_error("The two matrices can't be multiplied!");

	Matrix result(this->rows, other.cols);

	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < other.cols; j++)
		{
			for (size_t k = 0; k < cols; k++)
				result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
		}
	}

	return result;
}