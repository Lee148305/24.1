#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_FLIP 10000
#define COIN_FAC_BAC 2
#define COIN_FAC_STATUS 0
#define COIN_BAC_STATUS 1

// generating the seed number using the time clock information
void GenRandSeed()
{
    srand((unsigned int)time(NULL));
}

// generating the random number
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    while (1)
    {
        nRes = rand() % nRange;
        if (nRes == COIN_FAC_STATUS || nRes == COIN_BAC_STATUS)
        {
            printf("nRes:%d\n", nRes);
            break;
        }
    }
    return nRes;
}

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nNumSumFacFlip = 0;
    int nNumSumBacFlip = 0;

    // finite loop
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FAC_BAC);

        if (nStatusFlipCoin == COIN_FAC_STATUS)
            nNumSumFacFlip++;
        else
            nNumSumBacFlip++;
    }

    // °á°ú Ãâ·Â
    printf("¾Õ¸é ³ª¿Â È½¼ö: %d\n", nNumSumFacFlip);
    printf("µÞ¸é ³ª¿Â È½¼ö: %d\n", nNumSumBacFlip);

    return 0;
}