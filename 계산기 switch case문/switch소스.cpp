#include <stdio.h>

int main(void)
{
	int num1, num2;
	char calcul;

	printf("사칙연산 입력(정수): ");
	scanf_s("%d %c %d", &num1, &calcul, sizeof(calcul), &num2);

	switch (calcul) {
	case '+':
		printf("%d+%d=%d\n", num1, num2, num1 + num2);
		break;
	case '-':
		printf("%d-%d=%d\n", num1, num2, num1 - num2);
		break;
	case '*':
		printf("%d*%d=%d\n", num1, num2, num1 * num2);
		break;
	case '/':
		printf("%d/%d=%d\n", num1, num2, num1 / num2);
		break;
	default:
		printf("잘못된 연산 입력");
	}
	return 0;
}