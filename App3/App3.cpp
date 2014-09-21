// Разложить натуральное число N на простые множители. Например: 75 = 3 * 5 * 5

//	Антон Немиров	13501/3	<an2an96@bk.ru>

#include "stdafx.h"

using namespace std;

void IntToPrime(int num)
{

	int pnumbers[] = {
		2, 3, 5, 7, 11, 13, 17,
		19, 23, 29, 31, 37, 41, 43,
		47, 53, 59, 61, 67, 71, 73,
		79, 83, 89, 97, 101, 103, 107
	};

	cout << num << " = ";
	bool error = true;
	while (num > 1)
	{
		for (int i = 0; i < sizeof pnumbers; i++)
		{
			if (num % pnumbers[i])
				continue;
			num = num / pnumbers[i];
			cout << pnumbers[i];
			if (num != 1)
				cout << " * ";
			error = false;
			break;
		}
		if (error)
		{
			cout << "Не получается:C";
			break;
		}
		error = true;
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	int number;
	do
	{
		cout << "Введите целое число:" << endl;
		cin >> number;
	} while (number < 1);

	IntToPrime(number);
	system("pause");
	return false;
}