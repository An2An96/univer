// Пользователь задает целое двухзначное число (например, 47). Необходимо вывести число, полученное
// из заданного перестановкой цифр в обратном порядке (например, 74).

//	Nemirov Anton	(13501/3)	<an2an96@bk.ru>

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	int x;
	do
	{
		cout << "Введите ЦЕЛОЕ ДВУХЗНАЧНОЕ число: ";
		cin >> x;
	} while (x >= 10 && x < 100);
	cout << "Ваше число с поменяными местами цифрами: " << ((x % 10) * 10) << (x / 10) << endl;

	system("pause");
	return 0;
}