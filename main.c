#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char String[3000];
int Words[1500];
int Number;

int main()
{
    int i, j, temp;
    int flag;
    printf("Введите строку > \n");
    gets(String);
    for (Number = 0, flag = 1, i = 0; String[i]; i++) {
        if (String[i] == ' ') {
            String[i] = 0;
            flag = 1;
        } else if (flag) {
            Words[Number++] = i;
            flag = 0;
        }
    }
    for (j = Number - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0) {
                temp = Words[i];
                Words[i] = Words[i + 1];
                Words[i + 1] = temp;
            }
    for (i = 0; i < Number; i++)
        printf("%s ", &String[Words[i]]);
    return 0;
}