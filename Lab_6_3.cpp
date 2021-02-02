#include <iostream>
#include <queue>
using namespace std;
/*int main()
{
	int n;
	cin >> n;
	queue <int> que_2;
	queue <int> que_3;
	queue <int> que_5;

	for (int i = 1; i < n; i++)
	{
		if (2^i < = n)
			que_2.push(i * 2);
		if (i * 3 <= n)
			que_3.push(i * 3);
		if (i * 5 <= n)
			que_5.push(i * 5);
	}
	/*
	for (int i = 1; i < n; i++)
	{
		if (i * 2 <= n)
			que_2.push(i * 2);
		if (i * 3 <= n)
			que_3.push(i * 3);
		if (i * 5 <= n)
			que_5.push(i * 5);
	}

	/*while (que_2.size() != 0 && que_3.size() != 0 && que_5.size() != 0)
	{
		if (que_2.size() != 0 && que_2.front() == que_3.front())
			que_3.pop();
		if (que_3.size() != 0 && que_2.front() == que_5.front())
			que_5.pop();
		if (que_5.size() != 0 && que_3.front() == que_5.front())
			que_5.pop();

		if (que_2.front() < que_3.front() && que_2.size() != 0 && que_3.size() != 0)
		{
			cout << que_2.front();
			que_2.pop();
		}
		else
			if (que_5.size() != 0 && que_3.size() != 0)
				if (que_3.front() < que_5.front())
				{
					cout << que_3.front();
					que_3.pop();
				}
				else
				{
					if (que_5.size() != 0)
						if (que_5.front() < que_3.front()&& que_5.front() < que_2.front())
						cout << que_5.front();
					que_5.pop();
				}
	}

	queue <int> que_23;
	while (que_2.size() != 0 && que_3.size() != 0)
	{
		if (que_2.size() != 0 && que_3.size() != 0)
		{
			if (que_2.front() < que_3.front())
			{
				que_23.push(que_2.front());
				que_2.pop();
			}
			if (que_2.front() == que_3.front())
			{
				que_23.push(que_2.front());
				que_3.pop();
				que_2.pop();
			}
			if (que_2.front() > que_3.front())
			{
				que_23.push(que_3.front());
				que_3.pop();
			}
		}
		if (que_2.size() == 0 && que_3.size() != 0)
		{
			que_23.push(que_3.front());
			que_3.pop();
		}
		if (que_2.size() != 0 && que_3.size() == 0)
		{
			que_23.push(que_2.front());
			que_2.pop();
		}
	}

	while (que_23.size() != 0 && que_5.size() != 0)
	{
		if (que_23.size() != 0 && que_5.size() != 0)
		{
			if (que_23.front() < que_5.front())
			{
				cout << que_23.front() << endl;
				que_23.pop();
			}
			else
				if (que_23.front() > que_5.front())
				{
					cout << que_5.front() << endl;
					que_5.pop();
				}
			if (que_23.front() == que_5.front())
			{
				cout << que_23.front() << endl;
				que_23.pop();
				que_5.pop();
			}

		}
		if (que_23.size() == 0 && que_5.size() != 0)
		{
			cout << que_5.front() << endl;
			que_5.pop();
		}
		if (que_2.size() != 0 && que_3.size() == 0)
		{
			cout << que_23.front() << endl;
			que_23.pop();
		}
	}
	*/
	/*	system("pause");
		return 0;
	}*/
	/*#include <functional>
	int main()
	{
		setlocale(LC_ALL, "rus");
		int n;
		cout << "Введите числа: " << endl;
		cin >> n;

		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i : { 2, 3, 5 }) pq.push(i);

		while (n!=0) {
			int v = pq.top();
			while (pq.top() == v) pq.pop();
			cout << v << ' ';
			for (int i : { v * 2, v * 3, v * 5 }) pq.push(i);
			n--;
		}

		system("pause");
		return 0;
	}*/
int main()
{
	setlocale(LC_ALL, "rus");
	queue <int> que;
	int n;
	cout << "Введите количество чисел:";
	cin >> n;
	int number = 2;
	int x;

	while (que.size() != n)
	{
		x = number;
		while (x % 2 == 0)
			x = x / 2;
		while (x % 3 == 0)
			x = x / 3;
		while (x % 5 == 0)
			x = x / 5;
		if (x == 1)
			que.push(number);
		number++;
	}
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}