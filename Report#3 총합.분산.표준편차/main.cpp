#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_COUNT 10
#define RANGE_MIN 1
#define RANGE_MAX 100

// 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// 특정 범위 이내에서 무작위 정수 생성 함수
int GenRandIntInRange(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

// 총합 계산 함수
int CalculateSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// 분산 계산 함수
double CalculateVariance(int arr[], int size, double mean)
{
    double variance = 0.0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(arr[i] - mean, 2);
    }
    return variance / size;
}

int main(void)
{
    GenRandSeed();

    int numbers[NUM_COUNT];
    int sum = 0;
    double mean = 0.0, variance = 0.0, stddev = 0.0;

    // 무작위 정수 생성
    for (int i = 0; i < NUM_COUNT; i++)
    {
        numbers[i] = GenRandIntInRange(RANGE_MIN, RANGE_MAX);
        printf("무작위 정수 %d: %d\n", i + 1, numbers[i]);
    }

    // 총합 계산
    sum = CalculateSum(numbers, NUM_COUNT);
    mean = (double)sum / NUM_COUNT;

    // 분산 및 표준편차 계산
    variance = CalculateVariance(numbers, NUM_COUNT, mean);
    stddev = sqrt(variance);

    // 결과 출력
    printf("\n총합: %d\n", sum);
    printf("분산: %.2lf\n", variance);
    printf("표준편차: %.2lf\n", stddev);

    return 0;
}