#pragma once
#include <iostream>
class matr
{
private:   //������������ ������� 
	int cols;    //��� �������� 
	int rows;    //��� �����
	double* elems;    //�������� ��
public:     //�������� �� ��� ������
	matr();    //����������� 1 ��� ���������
	~matr();    //���������� ������ 1 	
	bool input();      //������ ������� � ����������
	bool sum(const matr* matr2);     //�������� ������
	void print();     //������ ������� � �������
	double get_elem(int i, int j);   //�������(i, j) �������
	void mult(matr* matr2);      //��������� ���� ������
	double trace();      //���� �������(����� ������������ ��������� ���������� �������)
	void mult_by_num(double num);       //��������� ������� �� �����
};

class matr
{
};

