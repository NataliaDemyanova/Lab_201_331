#pragma once
#include <iostream>
class matr
{
private:   //спецификатор доступа 
	int cols;    //кол столбцов 
	int rows;    //кол строк
	double* elems;    //значения эл
public:     //доступны из вне класса
	matr();    //конструктор 1 или несколько
	~matr();    //диструктор только 1 	
	bool input();      //ввести матрицу с клавиатуры
	bool sum(const matr* matr2);     //сложения матриц
	void print();     //печать матрицы в консоль
	double get_elem(int i, int j);   //вернуть(i, j) элемент
	void mult(matr* matr2);      //умножения двух матриц
	double trace();      //след матрицы(сумма диагональных элементов квадратной матрицы)
	void mult_by_num(double num);       //умножение матрицы на число
};

class matr
{
};

