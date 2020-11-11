#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

struct node { 
    int data; 
    struct node *next; 
}; 
  
int count(struct node* head); 
int getIntesectionNode(int d, struct node *head1, struct node *head2); 
  
int IntesectionNode(struct node *head1, struct node *head2){ 
    int c1 = count(head1); 
    int c2 = count(head2); 
    int diff; 
  
    if (c1 > c2) { 
        diff = c1 - c2; 
        return getIntesectionNode(diff, head1, head2); 
    } 
    else { 
        diff = c2 - c1; 
        return getIntesectionNode(diff, head2, head1); 
    } 
} 
  
int getIntesectionNode(int diff, struct node *head1, struct node *head2){ 
    int i; 
    struct node *curr1 = head1; 
    struct node *curr2 = head2; 
  
    for (i = 0; i < diff; i++) { 
        if (curr1 == NULL) { 
            return -1; 
        } 
        curr1 = curr1->next; 
    } 
  
    while (curr1 != NULL && curr2 != NULL) { 
        if (curr1 == curr2) 
        return curr1->data; 
        curr1 = curr1->next; 
        curr2 = curr2->next; 
    } 
  
    return -1; 
} 
  
int count(struct node *head) 
{ 
    struct node *ptr = head; 
    int count = 0; 
  
    while (ptr != NULL) { 
        count++; 
        ptr = ptr->next; 
    } 
  
    return count; 
} 

int main(int argc, char *argv[]){   
    struct node* newNode; 
    struct node* head1 = (struct node*)malloc(sizeof(struct node)); 
    head1->data = 10; 
  
    struct node* head2 = (struct node*)malloc(sizeof(struct node)); 
    head2->data = 3; 
  
    newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
    printf("\n The node of intersection is %d \n", IntesectionNode(head1, head2)); 
  
} 
