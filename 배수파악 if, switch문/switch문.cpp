#include <stdio.h>

int main() {
    int num1, num2;

    printf("ù ��° ������ �Է��ϼ���: ");
    scanf_s("%d", &num1);

    printf("�� ��° ������ �Է��ϼ���: ");
    scanf_s("%d", &num2);

    switch (num1 % num2) {
    case 0:
        printf("%d�� %d�� ����Դϴ�.\n", num1, num2);
        break;
    default:
        printf("%d�� %d�� ����� �ƴմϴ�.\n", num1, num2);
        break;
    }

    return 0;
}