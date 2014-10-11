//	Каждый элемент aij матрицы A(m,n) заменить суммой элементов подматрицы A'(i,j), 
//	расположенной в левом верхнем углу матрицы A.
//	Немиров Антон	13501/3

#include "stdafx.h"

#define	M	3
#define	N	3
#define gen_random(_range_min, _range_max)	\
	(_range_min + rand() % (_range_max - _range_min + 1))

int _tmain(int argc, _TCHAR* argv[])
{	
	//	init
	srand(time(NULL));
	//	initialize array
	int A[M][N];
	for (int m = 0; m < M; m++)
		for (int n = 0; n < N; n++)
			A[m][n] = gen_random(1, 9);
	//	perform		
	for (int m = 0; m < M; m++)	{
		for (int n = 0; n < N; n++)	{
			if (m - 1 >= 0)
				A[m][n] += (n - 1 >= 0)	? (A[m - 1][n] - A[m - 1][n - 1] + A[m][n - 1]) : (A[m - 1][n]);
			else
				A[m][n] += (n - 1 >= 0) ? (A[m][n - 1]) : (0);
		} 
	}
	system("pause");
	return 0;
}
