#include <stdio.h>

void SetArray(double* pDArr, int nArrSize)
{
	printf("Input: size(%d) array\n", nArrSize);
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		scanf_s("%lf", pDArr + i);
	}
}

void PrintArray(double* pDinput, int nArrSize)
{
	printf("using pointer..\n");
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		if (*(pDinput + i) > dRes)
			dRes = *(pDinput + i);
	}
	return dRes;
}

double CalcMaxValArray(double* pDArr, int nArrSize)
{
	double dRes = pDinput[0];
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		if (*(pDArr + i) > dRes)
			dRes = *(pDArr + i);
	}
	return dRes;
}

int main()
{
	double dArr[5] = {};
	double* pDArr = dArr;
	const int nArrSize = sizeof(dArr) / sizeof(dArr[0]);

	SetArray(dArr, nArrSize);
	PrintArray(dArr, nArrSize);

	printf("\n");
	printf("using array..\n");
	for (unsigned i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
	}


	printf("\n");
	printf("using competability..\n");
	for (unsigned i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
		printf("[%d](%u, %.4lf)\n", i, dArr + i, dArr + i));
		printf("[%d](%u, %.4lf)\n", i, &pDArr[i], pDArr[i]);
		printf("[%d](%u, %.4lf)\n", i, pDArr + i, pDArr + i));
	}

	printf("[MaxVal](%.4lf)\n", CalcMaxValArray(pDArr, nArrSize));
	return 0;
}