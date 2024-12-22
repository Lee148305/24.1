#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCISSORS 1
#define ROCK 2
#define PAPER 3

void print_menu(void)
{
    printf("< ���������� ���� >\n");
    printf("1: ����, 2: ����, 3: ��\n");
}

const char* get_choice_name(int choice)
{
    switch (choice)
    {
    case SCISSORS: return "����";
    case ROCK: return "����";
    case PAPER: return "��";
    default: return "�� �� ����";
    }
}

int main(void)
{
    int player_choice, computer_choice;
    int player_balance = 1000;    // �ʱ� �ܾ� õ��
    int bet_amount;
    int results[100];    // ���� ��� ���� �迭 (�ִ� 100 ����)
    int round = 0;    // ���� ���� ��ȣ

    srand(time(NULL));  // ���� �õ� ����

    printf("���������� ���� ������ �����մϴ�.\n");
    printf("�ʱ� �ܾ�: %d��\n", player_balance);

    while (player_balance > 0)
    {
        print_menu();

        printf("���� �ݾ��� �Է��ϼ���: ");
        scanf_s("%d", &bet_amount);

        if (bet_amount > player_balance || bet_amount <= 0)
        {
            printf("�߸��� ���� �ݾ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        printf("�����ϼ��� (1: ����, 2: ����, 3: ��): ");
        scanf_s("%d", &player_choice);

        if (player_choice < 1 || player_choice > 3)
        {
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        computer_choice = (rand() % 3) + 1;    // ��ǻ���� (1~3) ������ ����

        printf("\n����� ����: %s\n", get_choice_name(player_choice));
        printf("��ǻ���� ����: %s\n", get_choice_name(computer_choice));

        if (player_choice == computer_choice)    // ��� �Ǵ�
        {
            printf("���: ���º�! �ܾ� ���� ����.\n");
            results[round++] = 0;    // ���ºδ� 0 ����
        }
        else if ((player_choice == SCISSORS && computer_choice == PAPER) ||
            (player_choice == ROCK && computer_choice == SCISSORS) ||
            (player_choice == PAPER && computer_choice == ROCK))
        {
            printf("���: �¸�! %d���� ȹ���߽��ϴ�.\n", bet_amount);
            player_balance += bet_amount;
            results[round++] = 1;    // �¸��� 1 ����
        }
        else
        {
            printf("���: �й�! %d���� �Ҿ����ϴ�.\n", bet_amount);
            player_balance -= bet_amount;
            results[round++] = -1;    // �й�� -1 ����
        }

        printf("���� �ܾ�: %d��\n", player_balance);

        if (player_balance <= 0)
        {
            printf("�ܾ��� 0���� �Ǿ����ϴ�. ������ �����մϴ�.\n");
            break;
        }

        printf("����Ͻðڽ��ϱ�? (1: ���, 0: ����): ");    // ������� ���� Ȯ��
        int continue_game;
        scanf_s("%d", &continue_game);

        if (continue_game == 0)
        {
            printf("������ �����մϴ�. ���� �ܾ�: %d��\n", player_balance);
            break;
        }
    }

    printf("\n���� ���:\n");    // ���� ��� ���
    for (int i = 0; i < round; i++)
    {
        if (results[i] == 1)
            printf("���� %d: �¸�\n", i + 1);
        else if (results[i] == 0)
            printf("���� %d: ���º�\n", i + 1);
        else
            printf("���� %d: �й�\n", i + 1);
    }

    return 0;
}