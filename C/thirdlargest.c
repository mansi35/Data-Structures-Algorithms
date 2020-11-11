#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

struct Node { 
    int data; 
    struct Node* next; 
}; 

void push(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  

int listSize(struct Node* node)
{ 
    int count = 0; 
    while (node != NULL) { 
        count++; 
  
        node = node->next; 
    } 
    return count; 
} 

void print3largest(struct Node* head) 
{ 
    int i, first, second, third; 
    int list_size = listSize(head); 

    if (list_size < 2) { 
        printf("Invalid Input"); 
        return; 
    } 
  
    second = third = INT_MIN; 
  
    struct Node* temp = head;
    first = temp->data;
    temp = temp->next;

    while (temp != NULL) { 
        if (temp->data > first) {
            third = second; 
            second = first;
            first = temp->data; 
        } 

        else if (temp->data > second && temp->data != first) 
        {
            third = second;
            second = temp->data; 
        }

        else if (temp->data > third && temp->data != first) 
        {
            third = temp->data; 
        }
  
        temp = temp->next; 
    } 
  
    if (third == INT_MIN) 
        printf("There is no second largest element\n"); 
    else
        printf("The third largest element is %d \n", third); 
} 

int main() 
{ 
    struct Node* start = NULL;

    push(&start, 1);
    push(&start, 34);
    push(&start, 10);
    push(&start, 1);
    push(&start, 35);
    push(&start, 12);
  
    print3largest(start);
  
    return 0; 
} 