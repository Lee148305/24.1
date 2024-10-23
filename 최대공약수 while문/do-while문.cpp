#include <stdio.h>

int main(void)
{
	int num1, num2, A, B, C, D;

	printf("첫번째 숫자 입력: ");	//두 숫자를 입력 받기
	scanf_s("%d", &num1);
	printf("두번째 숫자 입력: ");
	scanf_s("%d", &num2);

	A = num1;	//입력 받은 두 숫자 받아두기
	B = num2;

	do		//최대공약수를 do-while문으로 계산
	{
		int temp = num2;
		num2 = num1 % num2;
		num1 = temp;
	} while (num2 != 0);

	C = num1;

	D = (A * B) / C;	//최소공배수 계산하기

	printf("최대공약수: %d\n", C);	//결과 출력하기
	printf("최소공배수: %d\n", D);

	return 0;
}