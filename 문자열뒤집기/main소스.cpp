#include <stdio.h>
#include <string.h>

void reverseWord(char * start, char * end)    // 각 단어를 뒤집는 함수
{
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void)
{
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';    // \n 문자 제거

    printf("Before reversing words: \"%s\"\n", input);

    char* wordStart = NULL;    // 단어를 하나씩 분리
    char* temp = input;

    while (*temp)
    {
        if (!wordStart && * temp != ' ')
        {
            wordStart = temp;   // 단어의 시작점 찾기
        }
        if (wordStart && (* temp == ' ' || * (temp + 1) == '\0'))
        {
            char* wordEnd = (* temp == ' ') ? temp - 1 : temp;   // 단어의 끝점 찾기
            reverseWord(wordStart, wordEnd);
            wordStart = NULL;
        }
        temp++;
    }

    printf("After reversing words: \"%s\"\n", input);

    return 0;
}