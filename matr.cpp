#include "matr.h"
using namespace std;


matr::matr()
{
	cols = 0;
	rows = 0;
	elems = nullptr;
}

matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;//удаление эл
}


bool matr::input()
{
	cout << "Input number of rows:";
	cin >> rows;
	cout << "Input number of columns:";
	cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		cin >> elems[i]; //введение с клавиатуры
		//elems[i] = i * 37 % 2;
	return true;
}

double matr::get_elem(int i, int j)
{
	return elems[i * cols + j];

}

void matr::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << get_elem(i, j) << "\t";
		cout << endl;
	}
}

bool matr::sum(const matr* matr2)
{
	if (rows != matr2->rows || cols != matr2->cols)
		return false;
	for (int i = 0; i < rows * cols; i++)
		elems[i] += matr2->elems[i];
	return true;
}

void matr::mult(matr* matr2)
{
	if (cols != matr2->rows)
		cout << "";
	matr res;
	res.cols = matr2->cols;
	res.rows = rows;
	res.elems = new double[res.cols * res.rows]{ 0 };
	for (int i = 0; i < cols * rows; i++)
		for (int j = 0; j < cols; j++)
			for (int r = 0; r < rows; r++)
				res.elems[i] += get_elem(r, j) * matr2->get_elem(j, r);
	res.print();
}

double matr::trace()
{
	setlocale(LC_ALL, "RUS");
	double trace = 0;
	if (cols != rows)
	{
		cout << "Неправильно задана матрица." << endl;
		return 0;
	}
	else
		for (int i = 0; i < rows * cols; i++)
		{
			trace += elems[i];
			i += cols;
		}
	return trace;
}

void matr::mult_by_num(double num)
{
	for (int i = 0; i < rows * cols; i++)
		elems[i] *= num;
}
