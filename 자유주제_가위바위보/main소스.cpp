#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCISSORS 1
#define ROCK 2
#define PAPER 3

void print_menu(void)
{
    printf("< 가위바위보 게임 >\n");
    printf("1: 가위, 2: 바위, 3: 보\n");
}

const char* get_choice_name(int choice)
{
    switch (choice)
    {
    case SCISSORS: return "가위";
    case ROCK: return "바위";
    case PAPER: return "보";
    default: return "알 수 없음";
    }
}

int main(void)
{
    int player_choice, computer_choice;
    int player_balance = 1000;    // 초기 잔액 천원
    int bet_amount;
    int results[100];    // 게임 결과 저장 배열 (최대 100 라운드)
    int round = 0;    // 현재 라운드 번호

    srand(time(NULL));  // 랜덤 시드 설정

    printf("가위바위보 도박 게임을 시작합니다.\n");
    printf("초기 잔액: %d원\n", player_balance);

    while (player_balance > 0)
    {
        print_menu();

        printf("베팅 금액을 입력하세요: ");
        scanf_s("%d", &bet_amount);

        if (bet_amount > player_balance || bet_amount <= 0)
        {
            printf("잘못된 베팅 금액. 다시 입력하세요.\n");
            continue;
        }

        printf("선택하세요 (1: 가위, 2: 바위, 3: 보): ");
        scanf_s("%d", &player_choice);

        if (player_choice < 1 || player_choice > 3)
        {
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
            continue;
        }

        computer_choice = (rand() % 3) + 1;    // 컴퓨터의 (1~3) 무작위 선택

        printf("\n당신의 선택: %s\n", get_choice_name(player_choice));
        printf("컴퓨터의 선택: %s\n", get_choice_name(computer_choice));

        if (player_choice == computer_choice)    // 결과 판단
        {
            printf("결과: 무승부! 잔액 변동 없음.\n");
            results[round++] = 0;    // 무승부는 0 저장
        }
        else if ((player_choice == SCISSORS && computer_choice == PAPER) ||
            (player_choice == ROCK && computer_choice == SCISSORS) ||
            (player_choice == PAPER && computer_choice == ROCK))
        {
            printf("결과: 승리! %d원을 획득했습니다.\n", bet_amount);
            player_balance += bet_amount;
            results[round++] = 1;    // 승리는 1 저장
        }
        else
        {
            printf("결과: 패배! %d원을 잃었습니다.\n", bet_amount);
            player_balance -= bet_amount;
            results[round++] = -1;    // 패배는 -1 저장
        }

        printf("현재 잔액: %d원\n", player_balance);

        if (player_balance <= 0)
        {
            printf("잔액이 0원이 되었습니다. 게임을 종료합니다.\n");
            break;
        }

        printf("계속하시겠습니까? (1: 계속, 0: 종료): ");    // 계속할지 여부 확인
        int continue_game;
        scanf_s("%d", &continue_game);

        if (continue_game == 0)
        {
            printf("게임을 종료합니다. 최종 잔액: %d원\n", player_balance);
            break;
        }
    }

    printf("\n게임 기록:\n");    // 게임 기록 출력
    for (int i = 0; i < round; i++)
    {
        if (results[i] == 1)
            printf("라운드 %d: 승리\n", i + 1);
        else if (results[i] == 0)
            printf("라운드 %d: 무승부\n", i + 1);
        else
            printf("라운드 %d: 패배\n", i + 1);
    }

    return 0;
}