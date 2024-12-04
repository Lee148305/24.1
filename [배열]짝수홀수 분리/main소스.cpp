#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10    // 배열 크기와 값의 범위를 정의
#define MIN_VALUE 0
#define MAX_VALUE 100
#define UNUSED_VALUE -1    // 사용되지 않은 인덱스 나타내는 초기화 값

void GenerateRandomArray(int * array, int size)      // 랜덤 정수 생성 함수
{
    for(int i = 0; i < size; i++)
    {
        array[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
    }
}

void InitializeArray(int* array, int size, int initialValue)    // 배열 초기화 함수
{
    for(int i = 0; i < size; i++)
    {
        array[i] = initialValue;
    }
}


void CalcEvenOddArray(const int * input, int size, int * evenArray, int * oddArray)    // 짝수 홀수 분리하고 각각 배열에 저장하는 함수
{
    int evenIndex = 0, oddIndex = 0;
    for(int i = 0; i < size; i++)
    {
        if(input[i] % 2 == 0)
        {
            evenArray[evenIndex++] = input[i];
        }
        else
        {
            oddArray[oddIndex++] = input[i];
        }
    }
}


void PrintArray(const int * array, int size)    // 배열 출력 함수, 사용 안하는 값 무시
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] != UNUSED_VALUE)
        {
            printf("%4d ", array[i]);
        }
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));    // 랜덤 시드 설정

    int inputArray[ARRAY_SIZE];    // 입력 배열 생성
    GenerateRandomArray(inputArray, ARRAY_SIZE);
    printf("Generated Array:\n");
    PrintArray(inputArray, ARRAY_SIZE);

    int evenArray[ARRAY_SIZE], oddArray[ARRAY_SIZE];    // 출력 배열 생성
    InitializeArray(evenArray, ARRAY_SIZE, UNUSED_VALUE);
    InitializeArray(oddArray, ARRAY_SIZE, UNUSED_VALUE);

    CalcEvenOddArray(inputArray, ARRAY_SIZE, evenArray, oddArray);    // 짝수와 홀수 분리

    printf("\n짝수:\n");    // 결과 출력
    PrintArray(evenArray, ARRAY_SIZE);

    printf("\n홀수:\n");
    PrintArray(oddArray, ARRAY_SIZE);

    return 0;
}