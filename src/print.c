#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char* stroka, int num, int* word)
{
    int i;
    FILE* f1;
    f1 = fopen("sort.txt", "w");
    for (i = 0; i < num; i++) {
        fputs(&stroka[word[i]], f1);
        fputs("\n", f1);
    }
    fclose(f1);
}
