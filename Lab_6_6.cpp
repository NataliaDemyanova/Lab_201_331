
#include <iostream>
#include <stack>
#include <iostream>
#include <map>
using namespace std;

//Лаб 6.6+
int main()
{
	//Установка кодировки
	setlocale(0, "");

	string word;
	int count = 0;
	map <string, double> map;
	cout << "Введите текст (0 символ конца ввода): " << endl;
	cin >> word;
	while (word != "0")
	{
		if (map.find(word) != map.end()) map[word]++;
		else map[word] = 1;
		cin >> word;
		count++;
	}
	cout << "Общее количество слов: " << count << endl;
	cout << "Слово \t| Частота " << endl;
	for (auto now : map)
	{
		cout << now.first << "\t|  " << now.second * 100 / count << "%" << endl;

	}

}
//as sdd as as as fffff fff sa sa sdd 0