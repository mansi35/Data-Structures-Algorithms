#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void create(struct node **q)
{
  struct node *r,*t;
  int cnt, i, val;
  printf("How many nodes?");
  scanf("%d", &cnt);
  for(i = 0; i < cnt; i++)
    {
       printf("Enter the data %d  ", i);
       scanf("%d", &val);
       r = (struct node *) malloc (sizeof(struct node));
       r->data = val;
       r->next = NULL;

       if (*q == NULL)
       {
         *q = r;
       }
      else
      {
         t = *q;
         while (t->next != NULL)
           {
             t = t->next;
           }
         t->next = r;
       }
    }
}

void display(struct node **q)
{
  struct node *r;
  r = *q;
  while(r != NULL)
    {
      printf("%d->", r->data);
      r = r->next;
    }
  printf("\n");
}

void max(struct node **q)
{
  struct node *r;
  int max = 0;
  r = *q;
    while(r != NULL){
    if(r->data > max) {
        max = r->data;
        }
    r = r->next;
    }
  printf("The max is %d",max);  
  printf("\n");
}

int main()
{
  struct node *head;
  create(&head);
  display(&head);
  max(&head);
}