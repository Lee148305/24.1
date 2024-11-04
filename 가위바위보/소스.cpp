#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RPS 3
#define rock 0
#define paper 1
#define scissor 2
#define INITSTATUS 100
#define END_COND 999

#define Player_Win 11
#define Player_Lose 12
#define Draw 0

void GenRandSeed() {
    srand((unsigned int)(time(NULL)));
}

unsigned int GenRandNum(unsigned int nRange) {
    return (unsigned int)(rand() % nRange);
}

int CalnRpsGameRes(unsigned int player, unsigned int computer) {
    if (player == computer) return Draw;
    else if ((player == rock && computer == scissor) ||
        (player == paper && computer == rock) ||
        (player == scissor && computer == paper)) {
        return Player_Win;
    }
    else {
        return Player_Lose;
    }
}

int main(void) {
    GenRandSeed();

    unsigned int nPlayerRps = INITSTATUS;

    while (1) {
        printf("Input your choice (rock:0, paper:1, scissor:2): ");
        printf("If you want to end the game, please input 999\n");
        scanf_s("%d", &nPlayerRps);

        if (nPlayerRps == END_COND) {
            printf("Ending the Rock-Paper-Scissors game.\n");
            break;
        }

        if ((nPlayerRps < 0) || (nPlayerRps >= RPS)) {
            printf("Invalid input. Please enter 0, 1, or 2.\n\n");
            continue;
        }

        unsigned int nComRps = GenRandNum(RPS);
        int nGameRpsRes = CalnRpsGameRes(nPlayerRps, nComRps);

        printf("Computer chose: %d\n", nComRps);

        switch (nGameRpsRes) {
        case Player_Win:
            printf("You win!\n\n");
            break;
        case Player_Lose:
            printf("You lose!\n\n");
            break;
        case Draw:
            printf("It's a draw!\n\n");
            break;
        default:
            printf("An error occurred.\n\n");
            break;
        }
    }

    return 0;
}