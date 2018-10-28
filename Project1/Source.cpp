//#include <iostream>
#include "Matrix.hpp"

Matrix:: Matrix(int rows=0, int columns=0) : m_rows(rows), m_columns(columns)
{
	m_values = new int*[rows];
	for (int i = 0; i < m_rows; i++)
		m_values[i] = new int[m_columns];
}

Matrix& Matrix::operator=(const Matrix& right) {
	if (&right == this) {
		return *this;
	}
	if (m_rows*m_columns == right.m_rows*right.m_columns) {
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				this->m_values[i][j] = right.m_values[i][j];
	}
	else {
		for (int i = 0; i < m_rows; i++)
			delete[] m_values[i];
		delete[] m_values;
		this->m_rows = right.m_rows;
		this->m_columns = right.m_columns;
		m_values = new int*[m_rows];
		for (int i = 0; i < m_rows; i++)
			m_values[i] = new int[m_columns];
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				m_values[i][j] = right.m_values[i][j];
	}
	return *this;
}



void Matrix:: SetMatrixValues()
{
	int i, j;
	for(i=0;i<m_rows;i++)
		for (j = 0; j < m_columns; j++)
			std::cin >> m_values[i][j];
}

Matrix:: ~Matrix()
{
	for (int i = 0; i < m_rows; i++)
		delete [] m_values[i];
	delete [] m_values;
}

Matrix:: Matrix(const Matrix &right) : m_rows(right.m_rows), m_columns(right.m_columns)
{
	m_values = new int *[m_rows];
	for (int i = 0; i < m_rows; i++)
		m_values[i] = new int[m_columns];
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			m_values[i][j] = right.m_values[i][j];
}

void Matrix::GetMatrix()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
			std::cout << m_values[i][j] << ' ';
		std::cout << '\n';
	}
	std::cout << '\n';
}

Matrix operator+(const Matrix &left, const Matrix &right)
{
	//if (left.m_columns != right.m_columns && left.m_rows != right.m_columns)
	//	return -1;
	Matrix result(left.m_rows,left.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = left.m_values[i][j] + right.m_values[i][j];
	return result;
}


Matrix &Matrix::operator+=(const Matrix &right)
{
	Matrix created;
	created= (*this) + right;
	(*this) = created;
	return *this;
}

int main()
{
	Matrix M1(2,2);
	M1.SetMatrixValues();
	M1.GetMatrix();
	Matrix M2(2,2);
	M2.SetMatrixValues();
	M2.GetMatrix();
	M2 += M1;
	M2.GetMatrix();
	system("pause");
	return 0;

}