#pragma once
#include <iostream>

class matr3D
{
private:
	size_t cols;    //��� �������� 
	size_t rows;    //��� �����
	double* elements;
public:
	matr3D();
	matr3D(size_t l_rows, size_t cols);
	matr3D(size_t l_rows, size_t cols, const double* arr);
	~matr3D();

	void input();      //������ ������� � ����������
	void print();     //������ ������� � �������
	double get_elem(size_t row, size_t column);   //�������(i, j) �������
	void set_elem(size_t row, size_t column, double argument);
	int get_rows();
	double trace();
	std::ostream& operator <<(std::ostream& out, const matr3D& matr);
	std::istream& operator>>(std::istream& in, matr3D& matr);


};

