// ������������ ������ ����� ����������� ����� (��������, 47). ���������� ������� �����, ����������
// �� ��������� ������������� ���� � �������� ������� (��������, 74).

//	Nemirov Anton	(13501/3)	<an2an96@bk.ru>

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	int x;
	do
	{
		cout << "������� ����� ����������� �����: ";
		cin >> x;
	} while (x >= 10 && x < 100);
	cout << "���� ����� � ���������� ������� �������: " << ((x % 10) * 10) << (x / 10) << endl;

	system("pause");
	return 0;
}