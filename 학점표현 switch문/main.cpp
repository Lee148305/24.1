#include <stdio.h>

int main(void)
{
    float score;
    int grade = -1;
    printf("����(0���� 100 ����)�� �Է��ϼ���: ");
    scanf_s("%f", &score);

    switch (grade) {
    case '0':
        if (score == 0) {
            printf("���� %.2f�� ���� ������ F�Դϴ�.\n", score);
        }
        else {
            printf("���� %.2f�� ���� ������ E�Դϴ�.\n", score);
        }
        break;
    case '1':
        printf("���� %.2f�� ���� ������ E�Դϴ�.\n", score);
        break;
    case '2':
        printf("���� %.2f�� ���� ������ D�Դϴ�.\n", score);
        break;
    case '3':
        printf("���� %.2f�� ���� ������ C�Դϴ�.\n", score);
        break;
    case '4':
        printf("���� %.2f�� ���� ������ B�Դϴ�.\n", score);
        break;
    case '5':
        printf("���� %.2f�� ���� ������ A�Դϴ�.\n", score);
        break;
    default:
        printf("�߸��� �Է�\n");
    }
    return 0;
}