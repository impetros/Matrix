#include <iostream>
class Matrix{

public:
	Matrix(int rows, int columns); // constructor with parameters
	Matrix(const Matrix &right);	//copy constructor
	~Matrix();	//destructor
	int Get_rows(){
		return m_rows;
	}	  // get number of rows
	int Get_columns(){
		return m_columns;
	}	 //get number of columns
	void ShowMatrix();	// function for show values of matrix
	void SetMatrixValues();	// function for set values
	Matrix& operator=(const Matrix& right); // overload '='
	friend Matrix operator+(const Matrix &left, const Matrix &right);
	friend Matrix operator+(const Matrix &left, double scalar);
	friend Matrix operator+(double scalar, const Matrix &right);
	friend Matrix operator-(const Matrix &left, const Matrix &right);
	friend Matrix operator-(const Matrix &left, double scalar);
	friend Matrix operator-(double scalar, const Matrix &right);
	friend Matrix operator*(const Matrix &left, const Matrix &right);
	friend Matrix operator*(const Matrix &left, double scalar);
	friend Matrix operator*(double scalar, const Matrix &right);
	friend Matrix operator/(const Matrix &left,double scalar);
	friend Matrix operator/(double scalar, const Matrix &right);
	friend Matrix operator^(const Matrix &left, int n);
	Matrix& operator*=(const Matrix &right);
	Matrix& operator*=(double scalar);
	Matrix& operator+=(const Matrix &right);
	Matrix& operator+=(double scalar);
	Matrix& operator-=(const Matrix &right);
	Matrix& operator-=(double scalar);

private:
	int **m_values;	// pointer to matrix's values
	int m_rows;	// number of rows
	int m_columns; // number of columns
	
};
