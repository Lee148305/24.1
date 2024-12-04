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


void CalcReverseArray(double* array, int size)      // 배열 역순 계산 함수
{
    for(int i = 0; i < size / 2; i++)
    {
        double temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}


void PrintArray(const double * array, int size)      // 배열 출력 함수
{
    for(int i = 0; i < size; i++)
    {
        printf("%6.2f ", array[i]);
    }
}


int main(void)    // 배열 생성하고 역순 변환 결과 확인
{
    srand((unsigned int)time(NULL));    // 랜덤 시드 설정

    double array[ARRAY_SIZE];    // 배열 선언

    GenerateRandomArray(array, ARRAY_SIZE);    // 랜덤 배열 생성
    printf("배열 생성:\n");
    PrintArray(array, ARRAY_SIZE);

    CalcReverseArray(array, ARRAY_SIZE);    // 배열 역순 계산
    printf("\n배열 역순:\n");
    PrintArray(array, ARRAY_SIZE);

    return 0;
}