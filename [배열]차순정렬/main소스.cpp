#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10       // 배열 크기와 값의 범위를 정의
#define MIN_VALUE -100.0
#define MAX_VALUE 100.0


void GenerateRandomArray(double * array, int size)      // 랜덤 실수 생성 함수
{
    for(int i = 0; i < size; i++)
    {
        array[i] = MIN_VALUE + ((double)rand() / RAND_MAX) * (MAX_VALUE - MIN_VALUE);
    }
}


void CalcSortArray(double* array, int size, int ascending)      // 입력 배열을 오름차순 또는 내림차순으로 정렬
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if((ascending && array[j] > array[j + 1]) || (!ascending && array[j] < array[j + 1]))
            {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


void PrintArray(const double * array, int size)      // 배열 출력 함수
{
    for(int i = 0; i < size; i++)
    {
        printf("%6.2f ", array[i]);
    }
}


int main(void)    // 배열 생성하고 정렬 결과 확인
{
    srand((unsigned int)time(NULL));    // 랜덤 시드 설정

    double array[ARRAY_SIZE];    // 배열 선언

    GenerateRandomArray(array, ARRAY_SIZE);    // 랜덤 배열 생성
    printf("배열 생성:\n");
    PrintArray(array, ARRAY_SIZE);

    CalcSortArray(array, ARRAY_SIZE, 1);    // 배열 오름차순 정렬
    printf("\n배열 정렬 (오름차순):\n");
    PrintArray(array, ARRAY_SIZE);

    CalcSortArray(array, ARRAY_SIZE, 0);    // 배열 내림차순 정렬
    printf("\n배열 정렬 (내림차순):\n");
    PrintArray(array, ARRAY_SIZE);

    return 0;
}