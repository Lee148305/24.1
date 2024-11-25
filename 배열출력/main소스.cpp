#include <stdio.h>

int main()
{
	int A[3] = { 1, 2, 3 };   // A 배열 초기화
	int B[10];    // 초기화 안된 B 배열 선언
	int i;

	for (i = 0; i < 10; i++)    // B 배열 채우기 위해 B 배열 요소의 개수만큼 반복
	{
		B[i] = A[i % 3];    // A 배열 첨자가 0~2를 갖도록 나머니 연산자 사용
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
	}
	return 0;
}