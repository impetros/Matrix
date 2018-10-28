#include <iostream>
class Matrix{
	int **m_values;
	int m_rows;
	int m_columns;
public:
	int Get_rows()
	{
		return m_rows;
	}
	int Get_columns()
	{
		return m_columns;
	}
	Matrix(int rows, int columns);
	Matrix(const Matrix &right);
	~Matrix();
	void GetMatrix();
	void SetMatrixValues();
	Matrix& operator=(const Matrix& right);
	friend Matrix operator+(const Matrix &left, const Matrix &right);
	Matrix& operator+=(const Matrix &right);

	
};
