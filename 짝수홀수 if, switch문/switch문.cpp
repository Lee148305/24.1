#include <stdio.h>

int main(void) {
    int number;

    printf("정수를 입력하세요: ");
    scanf("%d", &number);

    switch (number % 2) {
    case 0:
        printf("입력한 숫자 %d는 짝수.\n", number);
        break;
    case 1:
        printf("입력한 숫자 %d는 홀수.\n", number);
        break;
    default:
        printf("잘못된 입력.\n");
    }

    return 0;
}