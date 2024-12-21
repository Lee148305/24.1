#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SUBJECTS 4
#define MAX_STUDENTS 50

typedef enum    // 과목 열거형 정의
{
    KOREAN,
    ENGLISH,
    MATH,
    SCIENCE
} Subject;

typedef struct    // 학생 정보 구조체 정의
{
    char name[20];
    int id;
    int scores[NUM_SUBJECTS];
    double average;
    int class_rank;
    int overall_rank;
} Student;

void read_students(const char* filename, Student students[], int* count);    // 함수 선언
void calculate_averages(Student students[], int count);
void calculate_ranks(Student students[], int count);
void write_results(const char* filename, Student students[], int count);
double calculate_class_average(Student students[], int count);
int compare(const void* a, const void* b);

int main()
{
    Student class1[MAX_STUDENTS];
    Student class2[MAX_STUDENTS];
    int count1 = 0, count2 = 0;

    read_students("students_1.txt", class1, &count1);    // 학생 정보 읽기
    read_students("students_2.txt", class2, &count2);

    calculate_averages(class1, count1);    // 평균 및 등수 계산
    calculate_averages(class2, count2);
    calculate_ranks(class1, count1);
    calculate_ranks(class2, count2);

    write_results("students_1_results.txt", class1, count1);    // 결과 파일 저장
    write_results("students_2_results.txt", class2, count2);

    return 0;
}

void read_students(const char* filename, Student students[], int* count)    // 파일에서 학생 정보 읽기
{
    FILE* file = fopen_s(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fscanf_s(file, "%s %d %d %d %d %d",
        students[*count].name,
        &students[*count].id,
        &students[*count].scores[KOREAN],
        &students[*count].scores[ENGLISH],
        &students[*count].scores[MATH],
        &students[*count].scores[SCIENCE]) != EOF)
    {
        (*count)++;
    }

    fclose(file);
}

void calculate_averages(Student students[], int count)    // 평균 점수 계산
{
    for (int i = 0; i < count; i++)
    {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++)
        {
            total += students[i].scores[j];
        }
        students[i].average = total / (double)NUM_SUBJECTS;
    }
}

void calculate_ranks(Student students[], int count)    // 등수 계산
{
    qsort(students, count, sizeof(Student), compare);

    for (int i = 0; i < count; i++)
    {
        students[i].class_rank = i + 1;
    }
}

void calculate_overall_ranks(Student class1[], int count1, Student class2[], int count2)    // 전체 등수 계산
{
    Student combined[MAX_STUDENTS * 2];
    int total_count = count1 + count2;

    memcpy(combined, class1, count1 * sizeof(Student));
    memcpy(combined + count1, class2, count2 * sizeof(Student));

    qsort(combined, total_count, sizeof(Student), compare);

    for (int i = 0; i < total_count; i++)
    {
        combined[i].overall_rank = i + 1;
    }

    for (int i = 0; i < count1; i++)
    {
        for (int j = 0; j < total_count; j++)
        {
            if (class1[i].id == combined[j].id)
            {
                class1[i].overall_rank = combined[j].overall_rank;
                break;
            }
        }
    }

    for (int i = 0; i < count2; i++)
    {
        for (int j = 0; j < total_count; j++)
        {
            if (class2[i].id == combined[j].id)
            {
                class2[i].overall_rank = combined[j].overall_rank;
                break;
            }
        }
    }
}

int compare(const void* a, const void* b)    // 학생 평균 비교 함수
{
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;

    if (s1->average < s2->average) return 1;
    if (s1->average > s2->average) return -1;
    return 0;
}

void write_results(const char* filename, Student students[], int count)    // 결과 파일 작성
{
    FILE* file = fopen_s(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing: %s\n", filename);
        exit(1);
    }
    fprintf(file, "학번 이름 국어 영어 수학 탐구 평균 분반등수 전체등수\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %d %d %d %.2f %d %d\n",
            students[i].id,
            students[i].name,
            students[i].scores[KOREAN],
            students[i].scores[ENGLISH],
            students[i].scores[MATH],
            students[i].scores[SCIENCE],
            students[i].average,
            students[i].class_rank,
            students[i].overall_rank);
    }
    fclose(file);
}