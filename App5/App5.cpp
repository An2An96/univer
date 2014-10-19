// Текст содержит следующие знаки корректуры: $ - сделать красную строку, # - удалить следующее слово, @ - удалить следующее предложение.
// Произвести указанную корректировку.
//	Немиров Антон 13501/3

#include "stdafx.h"

using namespace std; 

void replace(string &s)
{	
	//tr1::regex rx("/ ^\w*(#\w*)\s\, \.");
	//tr1::regex_replace(s, rx, "");
	int n = 0, m;
	for (; n != -1;)
		if ((n = s.find("$", 0)) != -1)
			s.replace(n, 1, "\t");

	for (n = 0; n != -1;)
	{
		if ((n = s.find("#", 0)) != -1)
		{
			if ((m = s.find(" ", n)) != -1)
				s.erase(n, m - n + 1);
			else if ((m = s.find(".", n)) != -1)
				s.erase(n, m - n + 1);
			else if ((m = s.find(",", n)) != -1)
				s.erase(n, m - n + 1);
			else
				s.erase(n, s.size());
		}
	}

	for (n = 0; n != -1;)
		if ((n = s.find("@", 0)) != -1)
			s.erase(n, ((m = s.find(".", n)) != -1) ? (m - n + 1) : s.size());
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	string s = "$<- Должна добавиться красная строка.\n#ТЕСТ <- А тут не должно быть слово ТЕСТ.\n@ТЕСТ ТЕСТ ТЕСТ.<-Тут не должно быть предложения ТЕСТ ТЕСТ ТЕСТ.";
	cout << s << endl;
	replace(s);
	cout << s << endl;

	system("pause");
	return 0;
}
