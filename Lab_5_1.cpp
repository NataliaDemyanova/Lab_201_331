#include <iostream>
#include "matr.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	int choice;
	matr matrA, matrB;

	std::cout << "Введите матрицу А" << std::endl;
	matrA.input();//заполнение 	
	std::cout << "A=\n";
	matrA.print();//выведение

	std::cout << "Введите матрицу B" << std::endl;
	matrB.input();
	std::cout << "B=\n";
	matrB.print();

	while (true)
	{
		std::cout << "Что вы хотите выполнить?\n"
			<< "1 Сумма матриц\n"
			<< "2 Умножение матриц\n"
			<< "3 След матрицы\n"
			<< "4 Умножение матриц на число\n"
			<< "5 Выход\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			matrA.sum(&matrB);
			std::cout << "A+B=\n";
			matrA.print();
			break;
		}
		case 2:
		{
			std::cout << "A=A*B=\n";
			matrA.mult(&matrB);
			//matrA.print();
			break;
		}
		case 3:
		{
			std::cout << matrA.trace() << std::endl;
			break;
		}
		case 4:
		{
			double num;
			std::cout << "Введите число:" << std::endl;
			std::cin >> num;
			matrA.mult_by_num(num);
			std::cout << "A=A*num=\n";
			matrA.print();
			break;
		}
		case 5:
		{
			return 0;
		}
		}
	}
}