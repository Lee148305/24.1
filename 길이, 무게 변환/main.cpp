#include <stdio.h>

int main(void)
{
	double a;
	double b;
	printf("����(m), ����(kg) �Է� :\n");
	scanf_s("%lf %lf", &a, &b);
	printf("����(ft/inch), ����(slug) ��ȯ ���: %.1lf\t, %.1lf\t, %.1lf\n", a*3.28084, a*39.3701, b*0.0685218);
	return 0;
}