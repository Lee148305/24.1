#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculateSum(int * arr, int size)    // �迭�� ���� ���
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double calculateMean(int * arr, int size)    // �迭�� ��� ���
{
    return calculateSum(arr, size) / size;
}

double calculateVariance(int * arr, int size, double mean)    // �迭�� �л� ���
{
    double variance = 0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(arr[i] - mean, 2);
    }
    return variance / size;
}

double calculateStdDev(double variance)    // �迭�� ǥ������ ���
{
    return sqrt(variance);
}

int main(void)
{
    int initialSize, additionalSize;

    printf("�ʱ� �迭 ũ��: ");    // �ʱ� �迭 ũ�� �Է�
    scanf_s("%d", &initialSize);

    int* arr = (int *)malloc(initialSize * sizeof(int));    // �ʱ� �迭 ���� �޸� �Ҵ�

    printf("�Էµ� ��: ", initialSize);    // �ʱ� �迭 �� �Է¹ޱ�
    for (int i = 0; i < initialSize; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    double initialSum = calculateSum(arr, initialSize);    // �ʱ� �迭 ���
    double initialMean = calculateMean(arr, initialSize);
    double initialVariance = calculateVariance(arr, initialSize, initialMean);
    double initialStdDev = calculateStdDev(initialVariance);

    printf("�հ�: %.2f\n", initialSum);    // �ʱ� �迭 ��� ���
    printf("���: %.2f\n", initialMean);
    printf("�л�: %.2f\n", initialVariance);
    printf("ǥ������: %.2f\n", initialStdDev);

    printf("�߰� �迭 ũ��: ");    // �߰� �迭 ũ�� �Է�
    scanf_s("%d", &additionalSize);

    arr = (int *)realloc(arr, (initialSize + additionalSize) * sizeof(int));    // �߰� �迭 ���� �޸� ���Ҵ�

    printf("�߰��� ��: ", additionalSize);    // �߰� �迭 �� �Է¹ޱ�
    for (int i = initialSize; i < initialSize + additionalSize; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    int totalSize = initialSize + additionalSize;    // ��ü �迭 ���
    double totalSum = calculateSum(arr, totalSize);
    double totalMean = calculateMean(arr, totalSize);
    double totalVariance = calculateVariance(arr, totalSize, totalMean);
    double totalStdDev = calculateStdDev(totalVariance);

    printf("���ο� �հ�: %.2f\n", totalSum);    // �߰� �迭 ��� ���
    printf("���ο� ���: %.2f\n", totalMean);
    printf("���ο� �л�: %.2f\n", totalVariance);

    free(arr);    // ���� �޸� ����

    return 0;
}