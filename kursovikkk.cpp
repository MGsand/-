
#include <iostream> // ���������� cout
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // ���������� ���������� ��������� �����
using namespace std; // ����� �� ���������� std

int ii = 0;

void Shellsort(char* A, int N)
{
    int h = 2, i, j, k;
    char temp, t;
    for (k = h; k > 0; k--) {
        for (i = k; i < N; i++) {
            t = A[i];
            j = i - k;

            while (j >= 0 && t < A[j]) {
                temp = A[j + k];
                A[j + k] = A[j];
                A[j] = temp;
                j = j - k;
            }
            t = A[j + k];
        }
    }
}

void AddToSorted(char ch, char* text)
{
    text = new char[ii];
    text[ii] = ch;
    ii++;
    text = new char[ii];
    text[ii] = '\0';
    for (int i = 0; i < ii; i++) {
        char c = text[i];
        printf("%c", c);
    }
    printf("\n");
    Shellsort(text, ii + 1);
    for (int i = 0; i < ii; i++) {
        printf("%c", text[i]);
    }
    printf("\n");
}

int main()
{
    char* text;
    //    int i, j;
    char a = '1';
    while (a != 'q') {
        scanf("%c", &a);
        if (((a >= 'A') && (a <= 'Z')) || ((a >= 'a') && (a <= 'z'))) {
            AddToSorted(a, text);
        }
    }
    text[ii + 1] = '\0';
    printf("%s", text);
    system("pause");
}
