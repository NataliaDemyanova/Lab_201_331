#include "matrix.h"
using namespace std;


matr::matr()
{
	cols = 0;
	rows = 0;
	elems = nullptr;
}

matr::matr(int i, int j)
{
	cols = j;
	rows = i;
	elems = new double[cols * rows];
}

matr::matr(int i, int j, const double* arr)
{
	cols = j;
	rows = i;
	elems = new double[cols * rows];
	for (int k = 0; k < cols * rows; k++)
		elems[k] = arr[k];
}

matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;//удаление эл
}


double matr::input()
{
	cout << "Input number of rows:";
	cin >> rows;
	cout << "Input number of columns:";
	cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		elems[i] = i * 37 % 2;
	return true;
}

double matr::input2()
{
	cout << "Input number of rows:";
	cin >> rows;
	cout << "Input number of columns:";
	cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		elems[i] = i * 42 % 2;
	return true;
}

bool matr::input3()
{
	cout << "Input number of rows:";
	cin >> rows;
	cout << "Input number of columns:";
	cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		elems[i] = i * 39 % 2;
	return true;
}

bool matr::input3(int i, int j)
{
	if (elems != nullptr)
		delete[] elems;
	rows = i;
	cols = j;
	elems = new double[rows * cols];
	for (int k = 0; k < rows * cols; k++)
		elems[k] = k * 37 % 2;
	return true;
}

bool matr::input3(int i, int j, double* arr)
{
	if (elems != nullptr)
		delete[] elems;
	rows = i;
	cols = j;
	elems = new double[rows * cols];
	for (int k = 0; k < rows * cols; k++)
		elems[k] = arr[k];
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

double matr::sum(const matr* matr2)
{
	if (rows != matr2->rows || cols != matr2->cols)
		return false;
	for (int i = 0; i < rows * cols; i++)
		elems[i] += matr2->elems[i];
	return true;
}

double matr::sum(int i, int j, double* arr)
{
	if (rows != i || cols != j)
		return false;
	for (int i = 0; i < rows * cols; i++)
		elems[i] = elems[i] + arr[i];
	return true;
}

bool matr::mult(const matr* matr2)
{
	if (cols != matr2->rows)
		return false;
	matr res;
	res.cols = matr2->cols;
	res.rows = rows;
	res.elems = new double[res.cols * res.rows];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < matr2->cols; j++) {
			res.elems[i * res.cols + j] = 0;
			for (int r = 0; r < matr2->rows; r++)
				res.elems[i * res.cols + j] += elems[i * cols + r] * matr2->elems[r * matr2->cols + j];
		}
	delete[] this->elems;
	this->cols = res.cols;
	this->rows = res.rows;
	this->elems = new double[cols * rows];
	for (int i = 0; i < cols * rows; i++)
		elems[i] = res.elems[i];
	return true;
}

bool matr::mult(int i, int j, double* arr)
{
	if (cols != i)
		return false;
	matr res;
	res.cols = j;
	res.rows = this->rows;
	res.elems = new double[(res.cols) * res.rows]{ 0 };
	for (int i = 0; i < res.rows; i++)
		for (int l = 0; l < res.cols; l++) {
			res.elems[i * res.cols + j] = 0;
			for (int r = 0; r < this->cols; r++)
				res.elems[i * res.cols + l] += get_elem(i, r) * arr[r * l + j];
		}
	res.print();
	return false;
}

double matr::trace()
{
	setlocale(LC_ALL, "rus");
	int k = 0;
	if (rows != cols)
	{
		cout << "Неправильно задана матрица." << endl;
		return 0;
	}
	else
		for (int i = 0; i < rows * cols; i = i + cols)
		{
			k += elems[i];
			i += 1;
		}
	cout << "Сумма по диагонали: " << k << endl;
	return true;
}

double matr::det()
{
	int det1;
	int det2;
	if (((rows != 2) && (cols != 2)) && ((rows != 3) && (cols != 3)))
		cout << "Ошибка!";
	else
	{
		if ((rows == 2) && (cols == 2))
		{
			det1 = elems[0] * elems[3] - elems[1] * elems[2];
			cout << det1;
		}
		if ((rows == 3) && (cols == 3))
		{
			det2 = elems[0] * elems[4] * elems[8] + elems[6] * elems[1] * elems[5] + elems[3] * elems[7] * elems[2] - elems[6] * elems[8];
			cout << det2;
		}
	}
	return true;
}

double matr::mult_by_num()
{
	double num;
	cout << "Введите число: ";
	cin >> num;
	for (int i = 0; i < rows * cols; i++)
		elems[i] *= num;
	return true;
}
