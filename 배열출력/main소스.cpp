#include <stdio.h>

int main()
{
	int A[3] = { 1, 2, 3 };   // A �迭 �ʱ�ȭ
	int B[10];    // �ʱ�ȭ �ȵ� B �迭 ����
	int i;

	for (i = 0; i < 10; i++)    // B �迭 ä��� ���� B �迭 ����� ������ŭ �ݺ�
	{
		B[i] = A[i % 3];    // A �迭 ÷�ڰ� 0~2�� ������ ���Ӵ� ������ ���
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
	}
	return 0;
}