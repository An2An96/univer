// ��������� ����������� ����� N �� ������� ���������. ��������: 75 = 3 * 5 * 5
//	����� �������	13501/3	<an2an96@bk.ru>

#include "stdafx.h"

using namespace std;

int FindNextPrime(int number, int oldprime)
{
	bool check = false;
	for (int i = 2, k = oldprime + 1; i <= number; i++)
	{
		for (k; k < i; k++)
		{
			if (!(i % k))
			{
				check = true;
				break;
			}
		}
		if (!check)
			return k;
	}
}

void IntToPrime(int num)
{
	cout << num << " = ";
	int test, prime = 2;
	while (num > 1)
	{
		if (num % prime)
		{		   
			prime = FindNextPrime(num, prime);
			continue;
		}
		num = num / prime;
		cout << prime;
		if (num != 1)
			cout << " * ";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	int number;
	do
	{
		cout << "������� ����� �����:" << endl;
		cin >> number;
	} while (number < 1);

	IntToPrime(number);
	system("pause");
	return false;
}