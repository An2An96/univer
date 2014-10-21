

#include "main.h"

class IDString	{

public:
	IDString(char *str)	{ strid = clock(); input(str); }	// construct
	IDString(void)		{ strid = clock(); }			// or empty construct
	~IDString()		{ clear(); }				// destruct
	void input(char *str)						// input string
	{
		int len = strlen(str) + 1;
		inputstr = new char[len];
		strcpy_s(inputstr, len, str);
	}
	void output()	{ std::cout << inputstr << std::endl; }		// output string
	IDString copy()	{ return IDString(inputstr); }			// copies one instance of a class to another while maintaining the line

private:
	char *inputstr;		// link to string
	int strid;		// string id

	void clear()	{ delete[]inputstr; }				// clear memory
};
