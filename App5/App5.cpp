// Текст содержит следующие знаки корректуры: $ - сделать красную строку, # - удалить следующее слово, @ - удалить следующее предложение.
// Произвести указанную корректировку.
//	Немиров Антон 13501/3

#include "stdafx.h"

using namespace std; 

string replace(string &s)
{	
	int n = 0, m;
	string error;
	for (n = s.find("$", 0); n != -1; n = s.find("$", n))
	{
		if (n == 0 || (n > 1 && s[n - 1] == '\n'))
			s.replace(n, 1, "\t");
		else
		{  
			error.insert(error.size(), "Невозможно добавить красную строку в середину предложения.\n");
			break;
		}	
	}

	for (n = s.find("#", 0); n != -1; n = s.find("#", n))
	{
		for (m = n + 1; m < s.size(); m++)
		{
			if (((int)s[m] < 65 || (int)s[m] > 122)	//	in not en or ru chars  
			&& ((int)s[m] < -64 || (int)s[m] > -1))
			{
				s.erase(n, m - n);
				break;
			}
		}
		if (m == s.size())
		{
			error.insert(error.size(), "Невозможно удалить слово, так как оно не ограничено знаком припинания.\n");
			break;
		}
	}

	for (n = s.find("@", 0); n != -1; n = s.find("@", n))
	{
		if ((m = s.find(".", n)) != -1)
			s.erase(n, m - n + 1);
		else
		{	 
			error.insert(error.size(), "Невозможно удалить предложение, так как оно не ограничено точкой.\n");
			break;
		}	
	}
	return error;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	string s = "$<- Должна добавиться красная строка.\n#ТЕСТ- А тут не должно быть слово ТЕСТ.\n@ТЕСТ ТЕСТ ТЕСТ.<-Тут не должно быть предложения ТЕСТ ТЕСТ ТЕСТ.\n";
	cout << s << endl;
	string error = replace(s);
	if (error.size())
		cerr << "При обработке строки были найдены ошибки:\n" << error << endl;
	else
		cout << "Результат обработки строки:\n" << s << endl;

	system("pause");
	return 0;
}
