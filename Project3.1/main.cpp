#include <stdio.h>

int main(void)
{
	double a;
	double b;
	double c;
	double d;
	double e;
	printf("값(삼각형의 밑변과 높이, 사각형의 두 밑변, 원의 반지름) 입력 :\n");
	scanf_s("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
	printf("계산 결과(삼각형 넓이, 사각형 넓이, 원 넓이, 원 표면적, 원 체적): %.1lf\t, %.1lf\t, %.1lf\t, %.1lf\t, %.1lf\n", a*b*0.5, c*d, e*e*3.14, e*e*3.14*4, e*e*e*3.14*4/3);
	return 0;
}