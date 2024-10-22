#include <stdio.h>

int main() {
    int num1, num2;

    printf("첫 번째 정수를 입력하세요: ");
    scanf_s("%d", &num1);

    printf("두 번째 정수를 입력하세요: ");
    scanf_s("%d", &num2);

    switch (num1 % num2) {
    case 0:
        printf("%d는 %d의 배수입니다.\n", num1, num2);
        break;
    default:
        printf("%d는 %d의 배수가 아닙니다.\n", num1, num2);
        break;
    }

    return 0;
}