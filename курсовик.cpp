
#include <stdlib.h>
#include <string.h>     // подключаем библиотеку обработки строк
#include <iostream>     // подключаем cout
 
//функция для сортировки строк по возрастанию
int comp1 (const void * a, const void * b)
{
  return strcmp(*(char**)a,*(char**)b);
}
 
//функция для сортировки строк по убыванию
int comp2 (const void * a, const void * b)
{
  return -strcmp(*(char**)a,*(char**)b);
}
 
using namespace std; // чтобы не подключать std
 
int main ()
{
  char **text;
  int i,j;
  *text=new char(20);
  for(i=0;i<20;i++)
  text[i]=new char(20);
  for(i=0;i<20;i++)
   for(j=0;j<20;j++)
   cout<<text[i][j]<<cin;
  //сортировка по возрастанию
  qsort (text, 20, sizeof(char**), comp1); //about and hi i that the this url
 
  //ввывод результатов на экран
  for(i=0; i<20; i++)
	cout<<text[i]<<" ";
  cout<<"\n";
 
  //сортировка по убыванию
  qsort (text, 20, sizeof(char**), comp2);//url this the that i hi and about
 
  //ввывод результатов на экран
  for(i=0; i<8; i++)
	cout<<text[i]<<" ";
  cout<<"\n";
 
  system("pause");}
