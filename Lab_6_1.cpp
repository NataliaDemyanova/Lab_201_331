#include <stack>
#include<iostream>
#include <string>
using namespace std;

//Лаб 6.1

int main()
{
	setlocale(LC_ALL, "RUS");
	stack <char> number_steck;
	string exampl;
	cout << "Введите пример:";
	getline(cin, exampl);
	for (int i = 0; i < exampl.length(); i++)
	{
		if (exampl[i] == '(' || exampl[i] == '[' || exampl[i] == '{')
			number_steck.push(exampl[i]);
		if (exampl[i] == ')' || exampl[i] == ']' || exampl[i] == '}')
		{
			if (number_steck.empty())
			{
				cout << "Выражение неверно" << endl;
				system("PAUSE");
				return 0;
			}
			else
				if ((number_steck.top() == '(' && exampl[i] == ')') || (number_steck.top() == '[' && exampl[i] == ']') || (number_steck.top() == '{' && exampl[i] == '}'))
				{
					number_steck.pop();
				}
				else
				{
					cout << "Выражение неверно" << endl;
					system("PAUSE");
					return 0;
				}
		}
	}
	if (number_steck.empty())
		cout << "Выражение верно" << endl;
	else
		cout << "Выражение неверно" << endl;
	system("PAUSE");
	return 0;
}
