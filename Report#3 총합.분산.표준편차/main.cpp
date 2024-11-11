#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_COUNT 10
#define RANGE_MIN 1
#define RANGE_MAX 100

// �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// Ư�� ���� �̳����� ������ ���� ���� �Լ�
int GenRandIntInRange(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

// ���� ��� �Լ�
int CalculateSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// �л� ��� �Լ�
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

    // ������ ���� ����
    for (int i = 0; i < NUM_COUNT; i++)
    {
        numbers[i] = GenRandIntInRange(RANGE_MIN, RANGE_MAX);
        printf("������ ���� %d: %d\n", i + 1, numbers[i]);
    }

    // ���� ���
    sum = CalculateSum(numbers, NUM_COUNT);
    mean = (double)sum / NUM_COUNT;

    // �л� �� ǥ������ ���
    variance = CalculateVariance(numbers, NUM_COUNT, mean);
    stddev = sqrt(variance);

    // ��� ���
    printf("\n����: %d\n", sum);
    printf("�л�: %.2lf\n", variance);
    printf("ǥ������: %.2lf\n", stddev);

    return 0;
}