#include <stdio.h>

double fac(int n)	//팩토리얼 계산 함수
{
	double result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
double A(double a, int b)	//a의 b제곱 계산하는 함수
{
	double result = 1;
	for (int i = 0; 1 < b; i++) {
		result *= a;
	}
	return result;
}
double sin(double x)	//sin값 계산 함수
{
	double sinVal = 0;
	for (int i = 0; i < 5; i++) {
		int sign = (i % 2 == 0) ? 1 : -1;
		sinVal += sign * (x * A(x, 2 * i) / fac(2 * i + 1));
	}
	return sinVal;
}
double cos(double x)	//cos값 계산 함수
{
	double cosVal = 0;
	for (int i = 0; i < 5; i++) {
		int sign = (i % 2 == 0) ? 1 : -1;
		cosVal += sign * (A(x, 2 * i) / fac(2 * i));
	}
	return cosVal;
}

int main(void)
{
	double deg, rad;
	printf("각도(0 ~ 100) 입력: ");
	scanf_s("%lf", &deg);

		return 1;

	rad = deg * (3.14 / 180);	//각도를 라디안으로 바꾸기
	printf("SIN(%.2f) = %.4f\n", deg, sin(rad));
	printf("COS(%.2f) = %.4f\n", deg, cos(rad));

	return 0;
}