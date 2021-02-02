#pragma once
#include <iostream>

class matr3D
{
private:
	size_t cols;    //кол столбцов 
	size_t rows;    //кол строк
	double* elements;
public:
	matr3D();
	matr3D(size_t l_rows, size_t cols);
	matr3D(size_t l_rows, size_t cols, const double* arr);
	~matr3D();

	void input();      //ввести матрицу с клавиатуры
	void print();     //печать матрицы в консоль
	double get_elem(size_t row, size_t column);   //вернуть(i, j) элемент
	void set_elem(size_t row, size_t column, double argument);
	int get_rows();
	double trace();
	std::ostream& operator <<(std::ostream& out, const matr3D& matr);
	std::istream& operator>>(std::istream& in, matr3D& matr);


};

