#include <stdio.h>

int main(void)
{
	double a;
	double b;
	double c;
	double d;
	double e;
	printf("��(�ﰢ���� �غ��� ����, �簢���� �� �غ�, ���� ������) �Է� :\n");
	scanf_s("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
	printf("��� ���(�ﰢ�� ����, �簢�� ����, �� ����, �� ǥ����, �� ü��): %.1lf\t, %.1lf\t, %.1lf\t, %.1lf\t, %.1lf\n", a*b*0.5, c*d, e*e*3.14, e*e*3.14*4, e*e*e*3.14*4/3);
	return 0;
}