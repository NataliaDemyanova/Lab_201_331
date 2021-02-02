#pragma once
#include <iostream>
class matr
{
private:   //спецификатор доступа 
	int cols;    //кол столбцов 
	int rows;    //кол строк
	double* elems;    //значения эл
	double* arr = nullptr;
public:     //доступны из вне класса
	matr();    //конструктор 1 или несколько
	matr(int i, int j);
	matr(int i, int j, const double* arr);
	~matr();    //диструктор только 1 	

	double input();      //ввести матрицу с клавиатуры
	double input2();
	bool input3();
	bool input3(int i, int j);
	bool input3(int i, int j, double* arr);
	void print();     //печать матрицы в консоль
	double get_elem(int i, int j);   //вернуть(i, j) элемент
	double sum(const matr* matr2);     //сложения матриц
	double sum(int i, int j, double* arr);
	bool mult(const matr* matr2);
	bool mult(int i, int j, double* arr);
	double trace();      //след матрицы(сумма диагональных элементов квадратной матрицы)
	double det();
	double mult_by_num();       //умножение матрицы на число
};


