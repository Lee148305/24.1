#include <stdio.h>

double fac(int n)	//���丮�� ��� �Լ�
{
	double result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
double A(double a, int b)	//a�� b���� ����ϴ� �Լ�
{
	double result = 1;
	for (int i = 0; 1 < b; i++) {
		result *= a;
	}
	return result;
}
double sin(double x)	//sin�� ��� �Լ�
{
	double sinVal = 0;
	for (int i = 0; i < 5; i++) {
		int sign = (i % 2 == 0) ? 1 : -1;
		sinVal += sign * (x * A(x, 2 * i) / fac(2 * i + 1));
	}
	return sinVal;
}
double cos(double x)	//cos�� ��� �Լ�
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
	printf("����(0 ~ 100) �Է�: ");
	scanf_s("%lf", &deg);

		return 1;

	rad = deg * (3.14 / 180);	//������ �������� �ٲٱ�
	printf("SIN(%.2f) = %.4f\n", deg, sin(rad));
	printf("COS(%.2f) = %.4f\n", deg, cos(rad));

	return 0;
}