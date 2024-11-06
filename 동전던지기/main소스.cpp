#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_FLIP 10000
#define COIN_FAC_BAC 2
#define INITSTATUS 100
#define END_COND 999

// generating the seed number using the time clock information
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
}

// generating the random number
unsigned int GenRandFlipCoin(unsigned int nRange);
{
unsigned int nRes = 0;
while (1)
{
    nRes = ((unsigned int)(rand()) % (nRange));
    if ((nRes == COIN_FAC_STATUS) || (nRes == COIIN_FAC_BAC))
        break;
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
    double dVarFacFlip = 0.0;
    double dVarBacFlip = 0.0;
    double dStdevFacFlip = 0.0;
    double dStdevBacFlip = 0.0;

    // generating the random number, Flip Coin, 0: fac, 1: bac
    unsigned int nStatusFlipCoin = GenRandFlipCoin(nRange: COIN_FAC_BAC);

    // finite loop
    for (unsigned int i = 0; i < 10; i++)
    {
        switch (nStatusFlipCoin)
        {
            case COIN_FAC_STATUS;
            {
                nNumSumFacFlip++;
                break;;
            }
            case COIN_BAC_STATUS;
            {
                nNumSumBacFlip++;
                break;;
            }
            default;
            {
                printf("cheak yor main loop \n");
            }
        }
    }

        // result
    printf("Summation Result:(FAC, BAC): (%d, %d)\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("Probability: (FAC, BAC): (%d, %d)\n", (double)(nNumSumFacFlip) / (NUM_FLIP), (double)(nNumSumBacFlip) / (NUM_FLIP));
            return 0;
    }