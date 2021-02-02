#pragma once
#include <iostream>
class matr
{
private:   //������������ ������� 
	int cols;    //��� �������� 
	int rows;    //��� �����
	double* elems;    //�������� ��
	double* arr = nullptr;
public:     //�������� �� ��� ������
	matr();    //����������� 1 ��� ���������
	matr(int i, int j);
	matr(int i, int j, const double* arr);
	~matr();    //���������� ������ 1 	

	double input();      //������ ������� � ����������
	double input2();
	bool input3();
	bool input3(int i, int j);
	bool input3(int i, int j, double* arr);
	void print();     //������ ������� � �������
	double get_elem(int i, int j);   //�������(i, j) �������
	double sum(const matr* matr2);     //�������� ������
	double sum(int i, int j, double* arr);
	bool mult(const matr* matr2);
	bool mult(int i, int j, double* arr);
	double trace();      //���� �������(����� ������������ ��������� ���������� �������)
	double det();
	double mult_by_num();       //��������� ������� �� �����
};


