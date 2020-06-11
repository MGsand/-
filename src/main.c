#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print(char* stroka, int num, int* word)
{
    int i;
    FILE* f1;
    f1 = fopen("sort.txt", "w");
    for (i = 0; i < num; i++) {
        //        if (i == num) {
        //            fputs(&stroka[word[i]], f1);
        //      } else {
        fputs(&stroka[word[i]], f1);
        fputs("\n", f1);
        //    }
    }
    fclose(f1);
}

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
    return 0;
}

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

int filesize(FILE* f)
{
    fseek(f, 0, 2);
    long length = ftell(f);
    fseek(f, 0, 0);
    return length;
}

int count_spaces(char* stroka, int n)
{
    int c = 1, i;
    for (i = 0; i < n; i++) {
        if (stroka[i] == ' ')
            c++;
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* f;
    f = fopen("word.txt", "r");
    if (f == NULL) {
        printf("Не удалось открыть файл \n");
        return -1;
    } else
        printf("Удалось открыть файл \n");
    int n = filesize(f);
    char* stroka = (char*)malloc(n * sizeof(char));
    fgets(stroka, n, f);
    int error = ignoring_characters(stroka);
    switch (error) {
    case 0:
        printf("Корректный ввод данных \n");
        break;
    case 1:
        printf("Файл пустой \n");
        break;
    case 2:
        printf("Введён неккоректный символ \n");
        break;
    case 3:
        printf("Слишком много пробелов между словами \n");
        break;
    }
    if (error > 0)
        return 0;
    int k = count_spaces(stroka, n);
    int* word = (int*)malloc(k * sizeof(int));
    word_splitting(stroka, word);
    printf("Отсортированная строка \n");
    ShakerSort(stroka, k, word);
    printf("\n");
    print(stroka, k, word);
    printf("Откройте файл sort.txt \n");
    fclose(f);
    return 0;
}