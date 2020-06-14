#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// функция расщепления строки на слова
void word_splitting(char* stroka, int* word)
{
    int num, flag, i;
    for (i = 0, flag = 1, num = 0; stroka[i]; i++) {
        if (stroka[i] == ' ') {
            stroka[i] = 0;
            flag = 1;
        } else if (flag) {
            word[num++] = i;
            flag = 0;
        }
    }
    for (int i = 0; i < num; i++)
        printf("%s\n", &stroka[word[i]]);
}
// функция игнорирования некорректных символов
int ignoring_characters(char* stroka)
{
    int i = 0;
    int d; // длина строки
    d = strlen(stroka);
    if (d == 0) {
        return 1;
    }
    while (stroka[i] != '\0') {
        if ((stroka[i] >= 33 && stroka[i] <= 64)
            || (stroka[i] >= 91 && stroka[i] <= 96)
            || (stroka[i] >= 123 && stroka[i] <= 191))
            return 2;
        i++;
    }
    for (int i = 0; i < d; i++) {
        if (stroka[i] == ' ' && stroka[i - 1] == ' ')
            return 3;
    }
    if (stroka[0] == ' ')
        return 4;
    return 0;
}