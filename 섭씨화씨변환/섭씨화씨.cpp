#include <stdio.h>

double cel(double tempC);
double fah(double tempF);

double cel(double tempC)	//�������� ȭ���� �ٲٴ� �Լ�
{
	return(tempC * 9 / 5) + 32;
}
double fah(double tempF)	//ȭ������ ������ �ٲٴ� �Լ�
{
	return(tempF - 32) * 5 / 9;
}
int main(void)
{
	double tempC, tempF;
	int choice;

	printf("1�� 2�߿� ����(1: ���� �� ȭ��, 2: ȭ�� �� ����\n");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		printf("���� �µ� �Է�: ");
		scanf_s("%lf", &tempC);
		printf("ȭ�� �µ��� %.2f��\n", cel(tempC));
	}
	else if (choice == 2)
	{
		printf("ȭ�� �µ� �Է�: ");
		scanf_s("%lf", &tempF);
		printf("���� �µ��� %.2f��\n", fah(tempF));
	}
	else
	{
		printf("�߸��� �Է�.");
	}
	return 0;
}