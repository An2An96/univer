#include "stdafx.h"

int input_int()
{
	int n;
	char input[20], tmp[20];
	do
	{
		std::cin >> input;
		n = atoi(input);
		sprintf_s(tmp, "%i", n);
		if(strcmp(input, tmp))
			std::cout << "Неверный ввод, попробуйте снова:\n";
	} while(strcmp(input, tmp));
	return n;
}