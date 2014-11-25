/*Немиров Антон 13501/3 [https://github.com/An2An96/]*/

#include "stdafx.h"

assoc_array::assoc_array(int size)
{
	upperBound = size;
	ArrayData = new s_ArrData[upperBound];
}

assoc_array::~assoc_array()
{
	for (int i = 0; i < upperBound; i++)
		if (ArrayData[i].exist)
			delete ArrayData[i].string;
	delete ArrayData;
}

bool assoc_array::output(int key)
{
	int cell = findKey(key);
	if (cell == KEY_NOT_EXIST)
	{
		std::cerr << "The cell with the same key is not set" << std::endl;
		return false;
	}
	std::cout << ArrayData[cell].string;
	return true;
}

bool assoc_array::set(int key, char* string)
{
	int cell = findKey(key);
	if (cell == KEY_NOT_EXIST)
	{
		if ((cell = findFreeKey()) == NOT_FREE_KEYS)
		{
			std::cerr << "No free cells" << std::endl;
			return false;
		}
		ArrayData[cell].key = key;
		ArrayData[cell].exist = true;
	}
	int len = strlen(string) + 1;
	ArrayData[cell].string = new char[len];
	strcpy_s(ArrayData[cell].string, len, string);
	return true;
}

bool assoc_array::copy(int destKey, int sourceKey)
{
	int cell = findKey(sourceKey);
	if (cell == KEY_NOT_EXIST)
	{
		std::cerr << "Source string is not set" << std::endl;
		return false;
	}
	ArrayData[cell] = ArrayData[destKey];
	return true;
}

char* assoc_array::operator[](int key)
{
	int cell = findKey(key);
	if (cell == KEY_NOT_EXIST)
	{
		std::cerr << "The cell with the same key is not set" << std::endl;
		return NULL;
	}
	return ArrayData[cell].string;
}

std::ostream& operator<<(std::ostream& os, const assoc_array& a)
{
	for (int i = 0; i < a.upperBound; i++)
		if (a.ArrayData[i].exist)
			os << a.ArrayData[i].string << "\n";
	return os;
}

int assoc_array::findKey(int key)
{
	for (int i = 0; i < upperBound; i++)
		if (ArrayData[i].exist && ArrayData[i].key == key)
			return i;
	return KEY_NOT_EXIST;
}

int assoc_array::findFreeKey()
{
	for (int i = 0; i < upperBound; i++)
		if (ArrayData[i].exist == false)
			return i;
	return NOT_FREE_KEYS;
}
