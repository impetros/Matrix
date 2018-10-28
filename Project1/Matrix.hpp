#include <iostream>
class Matrix{
public:
	Matrix(int rows, int columns);
	Matrix(const Matrix &right);
	~Matrix();
	int Get_rows(){
		return m_rows;
	}
	int Get_columns(){
		return m_columns;
	}
	void ShowMatrix();
	void SetMatrixValues();
	Matrix& operator=(const Matrix& right);
	friend Matrix operator+(const Matrix &left, const Matrix &right);
	friend Matrix operator+(const Matrix &left, double scalar);
	friend Matrix operator+(double scalar, const Matrix &right);
	friend Matrix operator-(const Matrix &left, const Matrix &right);
	friend Matrix operator-(const Matrix &left, double scalar);
	friend Matrix operator-(double scalar, const Matrix &right);
	/*friend Matrix operator*(const Matrix &left, const Matrix &right);
	friend Matrix operator*(const Matrix &left, double scalar);
	friend Matrix operator*(double scalar, const Matrix &right);
	Matrix& operator*=(const Matrix &right);
	Matrix& operator*=(double scalar);*/
	Matrix& operator+=(const Matrix &right);
	Matrix& operator+=(double scalar);
	Matrix& operator-=(const Matrix &right);
	Matrix& operator-=(double scalar);

private:
	int **m_values;
	int m_rows;
	int m_columns;
	
};
