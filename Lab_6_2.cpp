#include <vector>
#include <iostream>

//Задание 1. Проверка на палиндром
/*int main()
{
	setlocale(LC_ALL, "rus");
	char dequeSize = 0;
	cout << "Введите строку: ";
	cin >> dequeSize;
	deque<char> myDeque(dequeSize);

	//Удаление пробелов и перевод всех символов к единому регистру
	for (int i = 0; i < myDeque.size(); i++)
	{
		if (myDeque[i] == ' ')
		{
			for (int j = i; j < myDeque.size(); j++)
			{
				myDeque[j] = myDeque[j + 1];
			}
		}

	}
	//Проверка на палиндром
	bool flag = true;
	for (int i = 0; i < myDeque.size() / 2; i++)
	{
		if (myDeque[i] != myDeque[myDeque.size() - 1 - i])
		{
			flag = false;
			break;
		}
	}
	flag ? cout << "Строка является палиндромом\n\n" : cout << "Строка не является палиндромом\n\n";

}*/
//Задание 2.Алгоритм Грэхема
struct pt
{
	double x, y;
};

bool cmp (pt a, pt b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}