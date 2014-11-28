/*Немиров Антон 13501/3 [https://github.com/An2An96/]*/

#include "stdafx.h"

using namespace std;

#define	KEY_NOT_EXIST	(-1)
#define	NOT_FREE_KEYS	(-1)

class assoc_array	{

public:

	assoc_array(int);
	~assoc_array();

	//	#functions
	bool output(int);
	bool set(int, char*);
	bool copy(int, int);
	bool clear(int);

	char* operator[](int);
	friend ostream& operator<<(ostream&, const assoc_array&);
	friend istream& operator>>(istream& is, assoc_array&);

private:

	//	#vars
	struct s_ArrData {
		char *string;
		int key;
		bool exist = false;
	}	*ArrayData;
	int upperBound;

	//	#functions
	bool keyCell(int, int&);
	int findKey(int);
	int findFreeKey();
};
