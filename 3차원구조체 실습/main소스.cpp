#include <stdio.h>
#include <math.h>

typedef struct    // ����ü ����
{
    double x;
    double y;
    double z;
}
Point3D;

double calculateDistance(const Point3D* p1, const Point3D* p2)    // �� �� ������ Euclidean �Ÿ� ��� �Լ�
{
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main(void)
{
    Point3D points[2];

    for (int i = 0; i < 2; i++)    // ����ڷκ��� �� ���� ��ǥ �Է� �ޱ�
    {
        printf("%d��° ���� ��ǥ�� �Է�. (x y z): ", i + 1);
        scanf_s("%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z);
    }

    double distance = calculateDistance(&points[0], &points[1]);    // �Ÿ� ��� �� ���
    printf("�� �� ������ �Ÿ���: %.2lf\n", distance);

    return 0;
}