
#include <stdlib.h>
#include <string.h>     // ���������� ���������� ��������� �����
#include <iostream>     // ���������� cout
 
//������� ��� ���������� ����� �� �����������
int comp1 (const void * a, const void * b)
{
  return strcmp(*(char**)a,*(char**)b);
}
 
//������� ��� ���������� ����� �� ��������
int comp2 (const void * a, const void * b)
{
  return -strcmp(*(char**)a,*(char**)b);
}
 
using namespace std; // ����� �� ���������� std
 
int main ()
{
  char *sort_char_array[] = { "about", "this", "and", "url", "that", "the", "i", "hi" };
  int i;//�������
 
  //���������� �� �����������
  qsort (sort_char_array, 8, sizeof(char**), comp1); //about and hi i that the this url
 
  //������ ����������� �� �����
  for(i=0; i<8; i++)
	cout<<sort_char_array[i]<<" ";
  cout<<"\n";
 
  //���������� �� ��������
  qsort (sort_char_array, 8, sizeof(char**), comp2);//url this the that i hi and about
 
  //������ ����������� �� �����
  for(i=0; i<8; i++)
	cout<<sort_char_array[i]<<" ";
  cout<<"\n";
 
  system("pause");}
