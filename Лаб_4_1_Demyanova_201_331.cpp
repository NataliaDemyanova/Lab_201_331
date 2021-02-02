
#include <cstdlib>
#include <clocale>
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

void task1()
{ 
	//���� ������
	cout << "������� ������: ";
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	//�������� ��������
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j < strlen(str); j++)
			{
				str[j] = str[j + 1];
			}
		}
		if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= '�') && (str[i] <= '�')))
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
	flag ? cout << "������ �������� �����������\n\n" : cout << "������ �� �������� �����������\n\n";
}

//����� ��������� � ������ 
int* find_substring(int arr[], char* str_for_search_in, char* substring, int start_position)
{
	int c = 1;

	for (int i = start_position; i < strlen(str_for_search_in); i++)
	{
		if (str_for_search_in[i] == substring[0])
		{
			int j = 0, k = i;
			while((j< strlen(substring))&&(substring[j++]== str_for_search_in[k++])){}
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
	//���� ������, ��������� � ��������� �������
	cout << "������� ������: ";
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	cout << "������� ���������: ";
	char pod[255];
	cin.getline(pod, 255);

	int pos;
	cout << "������� ��������� ������� ������: ";
	cin >> pos;

	//����� ��������� � ������ 
	int arr[255];
	int* res = find_substring(arr, str, pod, pos);

	//����� �������
	for (int i = 1; i < arr[0]; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

//���� ������
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
	cout << "������� ������: ";
	char str[255];
	cin.ignore();
	cin.getline(str, 255);

	int k;
	cout << "������� ����: ";
	cin >> k;

	encrypt(str, k);
	
	cout << str << "\n\n";
}

void task4()
{
	//���� ������ 
	cout << "������� �����: ";
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
	int choice = 0; // � ���� ���������� ����� ��������� ����� ������������
	while (true) // ����������� ����
	{
		cout << "��� �� ������ ���������? \n";
		cout << "1. �������� �� ��������� \n";
		cout << "2. ����� ��������� � ������ \n";
		cout << "3. ���������� ������\n";
		cout << "4. ����� ���� �������� �� �������\n";
		cout << "5. �����\n";
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



