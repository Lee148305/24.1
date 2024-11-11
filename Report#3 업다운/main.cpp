#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define RANGE_MIN 1
#define RANGE_MAX 100

// 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)time(NULL));
}

// 특정 범위 이내 무작위 정수 생성 함수
int GenRandIntInRange(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

int main()
{
    GenRandSeed();  // 랜덤 시드 초기화

    int targetNumber = GenRandIntInRange(RANGE_MIN, RANGE_MAX);  // 맞춰야 할 무작위 정수 생성
    int userGuess = 0;
    int attempts = 0;

    printf("1부터 100 사이의 정수 맞춰보기. 시도 기회는 %d번.\n", MAX_TRIES);

    // 최대 시도 횟수(10번) 만큼 반복
    while (attempts < MAX_TRIES)
    {
        printf("숫자를 입력: ");
        scanf_s("%d", &userGuess);
        attempts++;

        if (userGuess == targetNumber)
        {
            printf("%d번 만에 숫자를 맞췄습니다.\n", attempts);
            break;
        }
        else if (userGuess < targetNumber)
        {
            printf("업.\n");
        }
        else
        {
            printf("다운.\n");
        }

        // 남은 시도 횟수 출력
        printf("남은 기회: %d\n", MAX_TRIES - attempts);
    }

    // 시도 횟수 초과 시 종료 메시지 출력
    if (attempts == MAX_TRIES && userGuess != targetNumber)
    {
        printf("맞추기 실패. 정답은 %d였습니다.\n", targetNumber);
    }

    return 0;
}