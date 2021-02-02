#include <set>
#include <vector>
#include <iostream>
using namespace std;

//Лаб 6.4+
int main()
{
	//Установка кодировки
	setlocale(0, "");
	set<string>logins;
	vector<string> logins_points;
	int n, size = 0;
	string login, point;

	cout << "Введите n = ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> login >> point;
		logins.insert(login);
		if (logins.size() > size) logins_points.push_back(login + "\t|  " + point);
		size = logins.size();
	}

	cout << "login\t|  point" << endl;
	for (int i = 0; i < logins_points.size(); i++)
		cout << logins_points[i] << endl;

}
