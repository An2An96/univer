/*Немиров Антон 13501/3 [https://github.com/An2An96/]*/

#include "stdafx.h"

using namespace std;

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
		cerr << "The cell with the same key is not set" << endl;
		return false;
	}
	cout << ArrayData[cell].string;
	return true;
}

bool assoc_array::set(int key, char* string)
{
	int cell = findKey(key);
	if (cell == KEY_NOT_EXIST)
	{
		if ((cell = findFreeKey()) == NOT_FREE_KEYS)
		{
			cerr << "No free cells" << endl;
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
	int cell;
	return (keyCell(sourceKey, cell)) ? set(destKey, ArrayData[cell].string) : false;
}

bool assoc_array::clear(int key)
{
	int cell;
	if (keyCell(key, cell))
	{
		delete(ArrayData[cell].string);
		ArrayData[cell].exist = false;
		return true;
	}
	return false;
}

char* assoc_array::operator[](int key)
{
	int cell;
	if (keyCell(key, cell))
	{
		return ArrayData[cell].string;
	}
	return NULL;
}

ostream& operator<<(ostream& os, const assoc_array& a)
{
	for (int i = 0; i < a.upperBound; i++)
		if (a.ArrayData[i].exist)
			os << a.ArrayData[i].string << "\n";
	return os;
}

istream& operator>>(istream& is, assoc_array& a)
{	  
	string s;
	int key;
	bool step = false;
	while (getline(is, s))
	{
		if (step)	a.set(key, (char*)s.c_str());
		else		key = atoi(s.c_str());
		step = !step;
	}
	return is;
}

bool assoc_array::keyCell(int key, int &cell)
{
	cell = findKey(key);
	if (cell == KEY_NOT_EXIST)
	{
		cerr << "The cell with the same key is not set" << endl;
		return false;
	}
	return true;
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
