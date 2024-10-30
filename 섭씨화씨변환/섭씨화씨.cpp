#include <stdio.h>

double cel(double tempC);
double fah(double tempF);

double cel(double tempC)	//¼·¾¾¿¡¼­ È­¾¾·Î ¹Ù²Ù´Â ÇÔ¼ö
{
	return(tempC * 9 / 5) + 32;
}
double fah(double tempF)	//È­¾¾¿¡¼­ ¼·¾¾·Î ¹Ù²Ù´Â ÇÔ¼ö
{
	return(tempF - 32) * 5 / 9;
}
int main(void)
{
	double tempC, tempF;
	int choice;

	printf("1°ú 2Áß¿¡ ¼±ÅÃ(1: ¼·¾¾ ¡æ È­¾¾, 2: È­¾¾ ¡æ ¼·¾¾\n");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		printf("¼·¾¾ ¿Âµµ ÀÔ·Â: ");
		scanf_s("%lf", &tempC);
		printf("È­¾¾ ¿Âµµ´Â %.2f¢µ\n", cel(tempC));
	}
	else if (choice == 2)
	{
		printf("È­¾¾ ¿Âµµ ÀÔ·Â: ");
		scanf_s("%lf", &tempF);
		printf("¼·¾¾ ¿Âµµ´Â %.2f¡É\n", fah(tempF));
	}
	else
	{
		printf("Àß¸øµÈ ÀÔ·Â.");
	}
	return 0;
}