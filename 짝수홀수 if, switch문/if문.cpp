#include <stdio.h>

int main(void) {
    int number;

    printf("������ �Է�: ");
    scanf_s("%d", &number);

    if (number % 2 == 0) {
        printf("�Է��� ���� %d�� ¦��.\n", number);
    }
    else {
        printf("�Է��� ���� %d�� Ȧ��.\n", number);
    }

    return 0;
}