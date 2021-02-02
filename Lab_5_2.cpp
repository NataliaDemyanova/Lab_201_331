#include <iostream>
#include "matrix.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	//Сложение матриц
	std::cout << "Сложение матриц" << std::endl;
	matr matrA, matrB;
	matrA.input();
	matrB.input2();
	std::cout << "Matr 1: " << std::endl;
	matrA.print();
	std::cout << "Matr 2: " << std::endl;
	matrB.print();
	matrA.sum(&matrB);
	std::cout << "Sum:\n";
	matrA.print();
	std::cout << std::endl;

	//Умножение матриц
	std::cout << "Умножение матриц" << std::endl;
	matr matrC, matrD;
	matrC.input3();
	matrD.input3();
	std::cout << "Matr 1: " << std::endl;
	matrC.print();
	std::cout << "Matr 2: " << std::endl;
	matrD.print();
	matrC.mult(&matrD);
	std::cout << "Mult:\n";
	matrC.print();
	std::cout << std::endl;

	std::cout << "След матрицы: " << std::endl;
	matr matrE;
	matrE.input2();
	std::cout << "Matr: " << std::endl;
	matrE.print();
	matrE.trace();
	std::cout << std::endl;
}