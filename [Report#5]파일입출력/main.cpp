#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // 패딩 제거
typedef struct
{
    char name[20];       // 이름
    int id;              // 학번
    int scores[4];       // 과목 점수: 국어, 영어, 수학, 탐구
    double average;      // 평균 점수
    int rank;            // 등수
} Student;
#pragma pack(pop)

// 함수 선언
int loadStudents(const char* filename, Student* students);
void calculateAverages(Student* students, int count);
void rankStudents(Student* students, int count);
void saveToBinary(const char* filename, Student* students, int count);
void saveToText(const char* filename, Student* students, int count);
void printStudents(Student* students, int count);

int main(void)
{
    Student students[100]; // 최대 학생 수 100명
    int studentCount;

    const char* inputFile = "students_1.txt";
    const char* binaryFile = "students_1.bin";
    const char* resultFile = "students_1_results.txt";

    // 학생 데이터 읽기
    studentCount = loadStudents(inputFile, students);
    if (studentCount == 0)
    {
        printf("Error: No data loaded. Check the input file '%s'.\n", inputFile);
        return 1;
    }
    printf("Loaded %d students' data from '%s'.\n", studentCount, inputFile);

    // 평균 점수 계산 및 등수 부여
    calculateAverages(students, studentCount);
    rankStudents(students, studentCount);

    // 읽은 데이터를 출력해 확인
    printStudents(students, studentCount);

    // 데이터를 바이너리 파일로 저장
    saveToBinary(binaryFile, students, studentCount);

    // 결과를 텍스트 파일로 저장
    saveToText(resultFile, students, studentCount);

    printf("Data processing complete. Results saved to '%s'.\n", resultFile);

    return 0;
}

// 학생 데이터 텍스트 파일에서 읽기
int loadStudents(const char* filename, Student* students)
{
    FILE* file;
    int i = 0;

    // 파일 열기 확인
    if (fopen_s(&file, filename, "r") != 0)
    {
        printf("Error: Cannot open '%s' for reading.\n", filename);
        return 0;
    }

    // 데이터 읽기
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
    return i; // 학생 수 반환
}

// 평균 점수 계산
void calculateAverages(Student* students, int count)
{
    for (int i = 0; i < count; i++)
    {
        int total = 0;
        for (int j = 0; j < 4; j++) // 과목 4개
        {
            total += students[i].scores[j];
        }
        students[i].average = total / 4.0; // 평균 계산
    }
}

// 등수 부여 (평균 점수 기준 내림차순)
void rankStudents(Student* students, int count)
{
    for (int i = 0; i < count; i++)
    {
        students[i].rank = 1; // 초기 등수
        for (int j = 0; j < count; j++)
        {
            if (students[j].average > students[i].average)
            {
                students[i].rank++; // 평균이 더 높으면 등수 증가
            }
        }
    }
}

// 바이너리 파일에 저장
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

// 결과를 텍스트 파일로 저장
void saveToText(const char* filename, Student* students, int count)
{
    FILE* file;
    if (fopen_s(&file, filename, "w") != 0)
    {
        printf("Error: Cannot open '%s' for writing.\n", filename);
        return;
    }

    fprintf(file, "이름\t학번\t국어\t영어\t수학\t탐구\t평균\t등수\n");
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

// 학생 데이터 출력 (확인용)
void printStudents(Student* students, int count)
{
    printf("이름\t학번\t국어\t영어\t수학\t탐구\t평균\t등수\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\n",
            students[i].name, students[i].id,
            students[i].scores[0], students[i].scores[1],
            students[i].scores[2], students[i].scores[3],
            students[i].average, students[i].rank);
    }
}