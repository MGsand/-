
#include <iostream> // ���������� cout
#include <stdio.h>
#include <string.h> // ���������� ���������� ��������� �����
using namespace std; // ����� �� ���������� std

int ii = 0; //���������� �������� �� q

void Shellsort(char* A, int N)
{
    int h = 2, i, j, k, T;
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

/*

void Shellsort(char* A, int N)
{
        /*
        if(strlen(text) == 1){
        text = new char(1);
        text[0] = a;}
        */
// else{
/*text= new char[ii];
text[ii] = ch;
ii++;
text=new char[ii];
text[ii] = '\0';

//	printf("before %c      %s ",a, text);
for (int i=0; i<ii; i++)
{
char c = text[i];
printf("%c", c);
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
*/
void f(int i, char*& p)
{
    char a;
    ii++;
    scanf("%c", &a); //////////////////  scanf("% DDDDD  CCCC   c",&a);
    if (a == 'q') {
        p = new char[i + 1];
        p[i] = a;
        return;
    }
    f(i + 1, p);
    p[i] = a;
    printf("%d %c\n", i, a);
}

int main()
{
    char* text;
    // text = new char(1);
    char* p;

    printf("Vvedite stroki slov. q = zakanchivaet \n");

    f(0, p);

    /*
   //printf("ghghg");
     int i,j;
     char a='1';
     while (a!= 'q') {
           scanf("%c",&a);
           if((a>= 'A') && ( a<='Z') || (a>= 'a') && (a<= 'z'))
           {

                    AddToSorted(a,text);

             }
     }
     text[ii+1]='\0';
       */
    for (int j = 0; p[j]; j++)
        printf("%c,", p[j]);
    printf("\n");

    printf("\n%d = lenth\n", ii);
    Shellsort(p, ii);

    printf("Result is...");

    for (int j = 0; p[j]; j++)
        printf("%c,", p[j]);
    printf("\n");
    system("pause");
}
