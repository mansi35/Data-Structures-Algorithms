#include <stdio.h> 
#include <stdlib.h> 

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

int count(struct Node* head, int search_for) 
{ 
    struct Node* current = head; 
    int count = 0; 
    while (current != NULL) { 
        if (current->data == search_for) 
            count++; 
        current = current->next; 
    } 
    return count; 
} 

int main() 
{
    struct Node* head = NULL; 

    push(&head, 1); 
    push(&head, 3); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 1);

    int dp[100] ={0};
    while (head != NULL)
    {
        if (dp[head->data] != 0) {
            printf("%d ", dp[head->data]);
            head = head->next;
        }
        else {
            dp[head->data] = count(head, head->data);
            printf("%d ", dp[head->data]);
            head = head->next;
        }
    }
    printf("\n");
    
    return 0; 
}