#include <stdio.h>

int main(void) {
    int number;

    printf("정수를 입력: ");
    scanf_s("%d", &number);

    if (number % 2 == 0) {
        printf("입력한 숫자 %d는 짝수.\n", number);
    }
    else {
        printf("입력한 숫자 %d는 홀수.\n", number);
    }

    return 0;
}