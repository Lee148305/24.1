#include <stdio.h>

int main(void) {
    int number;

    printf("������ �Է��ϼ���: ");
    scanf("%d", &number);

    switch (number % 2) {
    case 0:
        printf("�Է��� ���� %d�� ¦��.\n", number);
        break;
    case 1:
        printf("�Է��� ���� %d�� Ȧ��.\n", number);
        break;
    default:
        printf("�߸��� �Է�.\n");
    }

    return 0;
}