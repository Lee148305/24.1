#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculateSum(int * arr, int size)    // 배열의 총합 계산
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double calculateMean(int * arr, int size)    // 배열의 평균 계산
{
    return calculateSum(arr, size) / size;
}

double calculateVariance(int * arr, int size, double mean)    // 배열의 분산 계산
{
    double variance = 0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(arr[i] - mean, 2);
    }
    return variance / size;
}

double calculateStdDev(double variance)    // 배열의 표준편차 계산
{
    return sqrt(variance);
}

int main(void)
{
    int initialSize, additionalSize;

    printf("초기 배열 크기: ");    // 초기 배열 크기 입력
    scanf_s("%d", &initialSize);

    int* arr = (int *)malloc(initialSize * sizeof(int));    // 초기 배열 동적 메모리 할당

    printf("입력된 값: ", initialSize);    // 초기 배열 값 입력받기
    for (int i = 0; i < initialSize; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    double initialSum = calculateSum(arr, initialSize);    // 초기 배열 계산
    double initialMean = calculateMean(arr, initialSize);
    double initialVariance = calculateVariance(arr, initialSize, initialMean);
    double initialStdDev = calculateStdDev(initialVariance);

    printf("합계: %.2f\n", initialSum);    // 초기 배열 결과 출력
    printf("평균: %.2f\n", initialMean);
    printf("분산: %.2f\n", initialVariance);
    printf("표준편차: %.2f\n", initialStdDev);

    printf("추가 배열 크기: ");    // 추가 배열 크기 입력
    scanf_s("%d", &additionalSize);

    arr = (int *)realloc(arr, (initialSize + additionalSize) * sizeof(int));    // 추가 배열 동적 메모리 재할당

    printf("추가된 값: ", additionalSize);    // 추가 배열 값 입력받기
    for (int i = initialSize; i < initialSize + additionalSize; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    int totalSize = initialSize + additionalSize;    // 전체 배열 계산
    double totalSum = calculateSum(arr, totalSize);
    double totalMean = calculateMean(arr, totalSize);
    double totalVariance = calculateVariance(arr, totalSize, totalMean);
    double totalStdDev = calculateStdDev(totalVariance);

    printf("새로운 합계: %.2f\n", totalSum);    // 추가 배열 결과 출력
    printf("새로운 평균: %.2f\n", totalMean);
    printf("새로운 분산: %.2f\n", totalVariance);

    free(arr);    // 동적 메모리 해제

    return 0;
}