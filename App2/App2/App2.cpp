// ���������, ����� �� ���������� (x-a1)^2+(y-b1)^2=r^2 ������� ������ ���������� (x-a2)^2+(y-b2)^2=r^2 ��� ��������

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
	cout << "������� a1, b1, r1, a2, b2, r2: ";
	cin >> a1 >> b1 >> r1 >> a2 >> b2 >> r2;
	
	if (Check(a1, b1, r1, a2, b2, r2))			cout << "���������� 2 ����� � ���������� 1!" << endl;
	else if (Check(a2, b2, r2, a1, b1, r1))		cout << "���������� 1 ����� � ���������� 2!" << endl;
	else										cout << "�� ���� �� ����������� �� ����� ���� � �����!" << endl;
	system("pause");
	return 0;
}