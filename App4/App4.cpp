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
	int A[M][N], copy_A[M][N];

	srand(time(NULL));
	for (int m = 0; m < M; ++m)
		for (int n = 0; n < N; ++n)
			A[m][n] = gen_random(1, 10);
	memcpy(copy_A, A, sizeof(A));

	for (int m = 0; m < M; ++m)	{
		for (int n = 0, summ = 0; n < N; ++n, summ = 0)	{
			for (int i = 0; i <= m; ++i)
				for (int j = 0; j <= n; ++j)
					summ += copy_A[i][j];
			A[m][n] = summ;
		}
	}
	system("pause");
    return 0;
}