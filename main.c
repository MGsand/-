#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st{
  char slovo[20];
  struct st* next;
}spis;

spis* create(){
  spis* lst;
  lst = new spis;
  lst->next = NULL;
  return (lst);
}

spis* addElement(spis* lst){
  char slovo[20];
  spis *temp;
  temp = new spis;
//  printf("Введите слово: ");
  scanf("%s",slovo);
  lst->next = temp;
  temp->next = NULL;
  strcpy(temp->slovo,slovo);
  return (temp);
}

void listPrint(spis* head){
  spis* p;
  p = head->next;
  while(p != NULL){
    printf("%s\n",p->slovo);
    p = p->next;
  }
}

void sortList(spis* head){
  spis *p, *t1, *t2;
  int i;
  do{
    i = 0;
    for(p = head; p->next->next; p = p->next){
      t1 = p->next;
      t2 = t1->next;
      if(strcmp(t1->slovo,t2->slovo) > 0){
        p->next = t2;
        t1->next = t2->next;
        t2->next = t1;
        i = 1;
        }
    }
  }while(i);
}

void freeSpis(spis* head){
  spis *p, *q;
  q = p = head;
  while(p != NULL){
    p = q->next;
    delete(q);
    q = p;
  }
  head = NULL;
}

int main(){
  setlocale(LC_ALL,"Russian");
  spis *head, *p;
  int i, n;
  printf("Введите количество слов в списке: ");
  scanf("%d",&n);
  head = create();
  p = head;
  for(i = 0; i < n; i++){
    p = addElement(p);
  }
  printf("Исходный список\n");
  listPrint(head);
  printf("Отсортированный список\n");
  sortList(head);
  listPrint(head);
  freeSpis(head);
  return 0;
}