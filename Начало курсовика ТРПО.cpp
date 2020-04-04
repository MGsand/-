
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
  char *sort_char_array[] = { "about", "this", "and", "url", "that", "the", "i", "hi" };
  int i;//счётчик
 
  //сортировка по возрастанию
  qsort (sort_char_array, 8, sizeof(char**), comp1); //about and hi i that the this url
 
  //ввывод результатов на экран
  for(i=0; i<8; i++)
	cout<<sort_char_array[i]<<" ";
  cout<<"\n";
 
  //сортировка по убыванию
  qsort (sort_char_array, 8, sizeof(char**), comp2);//url this the that i hi and about
 
  //ввывод результатов на экран
  for(i=0; i<8; i++)
	cout<<sort_char_array[i]<<" ";
  cout<<"\n";
 
  system("pause");}
