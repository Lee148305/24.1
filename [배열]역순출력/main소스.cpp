#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10       // �迭 ũ��� ���� ������ ����
#define MIN_VALUE -100.0
#define MAX_VALUE 100.0


void GenerateRandomArray(double * array, int size)      // ���� �Ǽ� ���� �Լ�
{
    for(int i = 0; i < size; i++)
    {
        array[i] = MIN_VALUE + ((double)rand() / RAND_MAX) * (MAX_VALUE - MIN_VALUE);
    }
}


void CalcReverseArray(double* array, int size)      // �迭 ���� ��� �Լ�
{
    for(int i = 0; i < size / 2; i++)
    {
        double temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}


void PrintArray(const double * array, int size)      // �迭 ��� �Լ�
{
    for(int i = 0; i < size; i++)
    {
        printf("%6.2f ", array[i]);
    }
}


int main(void)    // �迭 �����ϰ� ���� ��ȯ ��� Ȯ��
{
    srand((unsigned int)time(NULL));    // ���� �õ� ����

    double array[ARRAY_SIZE];    // �迭 ����

    GenerateRandomArray(array, ARRAY_SIZE);    // ���� �迭 ����
    printf("�迭 ����:\n");
    PrintArray(array, ARRAY_SIZE);

    CalcReverseArray(array, ARRAY_SIZE);    // �迭 ���� ���
    printf("\n�迭 ����:\n");
    PrintArray(array, ARRAY_SIZE);

    return 0;
}