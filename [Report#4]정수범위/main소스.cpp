#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generate_random_numbers(int* array, int size, int min, int max);    // 함수 선언
void extract_numbers_in_range(const int* array, int size, int* result, int range_min, int range_max, int count);
double calculate_sum(const int* array, int size);
double calculate_variance(const int* array, int size, double mean);
double calculate_standard_deviation(double variance);

void generate_random_numbers(int* array, int size, int min, int max)    // 랜덤 숫자 생성 함수
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void extract_numbers_in_range(const int* array, int size, int* result, int range_min, int range_max, int count)    // 특정 범위의 숫자 추출 함수
{
    int extracted_count = 0;
    for (int i = 0; i < size && extracted_count < count; i++)
    {
        if (array[i] >= range_min && array[i] <= range_max)
        {
            result[extracted_count++] = array[i];
        }
    }

    for (int i = extracted_count; i < count; i++)    // 만약 필요한 개수만큼 추출되지 않으면 나머지는 0으로 채움
    {
        result[i] = 0;
    }
}

double calculate_sum(const int* array, int size)    // 총합 계산 함수
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

double calculate_variance(const int* array, int size, double mean)    // 분산 계산 함수
{
    double variance = 0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(array[i] - mean, 2);
    }
    return variance / size;
}

double calculate_standard_deviation(double variance)    // 표준편차 계산 함수
{
    return sqrt(variance);
}

int main(void)
{
    srand(time(NULL));

    int numbers[100];    // 100개의 무작위 정수 생성
    generate_random_numbers(numbers, 100, 1, 100);    // 범위: 1 ~ 100

    printf("무작위 정수 100개: \n");    // 생성된 정수 출력
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", numbers[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    int extracted[10];    // 특정 범위에서 10개의 정수 추출
    int range_min = 20, range_max = 60;
    extract_numbers_in_range(numbers, 100, extracted, range_min, range_max, 10);

    printf("\n추출된 정수 (지정한 범위: %d ~ %d): \n", range_min, range_max);    // 추출된 정수 출력
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", extracted[i]);
    }
    printf("\n");

    double sum = calculate_sum(extracted, 10);    // 총합, 분산, 표준편차 계산
    double mean = sum / 10;
    double variance = calculate_variance(extracted, 10, mean);
    double std_deviation = calculate_standard_deviation(variance);

    printf("\n총합: %.2f\n", sum);    // 결과 출력
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", std_deviation);

    return 0;
}