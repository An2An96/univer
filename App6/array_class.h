/*Немиров Антон 13501/3 [https://github.com/An2An96/]*/

#include "stdafx.h"

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
	friend std::ostream& operator<<(std::ostream&, const assoc_array&);

private:

	//	#vars
	struct s_ArrData {
		char *string;
		int key;
		bool exist = false;
	}	*ArrayData;
	int upperBound;

	//	#functions
	int findKey(int iKey);
	int findFreeKey();
};
