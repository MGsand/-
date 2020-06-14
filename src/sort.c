#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// функция сортировки строки, stroka - массив для хранения введенной строки,
// word - массив для хранения номеров позиций, с которых начинаются слова, num -
// количество введеных слов
void ShakerSort(char* stroka, int num, int* word)
{
    int L = 0, R = num - 1, temp, k = num, i;
    while (L < R) {
        for (i = R; i > L; i--) {
            if (strcmp(&stroka[word[i]], &stroka[word[i - 1]]) < 0) {
                temp = word[i];
                word[i] = word[i - 1];
                word[i - 1] = temp;
                k = i;
            }
        }
        L = k;
        for (i = L; i < R; i++) {
            if (strcmp(&stroka[word[i]], &stroka[word[i + 1]]) > 0) {
                temp = word[i + 1];
                word[i + 1] = word[i];
                word[i] = temp;
                k = i;
            }
        }
        R = k;
    }
    for (int i = 0; i < num; i++)
        printf("%s ", &stroka[word[i]]);
}
// считает количество пробелов
int count_spaces(char* stroka, int n)
{
    int c = 1, i;
    for (i = 0; i < n; i++) {
        if (stroka[i] == ' ')
            c++;
    }
    return c;
}