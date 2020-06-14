#include "print.h"
#include "sort.h"
#include "word_splitting.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// функция для определения размера файла
int filesize(FILE* f)
{
    fseek(f, 0, 2);
    long length = ftell(f);
    fseek(f, 0, 0);
    return length;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    FILE* f;
    f = fopen("word.txt", "r");
    if (f == NULL) {
        printf("Could not open file. (Не удалось открыть файл) \n");
        return -1;
    } else
        printf("I managed to open the file (Удалось открыть файл) \n");
    int n = filesize(f); // в переменную n записываем размер файла
    char* stroka
            = (char*)malloc(n * sizeof(char)); // выделяем память под строку
    fgets(stroka, n, f);
    int error = ignoring_characters(stroka);
    switch (error) {
    case 0:
        printf("Correct data entry (Корректный ввод данных)\n");
        break;
    case 1:
        printf("File is empty (Файл пустой) \n");
        break;
    case 2:
        printf("Incorrect symbol entered (Введён неккоректный символ) \n");
        break;
    case 3:
        printf("Too many spaces between words (Слишком много пробелов между "
               "словами) \n");
        break;
    case 4:
        printf("There should not be a space first (Сначала не должен стоять "
               "пробел) \n");
        break;
    }
    if (error > 0)
        return 0;
    int k = count_spaces(stroka, n);
    int* word = (int*)malloc(k * sizeof(int));
    word_splitting(stroka, word);
    printf("Sorted row (Отсортированная строка) \n");
    ShakerSort(stroka, k, word);
    printf("\n");
    print(stroka, k, word);
    printf("Open the sort.txt file to view (Откройте файл sort.txt для "
           "просмотра)\n");
    fclose(f);
    return 0;
}