#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generate_random_numbers(int* array, int size, int min, int max);    // �Լ� ����
void extract_numbers_in_range(const int* array, int size, int* result, int range_min, int range_max, int count);
double calculate_sum(const int* array, int size);
double calculate_variance(const int* array, int size, double mean);
double calculate_standard_deviation(double variance);

void generate_random_numbers(int* array, int size, int min, int max)    // ���� ���� ���� �Լ�
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void extract_numbers_in_range(const int* array, int size, int* result, int range_min, int range_max, int count)    // Ư�� ������ ���� ���� �Լ�
{
    int extracted_count = 0;
    for (int i = 0; i < size && extracted_count < count; i++)
    {
        if (array[i] >= range_min && array[i] <= range_max)
        {
            result[extracted_count++] = array[i];
        }
    }

    for (int i = extracted_count; i < count; i++)    // ���� �ʿ��� ������ŭ ������� ������ �������� 0���� ä��
    {
        result[i] = 0;
    }
}

double calculate_sum(const int* array, int size)    // ���� ��� �Լ�
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

double calculate_variance(const int* array, int size, double mean)    // �л� ��� �Լ�
{
    double variance = 0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(array[i] - mean, 2);
    }
    return variance / size;
}

double calculate_standard_deviation(double variance)    // ǥ������ ��� �Լ�
{
    return sqrt(variance);
}

int main(void)
{
    srand(time(NULL));

    int numbers[100];    // 100���� ������ ���� ����
    generate_random_numbers(numbers, 100, 1, 100);    // ����: 1 ~ 100

    printf("������ ���� 100��: \n");    // ������ ���� ���
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", numbers[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    int extracted[10];    // Ư�� �������� 10���� ���� ����
    int range_min = 20, range_max = 60;
    extract_numbers_in_range(numbers, 100, extracted, range_min, range_max, 10);

    printf("\n����� ���� (������ ����: %d ~ %d): \n", range_min, range_max);    // ����� ���� ���
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", extracted[i]);
    }
    printf("\n");

    double sum = calculate_sum(extracted, 10);    // ����, �л�, ǥ������ ���
    double mean = sum / 10;
    double variance = calculate_variance(extracted, 10, mean);
    double std_deviation = calculate_standard_deviation(variance);

    printf("\n����: %.2f\n", sum);    // ��� ���
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", std_deviation);

    return 0;
}