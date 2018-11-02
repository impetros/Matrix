//#include <iostream>
#include "Matrix.hpp"

Matrix:: Matrix(int rows=0, int columns=0) : m_rows(rows), m_columns(columns)
{
	if (!rows || !columns)
	{
		int n; //sau ii dam noi lui n valoare initiala si comentam cele 2 linii de jos
		std::cout << "Ce dimensiune doriti sa fie matricea unitate?" << '\n';
		std::cin >> n;
		m_rows = m_columns = n;
		m_values = new double*[m_rows];
		for (int i = 0; i < m_rows; i++)
			m_values[i] = new double[m_columns];
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				if (i != j)
					m_values[i][j] = 0;
				else m_values[i][j] = 1;
	}
	else {
		m_values = new double*[m_rows];
		for (int i = 0; i < m_rows; i++)
			m_values[i] = new double[m_columns];
	}
}

Matrix:: ~Matrix()
{
	for (int i = 0; i < m_rows; i++)
		delete [] m_values[i];
	delete [] m_values;
}

Matrix:: Matrix(const Matrix &right) : m_rows(right.m_rows), m_columns(right.m_columns)
{
	m_values = new double *[m_rows];
	for (int i = 0; i < m_rows; i++)
		m_values[i] = new double[m_columns];
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_columns; j++)
			m_values[i][j] = right.m_values[i][j];
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
		m_values = new double*[m_rows];
		for (int i = 0; i < m_rows; i++)
			m_values[i] = new double[m_columns];
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_columns; j++)
				m_values[i][j] = right.m_values[i][j];
	}
	return *this;
}

Matrix &Matrix::operator+=(const Matrix &right)
{
	(*this) = (*this) + right;
	return (*this) + right;
}

Matrix &Matrix::operator+=(double scalar)
{
	(*this) = (*this) + scalar;
	return *this;
}

Matrix &Matrix::operator-=(const Matrix &right)
{
	(*this) = (*this) - right;
	return *this;
}

Matrix &Matrix::operator-=(double scalar)
{
	(*this) = (*this) - scalar;
	return *this;
}

Matrix &Matrix::operator*=(const Matrix &right)
{
	(*this) = (*this) * right;
	return *this;
}

Matrix &Matrix::operator*=(double scalar)
{
	(*this) = (*this) * scalar;
	return *this;
}

Matrix &Matrix::operator/=(double scalar)
{
	(*this) = (*this) / scalar;
	return *this;
}

/*Matrix &Matrix::operator+()
{
	return *this;
}

Matrix &Matrix::operator-()
{
	for (int i = 0; i < m_rows; i++)
		for (int j = i + 1; j < m_columns; j++)
			m_values[i][j] = -m_values[i][j];
	return *this;
}*/

Matrix Matrix::operator[](int n)
{
	Matrix result(1,1);
	if (m_rows == 1 && m_columns != 1)
		result.m_values[0][0] = m_values[0][n];
	else if (m_rows != 1 && m_columns == 1)
		result.m_values[0][0] = m_values[n][0];
	else {
		Matrix rez(1, m_columns);
		result = rez;
		for (int j = 0; j < m_columns; j++)
			result.m_values[0][j] = m_values[n][j];
	}
	return result;
}

std::istream &operator>>(std::istream &in, Matrix &right)
{
	for (int i = 0; i < right.m_rows; i++)
		for (int j = 0; j < right.m_columns; j++)
			in >> right.m_values[i][j];
	return in;
}

std::ostream &operator<<(std::ostream &out,const  Matrix &right)
{
	out << '\n';
	for (int i = 0; i < right.m_rows; i++)
	{
		for (int j = 0; j < right.m_columns; j++)
			out << right.m_values[i][j] << ' ';
		out << '\n';
	}
	out << '\n';
	return out;
}

Matrix operator+(const Matrix &left, const Matrix &right)
{
	if (left.m_columns != right.m_columns || left.m_rows != right.m_rows)
		throw("Nu se poate face adunarea din cauza dimensiunilor");
	Matrix result(left.m_rows,left.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = left.m_values[i][j] + right.m_values[i][j];
	return result;
}

Matrix operator+(const Matrix &left, double scalar)
{
	Matrix result(left.m_rows, left.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = left.m_values[i][j] + scalar;
	return result;
}

Matrix operator+(double scalar,const Matrix &right)
{
	Matrix result(right.m_rows, right.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = right.m_values[i][j] + scalar;
	return result;
}

Matrix operator-(const Matrix &left, const Matrix &right)
{
	if (left.m_columns != right.m_columns || left.m_rows != right.m_rows)
		throw("Nu se poate face scaderea din cauza dimensiunilor");
	Matrix result(left.m_rows, left.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = left.m_values[i][j] - right.m_values[i][j];
	return result;
}

Matrix operator-(const Matrix &left, double scalar)
{
	Matrix result(left.m_rows, left.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = left.m_values[i][j] - scalar;
	return result;
}

Matrix operator-(double scalar, const Matrix &right)
{
	Matrix result(right.m_rows, right.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = scalar - right.m_values[i][j];
	return result;
}

Matrix operator*(const Matrix &left, const Matrix &right)
{
	if (left.m_rows != right.m_columns || left.m_columns != right.m_rows)
		throw("Nu se poate face inmultirea din cauza dimensiunilor");
	Matrix result(left.m_rows, right.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
		{
			result.m_values[i][j] = 0;
			for (int k = 0; k < result.m_rows; k++)
				result.m_values[i][j] += left.m_values[i][k] * right.m_values[k][j];
		}
	return result;
}

Matrix operator*(const Matrix &left, double scalar)
{
	Matrix result(left.m_rows, left.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
				result.m_values[i][j] = left.m_values[i][j] * scalar;
	return result;
}

Matrix operator*(double scalar, const Matrix &right)
{
	Matrix result(right.m_rows, right.m_columns);
	for (int i = 0; i < result.m_rows; i++)
		for (int j = 0; j < result.m_columns; j++)
			result.m_values[i][j] = right.m_values[i][j] * scalar;
	return result;
}

Matrix operator/(const Matrix &left, double scalar)
{
	if (!scalar)
		throw("Nu se poate face impartirea, deoarece scalarul este 0, iar numitorul nu are voie sa fie 0");
	Matrix result(left.m_rows, left.m_columns);
	for (int i = 0; i < left.m_rows; i++)
		for (int j = 0; j < left.m_columns; j++)
			result.m_values[i][j] = left.m_values[i][j] / scalar;
	return result;
}

Matrix operator/(double scalar,const Matrix &right)
{
	Matrix result(right.m_rows, right.m_columns);
	for (int i = 0; i < right.m_rows; i++)
		for (int j = 0; j < right.m_columns; j++)
			if (right.m_values[i][j])
				result.m_values[i][j] = scalar / right.m_values[i][j];
			else
				throw("Nu se poate face impartirea, deoarece numitorul este 0, mai exact elementul matricei");
	return result;
}

Matrix operator^(const Matrix &left, int n)
{
	Matrix result(left);
	for (int i = 0; i < n-1; i++)
		result *= left;
	for (int i= 0; i < left.m_rows; i++)
		for (int j = 0; j < left.m_columns; j++)
			if (result.m_values[i][j] > DBL_MAX)
				throw("Nu se poate ridica la putere");
	return result;
}

bool operator==(const Matrix &left, const Matrix &right)
{
	if (left.m_rows == right.m_rows && left.m_columns == right.m_columns)
	{
		for (int i = 0; i < left.m_rows; i++)
			for (int j = 0; j < left.m_columns; j++)
				if (left.m_values[i][j] != right.m_values[i][j])
					return false;
		return true;
	}
	else return false;
}

bool operator !=(const Matrix &left,const Matrix &right)
{
	if (left == right)
		return false;
	return true;
}

 Matrix operator+(const Matrix &left)
{
	return left;
}

Matrix operator-(Matrix &left)
{
	for (int i = 0; i < left.m_rows; i++)
		for (int j = 0; j < left.m_columns; j++)
			left.m_values[i][j] = -left.m_values[i][j];
	return left;
}

int main()
{
	Matrix M1(2, 2);
	//Matrix M2;
	std::cin >> M1;
	//std::cin >> M2;
	//M1 += M2; std::cout << M1;
	//M1 += 10; std::cout << M1;
	//M1 -= M2; std::cout << M1;
	//M1 -= 10; std::cout << M1;
	//M1 *= M2; std::cout << M1;
	//M1 *= 5; std::cout << M1;
	//M1 /= 5; std::cout << M1;
	//std::cout << M1+M2;
	//std::cout << M1+2;
	//std::cout << 2+M1;
	//std::cout << M1-M2;
	//std::cout << M1-2;
	//std::cout << 2-M1;
	//std::cout << M1*M2;
	//std::cout << M1*2;
	//std::cout << 2*M1;
	//std::cout << M1/2;
	//std::cout <<( M1^1000);
	//std::cout << M1[1];
	//std::cout << (M1==M2);
	//std::cout << (M1 != M2);
	system("pause");
	return 0;

}