#include <stdio.h>
#include <math.h>

typedef struct    // 구조체 선언
{
    double x;
    double y;
    double z;
}
Point3D;

double calculateDistance(const Point3D* p1, const Point3D* p2)    // 두 점 사이의 Euclidean 거리 계산 함수
{
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main(void)
{
    Point3D points[2];

    for (int i = 0; i < 2; i++)    // 사용자로부터 두 점의 좌표 입력 받기
    {
        printf("%d번째 점의 좌표를 입력. (x y z): ", i + 1);
        scanf_s("%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z);
    }

    double distance = calculateDistance(&points[0], &points[1]);    // 거리 계산 및 출력
    printf("두 점 사이의 거리는: %.2lf\n", distance);

    return 0;
}