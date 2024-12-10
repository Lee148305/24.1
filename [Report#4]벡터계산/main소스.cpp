#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dot_product(const int * v1, const int * v2);    // 함수 선언
void cross_product(const int * v1, const int * v2, int* result);
void generate_random_vector(int * vector, int size);

int dot_product(const int * v1, const int * v2)    // 내적 계산 함수
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

void cross_product(const int* v1, const int* v2, int* result)    // 외적 계산 함수
{
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void generate_random_vector(int* vector, int size)    // 랜덤 벡터 생성 함수
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = rand() % 21 - 10; // -10에서 10 사이의 랜덤 정수
    }
}

int main(void)
{
    srand(time(NULL));    // 랜덤 시드 설정

    int vector1[3];    // 3차원 벡터 선언 및 랜덤 값 초기화
    int vector2[3];

    generate_random_vector(vector1, 3);
    generate_random_vector(vector2, 3);

    printf("벡터1: [%d, %d, %d]\n", vector1[0], vector1[1], vector1[2]);    // 생성된 벡터 출력
    printf("벡터2: [%d, %d, %d]\n", vector2[0], vector2[1], vector2[2]);

    int cross[3];    // 외적 계산
    cross_product(vector1, vector2, cross);
    printf("외적: [%d, %d, %d]\n", cross[0], cross[1], cross[2]);

    int dot = dot_product(vector1, vector2);    // 내적 계산
    printf("내적: %d\n", dot);

    return 0;
}