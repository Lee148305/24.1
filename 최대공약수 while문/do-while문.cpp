#include <stdio.h>

int main(void)
{
	int num1, num2, A, B, C, D;

	printf("ù��° ���� �Է�: ");	//�� ���ڸ� �Է� �ޱ�
	scanf_s("%d", &num1);
	printf("�ι�° ���� �Է�: ");
	scanf_s("%d", &num2);

	A = num1;	//�Է� ���� �� ���� �޾Ƶα�
	B = num2;

	do		//�ִ������� do-while������ ���
	{
		int temp = num2;
		num2 = num1 % num2;
		num1 = temp;
	} while (num2 != 0);

	C = num1;

	D = (A * B) / C;	//�ּҰ���� ����ϱ�

	printf("�ִ�����: %d\n", C);	//��� ����ϱ�
	printf("�ּҰ����: %d\n", D);

	return 0;
}