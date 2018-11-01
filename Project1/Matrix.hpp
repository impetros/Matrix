#include <iostream>
class Matrix{

public:
	Matrix(int rows, int columns); // constructor with parameters
	Matrix(const Matrix &right);	//copy constructor
	~Matrix();	//destructor
	int GetRows(){
		return m_rows;
	}	  // get number of rows
	int GetColumns(){
		return m_columns;
	}	 //get number of columns
	Matrix& operator=(const Matrix& right); // overload assignment operator '='
	Matrix& operator+=(const Matrix &right);
	Matrix& operator+=(double scalar);
	Matrix& operator-=(const Matrix &right);
	Matrix& operator-=(double scalar);
	Matrix& operator*=(const Matrix &right);
	Matrix& operator*=(double scalar);
	Matrix& operator+();
	Matrix& operator-();
	Matrix operator[](int n);
	friend std::istream &operator>>(std::istream &in, Matrix &right);
	friend std::ostream &operator<<(std::ostream &out, const  Matrix &right);
	friend Matrix operator+(const Matrix &left, const Matrix &right);
	friend Matrix operator+(const Matrix &left, double scalar);
	friend Matrix operator+(double scalar, const Matrix &right);
	friend Matrix operator-(const Matrix &left, const Matrix &right);
	friend Matrix operator-(const Matrix &left, double scalar);
	friend Matrix operator-(double scalar, const Matrix &right);
	friend Matrix operator*(const Matrix &left, const Matrix &right);
	friend Matrix operator*(const Matrix &left, double scalar);
	friend Matrix operator*(double scalar, const Matrix &right);
	friend Matrix operator/(const Matrix &left, double scalar);
	friend Matrix operator/(double scalar, const Matrix &right);
	friend Matrix operator^(const Matrix &left, int n);
	friend bool operator==(const Matrix &left, const Matrix &right);
	friend bool operator!=(const Matrix &left, const Matrix &right);
private:
	double **m_values;	// pointer to matrix's values
	int m_rows;	// number of rows
	int m_columns; // number of columns
	
};
