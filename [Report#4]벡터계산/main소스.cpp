#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dot_product(const int * v1, const int * v2);    // �Լ� ����
void cross_product(const int * v1, const int * v2, int* result);
void generate_random_vector(int * vector, int size);

int dot_product(const int * v1, const int * v2)    // ���� ��� �Լ�
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

void cross_product(const int* v1, const int* v2, int* result)    // ���� ��� �Լ�
{
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void generate_random_vector(int* vector, int size)    // ���� ���� ���� �Լ�
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = rand() % 21 - 10; // -10���� 10 ������ ���� ����
    }
}

int main(void)
{
    srand(time(NULL));    // ���� �õ� ����

    int vector1[3];    // 3���� ���� ���� �� ���� �� �ʱ�ȭ
    int vector2[3];

    generate_random_vector(vector1, 3);
    generate_random_vector(vector2, 3);

    printf("����1: [%d, %d, %d]\n", vector1[0], vector1[1], vector1[2]);    // ������ ���� ���
    printf("����2: [%d, %d, %d]\n", vector2[0], vector2[1], vector2[2]);

    int cross[3];    // ���� ���
    cross_product(vector1, vector2, cross);
    printf("����: [%d, %d, %d]\n", cross[0], cross[1], cross[2]);

    int dot = dot_product(vector1, vector2);    // ���� ���
    printf("����: %d\n", dot);

    return 0;
}