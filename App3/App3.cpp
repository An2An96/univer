// Разложить натуральное число N на простые множители. Например: 75 = 3 * 5 * 5
//	Антон Немиров	13501/3	<an2an96@bk.ru>

#include "stdafx.h"

#define	input_int(_var)	\
	do { cin.clear();	cin.sync(); cout << "Введите целое число:" << endl; cin >> _var; } while (cin.fail());

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
	int number;
	input_int(number);
	while (number < 1)
	{
		cout << "Ошибка: Введите целое число больше 0..." << endl;
		input_int(number);
	}
	IntToPrime(number);
	system("pause");
	return false;
}