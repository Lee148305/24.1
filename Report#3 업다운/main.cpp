#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define RANGE_MIN 1
#define RANGE_MAX 100

// �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)time(NULL));
}

// Ư�� ���� �̳� ������ ���� ���� �Լ�
int GenRandIntInRange(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

int main()
{
    GenRandSeed();  // ���� �õ� �ʱ�ȭ

    int targetNumber = GenRandIntInRange(RANGE_MIN, RANGE_MAX);  // ����� �� ������ ���� ����
    int userGuess = 0;
    int attempts = 0;

    printf("1���� 100 ������ ���� ���纸��. �õ� ��ȸ�� %d��.\n", MAX_TRIES);

    // �ִ� �õ� Ƚ��(10��) ��ŭ �ݺ�
    while (attempts < MAX_TRIES)
    {
        printf("���ڸ� �Է�: ");
        scanf_s("%d", &userGuess);
        attempts++;

        if (userGuess == targetNumber)
        {
            printf("%d�� ���� ���ڸ� ������ϴ�.\n", attempts);
            break;
        }
        else if (userGuess < targetNumber)
        {
            printf("��.\n");
        }
        else
        {
            printf("�ٿ�.\n");
        }

        // ���� �õ� Ƚ�� ���
        printf("���� ��ȸ: %d\n", MAX_TRIES - attempts);
    }

    // �õ� Ƚ�� �ʰ� �� ���� �޽��� ���
    if (attempts == MAX_TRIES && userGuess != targetNumber)
    {
        printf("���߱� ����. ������ %d�����ϴ�.\n", targetNumber);
    }

    return 0;
}