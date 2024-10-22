#include <stdio.h>

int main(void)
{
	float score;
	printf("점수(0에서 100 사이)를 입력하세요: ");
	scanf("%f", &score);

    if (score == 0) {
        printf("점수 %.2f에 대한 등급은 F입니다.\n", score);
    }
    else if (score >= 1 && score <= 20) {
        printf("점수 %.2f에 대한 등급은 E입니다.\n", score);
    }
    else if (score >= 21 && score <= 40) {
        printf("점수 %.2f에 대한 등급은 D입니다.\n", score);
    }
    else if (score >= 41 && score <= 60) {
        printf("점수 %.2f에 대한 등급은 C입니다.\n", score);
    }
    else if (score >= 61 && score <= 80) {
        printf("점수 %.2f에 대한 등급은 B입니다.\n", score);
    }
    else if (score >= 81 && score <= 100) {
        printf("점수 %.2f에 대한 등급은 A입니다.\n", score);
    }
    else {
        printf("잘못된 입력입니다.\n");
    }
    return 0;
}