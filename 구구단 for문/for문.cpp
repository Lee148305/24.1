#include <stdio.h>

int main(void) {
	int A, B, C;

	printf("출력할 구구단수 입력(2~9 중 하나 입력, 0 입력 시 2단에서 9단까지 전부 출력): ");	//단수를 입력받음
	scanf_s("%d", &A);

	if (A == 0)		//입력받은 값 계산 및 출력하기
	{
		for (B = 2; B <= 9; B++) {		//2단부터 9단까지 순회함
			printf("\n%d단 출력: \n", B);
			for (C = 1; C <= 9; C++) {		//각 단 1부터 9까지 곱셈함
				printf("%d * %d = %d\n", B, C, B * C);
			}
		}
	}
	else if (A >= 2 && A <= 9) {	//특정 단을 출력하기
		printf("\n%d단 출력: \n", A);
		for (C = 1; C <= 9; C++) {		//특정 단 1부터 9까지 곱셈함
			printf("%d * %d = %d\n", A, C, A * C);
		}
	}
	else {		//잘못된 숫자나 문자 입력시 출력할 문구
		printf("잘못된 입력.");
	}

	return 0;
}