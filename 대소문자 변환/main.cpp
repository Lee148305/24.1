#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];     // 입력 문장 저장
    char output[100];    // 바뀐 문장 저장
    int i, count = 0;    // i: 반복 변수, count: 대문자 개수 세기

    printf("영어 문장 입력: ");
    fgets(input, sizeof(input), stdin); // 문장 입력 받기

    for (i = 0; input[i] != '\0'; i++)    // 대문자를 소문자로 변환
    {
        if (isupper(input[i]))    // 대문자인 경우
        {
            output[i] = tolower(input[i]);    // 소문자로 변환
            count++;   // 대문자 개수 증가
        }
        else
        {
            output[i] = input[i];    // 대문자가 아니면 그대로 복사
        }
    }
    output[i] = '\0';

    printf("문장 입력: %s", input);
    printf("바뀐 문장: %s", output);
    printf("바뀐 문자 수: %d\n", count);    //결과 출력
    return 0;
}