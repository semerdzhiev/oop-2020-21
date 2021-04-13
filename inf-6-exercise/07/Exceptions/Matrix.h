#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

//used in randomize function
const int MAXVAL = 50;

class Matrix 
{
	public:

		Matrix() = default;
		Matrix(size_t rows, size_t columns);
		Matrix(const Matrix& other);
		Matrix& operator=(const Matrix& other);
		Matrix(Matrix&& other) noexcept;
		Matrix& operator=(Matrix&& other) noexcept;
		~Matrix();

		//interface
		//fills the matrix with random values
		void randomize();

		//prints the contain to STDOUT
		void print() const;

		//how many columns are there
		int getCols()const;
		//how many rows are there
		int getRows()const;

		//returns the value at specified position
		int& getAt(size_t, size_t);

		//sets the value at wanted indexes
		void setAt(size_t, size_t, int);

		//returns the transpose matrix
		Matrix getTranspose() const;

		//returns the result of multiplying two matrices
		Matrix getMultipliedBy(const Matrix& other) const;

	private:

		//representing the matrix as an array of pointers
		int** matrix{ nullptr };
		size_t rows{ 0 };
		size_t cols{ 0 };

		//help functions
	private:

		void copy(const Matrix&);
		void clean();

		//allocates enough memory and initialize with 0
		void initialize(size_t, size_t);

		//is a point inside the matrix
		bool isValid(size_t, size_t) const;
};

#endif // !MATRIX_H_INCLUDED
