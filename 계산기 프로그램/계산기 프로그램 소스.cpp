#include <stdio.h>

int main(void)
{
	float score;
	printf("����(0���� 100 ����)�� �Է��ϼ���: ");
	scanf("%f", &score);

    if (score == 0) {
        printf("���� %.2f�� ���� ����� F�Դϴ�.\n", score);
    }
    else if (score >= 1 && score <= 20) {
        printf("���� %.2f�� ���� ����� E�Դϴ�.\n", score);
    }
    else if (score >= 21 && score <= 40) {
        printf("���� %.2f�� ���� ����� D�Դϴ�.\n", score);
    }
    else if (score >= 41 && score <= 60) {
        printf("���� %.2f�� ���� ����� C�Դϴ�.\n", score);
    }
    else if (score >= 61 && score <= 80) {
        printf("���� %.2f�� ���� ����� B�Դϴ�.\n", score);
    }
    else if (score >= 81 && score <= 100) {
        printf("���� %.2f�� ���� ����� A�Դϴ�.\n", score);
    }
    else {
        printf("�߸��� �Է��Դϴ�.\n");
    }
    return 0;
}