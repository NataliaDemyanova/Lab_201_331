#include "matr3D.h"
using namespace std;

matr3D::matr3D()
{
	rows = 0;
	elements = nullptr;
}

matr3D::matr3D(size_t l_rows, size_t cols)
{
	rows = l_rows;
	elements = new double[rows * rows]{ 0 };
}

matr3D::matr3D(size_t l_rows, size_t cols, const double* arr)
{

}

matr3D::~matr3D()
{
	if (elements != nullptr)
		delete[] elements;
}

void matr3D::input()
{
	if (elements != nullptr)
		delete[] elements;
	cout << "Input number of rows:";
	cin >> rows;
	elements = new double[rows * rows]{ 0 };
	cout << "Input firs diagonal:";
	for (int i = 1; i < rows * rows; i += rows + 1)
		cin >> elements[i];
	cout << "Input main diagonal:";
	for (int i = 0; i < rows * rows; i += rows + 1)
		cin >> elements[i];
	cout << "Input third diagonal:";
	for (int i = rows; i < rows * rows; i += rows + 1)
		cin >> elements[i];

}

void matr3D::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
			cout << get_elem(i, j) << "\t";
		cout << endl;
	}
}

double matr3D::get_elem(size_t row, size_t column)
{
	return elements[row * rows + column];
}

void matr3D::set_elem(size_t row, size_t column, double argument)
{
	this->elements[row * rows + column] = argument;
}

int matr3D::get_rows()
{
	return this->rows;
}

double matr3D::trace()
{
	double sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
			if (i == j)
				sum += elements[i * rows + j];
	}
	return sum;
}

std::ostream& operator<<(std::ostream& out, const matr3D& matr)
{
	out << "Rows = " << matr.rows << ' ' << "Column = " << matr.rows << endl;
	for (int i = 0; i < matr.rows; i++) {
		for (int j = 0; j < matr.rows; j++) {
			out << matr.elements[i * matr.rows + j] << '\t';
		}
		out << '\n';
	}
	return out;
}

std::istream& operator>>(std::istream& in, matr3D& matr)
{
	if (matr.elements != nullptr)
		delete[]matr.elements;
	cout << "Input number of rows: ";
	in >> matr.rows;

	matr.elements = new double[matr.rows * matr.rows]{ 0 };
	std::cout << "Input first diagonal: " << '\n';
	for (int i = 1; i < matr.rows * matr.rows; i += matr.rows + 1)
		in >> matr.elements[i];

	std::cout << "Input main diagonal: " << '\n';
	for (int i = 0; i < matr.rows * matr.rows; i += matr.rows + 1)
		in >> matr.elements[i];

	std::cout << "Input third diagonal: " << '\n';
	for (int i = matr.rows; i < matr.rows * matr.rows; i += matr.rows + 1)
		in >> matr.elements[i];

	return in;
}

matr3D& operator+(matr3D& left, const matr3D& right)
{
	for (int i = 0; i < left.rows * left.rows; i++)
		left.elements[i] += right.elements[i];
	return left;
}

matr3D& operator-(matr3D& left, const matr3D& right)
{
	for (int i = 0; i < left.rows * left.rows; i++)
		left.elements[i] -= right.elements[i];
	return left;
}

const matr3D& operator+(const matr3D& matr)
{
	return matr;
}

const matr3D& operator-(matr3D& matr)
{
	for (int i = 0; i < matr.rows * matr.rows; i++)
	{
		if (matr.elements[i] == 0)
			continue;
		matr.elements[i] = -matr.elements[i];
	}
	return matr;
}

matr3D& matr3D::operator=(const matr3D& right)
{
	if (this == &right) {
		return*this;
	}
	this->rows = right.rows;
	this->rows = right.rows;
	delete[] this->elements;
	this->elements = new double[this->rows * this->rows];
	for (int i = 0; i < rows * rows; i++)
		this->elements[i] -= right.elements[i];
	return *this;
}

matr3D& operator*(matr3D& left, const matr3D& right)
{
	matr3D result;
	result = left;

	for (int i = 0; i < left.rows; i++) {
		for (int j = 0; j < left.rows; j++) {
			double sum = 0;
			for (int k = 0; k < left.rows; k++) {
				double a = left.get_elem(i, k);
				double b = right.elements[right.rows * k + j];
				sum += a * b;
			}
			left.set_elem(i, j, sum);
		}
	}
	return left;
}