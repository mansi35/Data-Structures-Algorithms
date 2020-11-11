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
	middleNode(start);
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
	 
void middleNode(struct node *start){  
    struct node *slow = start;  
    struct node *fast = start;  
  
    if (start!=NULL)  
    {  
        while (fast != NULL && fast->next != NULL)  
        {  
            fast = fast->next->next;  
            slow = slow->next;  
        }  
        printf("\n The middle element is %d\n\n", slow->data);  
    }  
}  

