#include <stdio.h>

int main() {
    int num1, num2;

    printf("ù ��° ������ �Է�: ");
    scanf_s("%d", &num1);

    printf("�� ��° ������ �Է�: ");
    scanf_s("%d", &num2);

    if (num1 % num2 == 0) {
        printf("%d�� %d�� �����.\n", num1, num2);
    }
    else {
        printf("%d�� %d�� ����� �ƴϴ�.\n", num1, num2);
    }

    return 0;
}