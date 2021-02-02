#include <fstream>//библиотека для считывания данных из файла и для записи в файл
#include <iostream>//библиотека ввода-вывода
#include <string>//библиотека работы со строками

using namespace std;
//D:\work\Project\Demyanova_201_331\text.txt

string file_format(const string file_path_full)
{
	int point;
	string format = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--)
	{
		if (file_path_full[i] == '.')
		{
			point = i;
			cout << "Формат ";
			for (int j = point + 1; j < file_path_full.length(); j++)
			{
				format += file_path_full[j];
			}

			break;
		}
	}
	cout << format;
	return string(format);
}

string file_name(const string file_path_full)
{
	int slh = -1, point = -1;
	string name = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--)
	{
		if (file_path_full[i] == '.' && point == -1)
		{
			point = i;
		}
		else if (file_path_full[i] == '\\')
		{
			slh = i;
			break;
		}
	}
	cout << "Название ";
	for (int i = slh + 1; i < point; i++)
	{
		name += file_path_full[i];
	}
	cout << name << endl;
	return string(name);
}

string file_path(const string file_path_full)
{
	int slh = -1;
	string path = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--)
	{
		if (file_path_full[i] == '\\')
		{
			slh = i;
			break;
		}
	}
	cout << "Расположение ";
	for (int i = 0; i < slh; i++)
	{
		path += file_path_full[i];
	}
	cout << path << endl;
	return string(path);
}

string file_disk(const string file_path_full)
{
	cout << "Имя диска: ";
	for (int i = 0; i <= 1; i++)
	{
		cout << file_path_full[i];
	}
	cout << endl;
	return file_path_full;
}

bool file_rename(string& file_path_full)
{
	string novel;
	string path, format;
	int slh = -1, point = -1;
	for (int i = file_path_full.length() - 1; i >= 0; i--)
	{
		if (file_path_full[i] == '.' && point == -1)
		{
			point = i;
		}
		else if (file_path_full[i] == '\\')
		{
			slh = i;
			break;
		}
	}
	for (int i = 0; i < slh; i++)
	{
		path = path + file_path_full[i];
	}
	for (int i = point + 1; i < file_path_full.length(); i++)
	{
		format = format + file_path_full[i];
	}
	file_path_full = path + '\\' + novel + '.' + format;
	cout << file_path_full << endl;
	return 0;
}

bool file_copy(const string file_path_full)
{
	int count;
	string format, path_and_name;
	ifstream file; //открытие существующего файла
	ofstream file_copy;//создание файла 
	int point;
	for (int i = file_path_full.length() - 1; i >= 0; i--)
	{
		if (file_path_full[i] == '.')
		{
			point = i;
			for (int j = point + 1; j < file_path_full.length(); j++)
				format = format + file_path_full[j];
			for (int j = 0; j < point; j++)
				path_and_name = path_and_name + file_path_full[j];
			break;
		}
	}
	file.open(file_path_full);
	if (file.is_open())
	{
		cout << "Файл открыт " << endl;
	}
	else
	{
		cout << "Файл не удалось открыть " << endl;
		return false;
	}
	file_copy.open(path_and_name + "_copy." + format);
	if (file_copy.is_open())
	{
		cout << "Копия файла открыта " << endl;
	}
	else
	{
		cout << "Копию файла не удалось открыть " << endl;
		return false;
	}
	file_copy << file.rdbuf();
	file.close();
	file_copy.close();
	return true;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	string str;
	cout << "Введите расположение файла:\n";
	cin >> str;


	int choice = 0; // в этой переменной будет храниться выбор пользователя
	while (true) // непрерывный цикл
	{

		cout << "Что вы хотите выполнить? \n";
		cout << "1. Получить расширение \n";
		cout << "2. Получить название\n";
		cout << "3. Получить расположение\n";
		cout << "4. Получить название диска\n";
		cout << "5. Переименовать файл\n";
		cout << "6. Создать копию файла\n";
		cout << "7. Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			file_format(str);
			cout << endl;
			break;
		}
		case 2:
		{
			file_name(str);
			cout << endl;
			break;
		}
		case 3:
		{
			file_path(str);
			cout << endl;
			break;
		}
		case 4:
		{
			file_disk(str);
			cout << endl;
			break;
		}
		case 5:
		{
			file_rename(str);
			cout << endl;
			break;
		}
		case 6:
		{
			file_copy(str);
			cout << endl;
			break;
		}
		case 7:
		{
			return 0;
		}

		}
	}
}


