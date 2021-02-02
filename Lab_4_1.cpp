
#include <cstdlib>
#include <clocale>
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

void task1()
{
	//Ввод строки
	cout << "Введите строку: ";
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	//Удаление пробелов
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j < strlen(str); j++)
			{
				str[j] = str[j + 1];
			}
		}
		if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'А') && (str[i] <= 'Я')))
		{
			str[i] = str[i] + ' ';
		}
	}
	bool flag = true;
	for (int i = 0; i < strlen(str) / 2; i++)
	{
		if (str[i] != str[strlen(str) - 1 - i])
		{
			flag = false;
			break;
		}
	}
	flag ? cout << "Строка является палиндромом\n\n" : cout << "Строка не является палиндромом\n\n";
}

//Поиск подстроки в строке 
int* find_substring(int arr[], char* str_for_search_in, char* substring, int start_position)
{
	int c = 1;

	for (int i = start_position; i < strlen(str_for_search_in); i++)
	{
		if (str_for_search_in[i] == substring[0])
		{
			int j = 0, k = i;
			while ((j < strlen(substring)) && (substring[j++] == str_for_search_in[k++])) {}
			if (j == strlen(substring))
			{
				arr[c] = i;
				c++;
			}
		}
	}
	arr[0] = c;
	return arr;
}

void task2()
{
	//Ввод строки, подстроки и начальной позиции
	cout << "Введите строку: ";
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	cout << "Введите подстроку: ";
	char pod[255];
	cin.getline(pod, 255);

	int pos;
	cout << "Введите начальную позицию поиска: ";
	cin >> pos;

	//Поиск подстроки в сторке 
	int arr[255];
	int* res = find_substring(arr, str, pod, pos);

	//Вывод массива
	for (int i = 1; i < arr[0]; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

//Шифр Цезаря
void encrypt(char* str_for_encrypt, int key)
{
	for (int i = 0; i < strlen(str_for_encrypt); i++)
	{
		if ((str_for_encrypt[i] >= 'a') && (str_for_encrypt[i] <= 'z'))
		{
			str_for_encrypt[i] = (char)(((int)(str_for_encrypt[i]) - 97 + key) % 26 + 97);
		}
	}
}

void task3()
{
	cout << "Введите строку: ";
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	int k;
	cout << "Введите ключ: ";
	cin >> k;

	encrypt(str, k);

	cout << str << "\n\n";
}

void task4()
{
	//Ввод текста 
	cout << "Введите текст: ";
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	int flag = -1;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '"')
		{
			flag *= -1;
			if (flag < 0)
			{
				cout << "\n";
			}
		}
		else {
			if (flag > 0)
			{
				cout << str[i];
			}
		}
	}
	cout << "\n";
}


int main()
{

	setlocale(LC_ALL, "RUS");
	int choice = 0; // в этой переменной будет храниться выбор пользователя
	while (true) // непрерывный цикл
	{
		cout << "Что вы хотите выполнить? \n";
		cout << "1. Проверка на палиндром \n";
		cout << "2. Поиск подстроки в строке \n";
		cout << "3. Шифрование Цезаря\n";
		cout << "4. Вывод всех названий из текстов\n";
		cout << "5. Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			task1();

			break;
		}
		case 2:
		{
			task2();
			break;
		}
		case 3:
		{
			task3();

			break;
		}
		case 4:
		{
			task4();
			break;
		}
		case 5:
		{
			return 0;
		}

		}
	}
}



