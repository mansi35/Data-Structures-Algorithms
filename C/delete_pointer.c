#include <stdio.h>
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
	printf("\n Initial linked list: ");
	start=display(start);
	delete_particular(start);
	printf("\n Linked list after deleting the node to which pointer is given: ");
	start=display(start);
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
	 
	void delete_particular(struct node *start){  
	struct node* temp;
    if (start->next == NULL) 
    { 
        free(start);  
        return; 
    } 
    temp = start->next; 
    start->data = temp->data; 
    start->next = temp->next; 
    free(temp); 
}  

