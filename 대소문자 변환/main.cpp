#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];     // �Է� ���� ����
    char output[100];    // �ٲ� ���� ����
    int i, count = 0;    // i: �ݺ� ����, count: �빮�� ���� ����

    printf("���� ���� �Է�: ");
    fgets(input, sizeof(input), stdin); // ���� �Է� �ޱ�

    for (i = 0; input[i] != '\0'; i++)    // �빮�ڸ� �ҹ��ڷ� ��ȯ
    {
        if (isupper(input[i]))    // �빮���� ���
        {
            output[i] = tolower(input[i]);    // �ҹ��ڷ� ��ȯ
            count++;   // �빮�� ���� ����
        }
        else
        {
            output[i] = input[i];    // �빮�ڰ� �ƴϸ� �״�� ����
        }
    }
    output[i] = '\0';

    printf("���� �Է�: %s", input);
    printf("�ٲ� ����: %s", output);
    printf("�ٲ� ���� ��: %d\n", count);    //��� ���
    return 0;
}