/*Немиров Антон 13501/3 [https://github.com/An2An96/]*/

#include "stdafx.h"

class assoc_array	{

public:

	assoc_array(int size);
	~assoc_array();

	//	#functions
	bool output(int iKey);
	bool set(int iKey, char* cString);
	bool copy(int iDestKey, int iSourceKey);

	char* operator[](int iKey);

private:
	//	#vars
	char **_iElements;
	int *_iKeys;
	int _iUpperBound;

	//	#functions
	int findKey(int iKey);
	int findFreeKey();
};
