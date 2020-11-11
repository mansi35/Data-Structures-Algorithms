#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *createll(struct node *);
struct node *display(struct node *);

int main(int argc, char *argv[]){
	
	start=createll(start);
	printf("\n Our linked list: ");
	start=display(start);
	start->next->next->next->next->next = start->next;
	hasCycle(start);
	return 0;
}

struct node *createll(struct node *start){
	 	struct node *ptr;
	 	struct node *new_node;
	 	int num;
		printf("\n Enter -1 to end");
		printf("\n Enter the data : ");
		scanf("%d", &num);
		while(num!=-1){
			 new_node = (struct node *)malloc(sizeof(struct node));
			 new_node -> data=num;
			 if(start==NULL){
				 new_node -> next = NULL;
				 start = new_node;
			 }
			 else{
				 ptr=start;
				 while(ptr->next!=NULL)
				 ptr=ptr->next;
				 ptr->next = new_node;
				 new_node->next=NULL;
			 }
			 printf("\n Enter the data : ");
			 scanf("%d", &num);
		}
		return start;
	 }
	 
	 struct node *display(struct node *start){
	 	struct node *ptr;
		ptr = start;
		while(ptr != NULL){
			 printf("\t %d", ptr -> data);
			 ptr = ptr -> next;
		}
		return start;
	 }
	 
	void hasCycle(struct node *start){  
	
    struct node *slow = start;  
    struct node *fast = start;  
  
   	while(slow && fast && fast->next) {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           printf("\n Linked List contains a cycle\n");
           printf("\n Node at which loop starts: %d", slow->data);
           return;
        }
    }
    printf("\n Linked List does not contain cycle\n");
}  

