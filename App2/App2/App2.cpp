// Проверить, лежит ли окружность (x-a1)^2+(y-b1)^2=r^2 целиком внутри окружности (x-a2)^2+(y-b2)^2=r^2 или наоборот

//	Nemirov Anton	(13501/3)	<an2an96@bk.ru>

#include "stdafx.h"

using namespace std;

bool Check(float a1, float b1, float r1, float a2, float b2, float r2)
{
	if ((a1 + r1) >= (a2 + r2) && (a1 - r1) <= (a2 - r2) && (b1 + r1) >= (b2 + r2) && (b1 - r1) <= (b2 - r2))
		return true;
	else
		return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	float a1, b1, r1, a2, b2, r2;
	cout << "Введите a1, b1, r1, a2, b2, r2: ";
	cin >> a1 >> b1 >> r1 >> a2 >> b2 >> r2;
	
	if (Check(a1, b1, r1, a2, b2, r2))			cout << "Окружность 2 лежит в окружности 1!" << endl;
	else if (Check(a2, b2, r2, a1, b1, r1))		cout << "Окружность 1 лежит в окружности 2!" << endl;
	else										cout << "Ни одна из окружностей не лежит друг в друге!" << endl;
	system("pause");
	return 0;
}
