#include <stdio.h>

int main(void)
{
	int num1, num2;
	char calcul;

	printf("��Ģ���� �Է�(����): ");
	scanf("\d", &num1);
	scanf("\c", &calcul);
	scanf("\d", &num2);

	if (calcul == '+')
	{
		printf("%d+%d=%d\n", num1, num2, num1+num2);
	}
	else if (calcul == '-')
	{
		printf("%d-%d=%d\n", num1, num2, num1-num2);
	}
	else if (calcul == '*')
	{
		printf("%d*%d=%d\n", num1, num2, num1*num2);
	}
	else if (calcul == '/')
	{
		if (num2 != 0)
		{ 
		printf("%d/%d=%d\n", num1, num2, num1/num2);
		}
		else {
			printf("0���� ������ �Ұ�.\n");
		}
	return 0;
}