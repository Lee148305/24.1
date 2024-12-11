#include <stdio.h>
#include <string.h>

void reverseWord(char * start, char * end)    // �� �ܾ ������ �Լ�
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

    input[strcspn(input, "\n")] = '\0';    // \n ���� ����

    printf("Before reversing words: \"%s\"\n", input);

    char* wordStart = NULL;    // �ܾ �ϳ��� �и�
    char* temp = input;

    while (*temp)
    {
        if (!wordStart && * temp != ' ')
        {
            wordStart = temp;   // �ܾ��� ������ ã��
        }
        if (wordStart && (* temp == ' ' || * (temp + 1) == '\0'))
        {
            char* wordEnd = (* temp == ' ') ? temp - 1 : temp;   // �ܾ��� ���� ã��
            reverseWord(wordStart, wordEnd);
            wordStart = NULL;
        }
        temp++;
    }

    printf("After reversing words: \"%s\"\n", input);

    return 0;
}