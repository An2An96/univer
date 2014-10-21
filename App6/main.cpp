/*
	Реализовать класс ТАБЛИЦА КЛЮЧ-ЗНАЧЕНИЕ (хранит строки, каждой из которых соответствует уникальный целый ключ).
	Требуемые методы:
		+ конструктор
		+ деструктор
		+ ввод
		+ вывод
		+ копирование
		- индексация по ключу
		+ добавление элемента

	Немиров Антон 13501/3 [https://github.com/An2An96/]
*/

#include "main.h"
#include "IDString_Class.cpp"

using namespace std;

int main()
{
	//	Init
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	//	Work
	IDString stmp("Тестовая строка:)");
	stmp.output();
	stmp.input("Меняем строку... вот она уже другая!");
	stmp.output();

	system("pause");
	return 0;
}
