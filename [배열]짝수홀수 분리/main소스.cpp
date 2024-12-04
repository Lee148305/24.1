#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10    // �迭 ũ��� ���� ������ ����
#define MIN_VALUE 0
#define MAX_VALUE 100
#define UNUSED_VALUE -1    // ������ ���� �ε��� ��Ÿ���� �ʱ�ȭ ��

void GenerateRandomArray(int * array, int size)      // ���� ���� ���� �Լ�
{
    for(int i = 0; i < size; i++)
    {
        array[i] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
    }
}

void InitializeArray(int* array, int size, int initialValue)    // �迭 �ʱ�ȭ �Լ�
{
    for(int i = 0; i < size; i++)
    {
        array[i] = initialValue;
    }
}


void CalcEvenOddArray(const int * input, int size, int * evenArray, int * oddArray)    // ¦�� Ȧ�� �и��ϰ� ���� �迭�� �����ϴ� �Լ�
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


void PrintArray(const int * array, int size)    // �迭 ��� �Լ�, ��� ���ϴ� �� ����
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
    srand((unsigned int)time(NULL));    // ���� �õ� ����

    int inputArray[ARRAY_SIZE];    // �Է� �迭 ����
    GenerateRandomArray(inputArray, ARRAY_SIZE);
    printf("Generated Array:\n");
    PrintArray(inputArray, ARRAY_SIZE);

    int evenArray[ARRAY_SIZE], oddArray[ARRAY_SIZE];    // ��� �迭 ����
    InitializeArray(evenArray, ARRAY_SIZE, UNUSED_VALUE);
    InitializeArray(oddArray, ARRAY_SIZE, UNUSED_VALUE);

    CalcEvenOddArray(inputArray, ARRAY_SIZE, evenArray, oddArray);    // ¦���� Ȧ�� �и�

    printf("\n¦��:\n");    // ��� ���
    PrintArray(evenArray, ARRAY_SIZE);

    printf("\nȦ��:\n");
    PrintArray(oddArray, ARRAY_SIZE);

    return 0;
}