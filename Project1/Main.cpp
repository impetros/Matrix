#include <iostream>
#include "Matrix.hpp"

int main()
{
	Matrix M1(2, 2);
	Matrix M2;
	std::cin >> M1;
	std::cout << M1.GetColumns() << ' ' << M1.GetRows();
	std::cin >> M2;
	std::cout << M1 << M2;
	M1 += M2; std::cout << M1;
	M1 += 10; std::cout << M1;
	M1 -= M2; std::cout << M1;
	M1 -= 10; std::cout << M1;
	M1 *= M2; std::cout << M1;
	M1 *= 5; std::cout << M1;
	M1 /= 5; std::cout << M1;
	std::cout << M1+M2;
	std::cout << M1+2;
	std::cout << 2+M1;
	std::cout << M1-M2;
	std::cout << M1-2;
	std::cout << 2-M1;
	std::cout << M1*M2;
	std::cout << M1*2;
	std::cout << 2*M1;
	std::cout << M1/2;
	std::cout <<( M1^1000);
	std::cout << M1[1];
	std::cout << (M1==M2);
	std::cout << (M1 != M2);
	system("pause");
	return 0;

}
