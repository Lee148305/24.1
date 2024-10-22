#include <stdio.h>

int main(void)
{
	double a;
	double b;
	printf("길이(m), 무게(kg) 입력 :\n");
	scanf_s("%lf %lf", &a, &b);
	printf("길이(ft/inch), 무게(slug) 변환 결과: %.1lf\t, %.1lf\t, %.1lf\n", a*3.28084, a*39.3701, b*0.0685218);
	return 0;
}