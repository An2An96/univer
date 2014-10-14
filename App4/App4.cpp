//	Каждый элемент aij матрицы A(m,n) заменить суммой элементов подматрицы A'(i,j), 
//	расположенной в левом верхнем углу матрицы A.
//	Немиров Антон	13501/3

#include "stdafx.h"

#define	M	3
#define	N	3

int gen_random(int range_min, int range_max)	{
	return (range_min + rand() % (range_max - range_min + 1));
}

int _tmain(int argc, _TCHAR* argv[])
{
	//	init
	srand(time(NULL));
	//	initialize array
	int A[M][N], m = 0, n = 0;
	for (; m < M; m++)
		for (n = 0; n < N; n++)
			A[m][n] = gen_random(1, 9);
	//	perform
	for (n = 1; n < N; n++)	
		A[0][n] += A[0][n - 1];

	for (m = 1; m < M; m++)
		A[m][0] += A[m - 1][0];

	for (m = 1; m < M; m++)
		for (n = 1; n < N; n++)
			A[m][n] += A[m - 1][n] - A[m - 1][n - 1] + A[m][n - 1];
	system("pause");
	return 0;
}
