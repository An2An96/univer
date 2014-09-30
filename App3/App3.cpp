// Разложить натуральное число N на простые множители. Например: 75 = 3 * 5 * 5
//	Антон Немиров	13501/3	<an2an96@bk.ru>

#include "stdafx.h"

using namespace std;

int FindNextPrime(int number, int oldprime)
{
	for (int i = oldprime + 1; i < number; ++i)
	{
		if (number % i)
			continue;
		for (int k = 2; k <= i; ++k)
		{
			if (k == i)
				return k;
			if (!(i % k))
				break;
		}
	}
	return number;
}

void IntToPrime(int num)
{
	cout << num << " = ";
	int prime = 2;
	while (num > 1)
	{
		if (num % prime)
		{		   
			prime = FindNextPrime(num, prime);
			continue;
		}
		num /= prime;
		cout << prime;
		if (num != 1)
			cout << " * ";
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	
	cout << "Введите целое число:" << endl;
	int number = input_int();
	while (number < 1)
	{
		cout << "Введите целое число больше 0!" << endl;
		number = input_int();
	}

	IntToPrime(number);
	system("pause");
	return false;
}