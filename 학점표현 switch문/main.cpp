#include <stdio.h>

int main(void)
{
    float score;
    int grade = -1;
    printf("점수(0에서 100 사이)를 입력하세요: ");
    scanf_s("%f", &score);

    switch (grade) {
    case '0':
        if (score == 0) {
            printf("점수 %.2f에 대한 학점은 F입니다.\n", score);
        }
        else {
            printf("점수 %.2f에 대한 학점은 E입니다.\n", score);
        }
        break;
    case '1':
        printf("점수 %.2f에 대한 학점은 E입니다.\n", score);
        break;
    case '2':
        printf("점수 %.2f에 대한 학점은 D입니다.\n", score);
        break;
    case '3':
        printf("점수 %.2f에 대한 학점은 C입니다.\n", score);
        break;
    case '4':
        printf("점수 %.2f에 대한 학점은 B입니다.\n", score);
        break;
    case '5':
        printf("점수 %.2f에 대한 학점은 A입니다.\n", score);
        break;
    default:
        printf("잘못된 입력\n");
    }
    return 0;
}