#include <stdio.h>

int main(void)
{
	int num1, num2;
	char calcul;

	printf("사칙연산 입력(정수): ")
		scanf("%d %c %d", &num1, &calcul, &num2);

	if (calcul == '+')
	{
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
	}
	else if (calcul == '-')
	{
		printf("%d - %d = %d\n", num1, num2, num1 - num2);
	}
	else if (calcul == '*')
	{
		printf("%d * %d = %d\n", num1, num2, num1 * num2);
	}
	else if (calcul == '/')
	{
		printf("%d / %d = %d\n", num1, num2, num1 / num2);
	}
	return 0;
}