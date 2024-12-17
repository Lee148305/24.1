#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // �е� ����
typedef struct
{
    char name[20];       // �̸�
    int id;              // �й�
    int scores[4];       // ���� ����: ����, ����, ����, Ž��
    double average;      // ��� ����
    int rank;            // ���
} Student;
#pragma pack(pop)

// �Լ� ����
int loadStudents(const char* filename, Student* students);
void calculateAverages(Student* students, int count);
void rankStudents(Student* students, int count);
void saveToBinary(const char* filename, Student* students, int count);
void saveToText(const char* filename, Student* students, int count);
void printStudents(Student* students, int count);

int main(void)
{
    Student students[100]; // �ִ� �л� �� 100��
    int studentCount;

    const char* inputFile = "students_1.txt";
    const char* binaryFile = "students_1.bin";
    const char* resultFile = "students_1_results.txt";

    // �л� ������ �б�
    studentCount = loadStudents(inputFile, students);
    if (studentCount == 0)
    {
        printf("Error: No data loaded. Check the input file '%s'.\n", inputFile);
        return 1;
    }
    printf("Loaded %d students' data from '%s'.\n", studentCount, inputFile);

    // ��� ���� ��� �� ��� �ο�
    calculateAverages(students, studentCount);
    rankStudents(students, studentCount);

    // ���� �����͸� ����� Ȯ��
    printStudents(students, studentCount);

    // �����͸� ���̳ʸ� ���Ϸ� ����
    saveToBinary(binaryFile, students, studentCount);

    // ����� �ؽ�Ʈ ���Ϸ� ����
    saveToText(resultFile, students, studentCount);

    printf("Data processing complete. Results saved to '%s'.\n", resultFile);

    return 0;
}

// �л� ������ �ؽ�Ʈ ���Ͽ��� �б�
int loadStudents(const char* filename, Student* students)
{
    FILE* file;
    int i = 0;

    // ���� ���� Ȯ��
    if (fopen_s(&file, filename, "r") != 0)
    {
        printf("Error: Cannot open '%s' for reading.\n", filename);
        return 0;
    }

    // ������ �б�
    while (fscanf_s(file, "%19s %d %d %d %d %d",
        students[i].name, (unsigned int)sizeof(students[i].name),
        &students[i].id,
        &students[i].scores[0],
        &students[i].scores[1],
        &students[i].scores[2],
        &students[i].scores[3]) == 6)
    {
        i++;
    }

    fclose(file);
    return i; // �л� �� ��ȯ
}

// ��� ���� ���
void calculateAverages(Student* students, int count)
{
    for (int i = 0; i < count; i++)
    {
        int total = 0;
        for (int j = 0; j < 4; j++) // ���� 4��
        {
            total += students[i].scores[j];
        }
        students[i].average = total / 4.0; // ��� ���
    }
}

// ��� �ο� (��� ���� ���� ��������)
void rankStudents(Student* students, int count)
{
    for (int i = 0; i < count; i++)
    {
        students[i].rank = 1; // �ʱ� ���
        for (int j = 0; j < count; j++)
        {
            if (students[j].average > students[i].average)
            {
                students[i].rank++; // ����� �� ������ ��� ����
            }
        }
    }
}

// ���̳ʸ� ���Ͽ� ����
void saveToBinary(const char* filename, Student* students, int count)
{
    FILE* file;
    if (fopen_s(&file, filename, "wb") != 0)
    {
        printf("Error: Cannot open '%s' for writing.\n", filename);
        return;
    }

    fwrite(students, sizeof(Student), count, file);
    fclose(file);
}

// ����� �ؽ�Ʈ ���Ϸ� ����
void saveToText(const char* filename, Student* students, int count)
{
    FILE* file;
    if (fopen_s(&file, filename, "w") != 0)
    {
        printf("Error: Cannot open '%s' for writing.\n", filename);
        return;
    }

    fprintf(file, "�̸�\t�й�\t����\t����\t����\tŽ��\t���\t���\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s\t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\n",
            students[i].name, students[i].id,
            students[i].scores[0], students[i].scores[1],
            students[i].scores[2], students[i].scores[3],
            students[i].average, students[i].rank);
    }

    fclose(file);
}

// �л� ������ ��� (Ȯ�ο�)
void printStudents(Student* students, int count)
{
    printf("�̸�\t�й�\t����\t����\t����\tŽ��\t���\t���\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\n",
            students[i].name, students[i].id,
            students[i].scores[0], students[i].scores[1],
            students[i].scores[2], students[i].scores[3],
            students[i].average, students[i].rank);
    }
}