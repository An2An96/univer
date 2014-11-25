/*Немиров Антон 13501/3 [https://github.com/An2An96/]*/

#include "stdafx.h"

assoc_array::assoc_array(int size)
{
	_iUpperBound = size;
	_iElements = (char**)calloc(_iUpperBound, sizeof(char*));
	_iKeys = (int*)calloc(_iUpperBound, sizeof(int*));

	for (int i = 0; i < _iUpperBound; i++)
	{
		_iElements[i] = NULL;
		_iKeys[i] = NULL;
	}
}

assoc_array::~assoc_array()
{
	for (int i = 0; i < _iUpperBound; i++)
		if (_iElements[i] != NULL)
			free(_iElements[i]);
	free(_iElements);
	free(_iKeys);
}

bool assoc_array::output(int iKey)
{
	int iCell = findKey(iKey);
	if (iCell == -1)
	{
		std::clog << "The cell with the same key is not set" << std::endl;
		return false;
	}
	std::cout << _iElements[iCell];
	return true;
}

bool assoc_array::set(int iKey, char* cString)
{
	int iCell = findKey(iKey);
	if (iCell == -1)
	{
		if ((iCell = findFreeKey()) == -1)
		{
			std::clog << "No free cells" << std::endl;
			return false;
		}
		_iKeys[iCell] = iKey;
	}

	//	if isset
	if (_iElements[iCell] != NULL)
		free(_iElements[iCell]);

	int len = strlen(cString) + 1;
	_iElements[iCell] = (char*)calloc(len, sizeof(char));
	for (int i = 0; i < len; i++)
		_iElements[iCell][i] = cString[i];
	return true;
}

bool assoc_array::copy(int iDestKey, int iSourceKey)
{
	int iSourceCell = findKey(iSourceKey);
	if (iSourceCell == -1)
	{
		std::clog << "Source string is not set" << std::endl;
		return false;
	}
	return assoc_array::set(iDestKey, _iElements[iSourceCell]);
}

char* assoc_array::operator[](int iKey)
{
	int iCell = findKey(iKey);
	if (iCell == -1)
	{
		std::clog << "The cell with the same key is not set" << std::endl;
		return NULL;
	}
	return _iElements[iCell];
}

int assoc_array::findKey(int iKey)
{
	for (int i = 0; i < _iUpperBound; i++)
	{
		if (_iKeys[i] == iKey)
			return i;
	}
	return -1;
}

int assoc_array::findFreeKey()
{
	for (int i = 0; i < _iUpperBound; i++)
	{
		if (_iElements[i] == NULL)
			return i;
	}
	return -1;
}
