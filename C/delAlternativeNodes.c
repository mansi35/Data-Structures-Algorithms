#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
} *tail;
struct Node* start;

struct Node* createNode(int val){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = val;
	temp -> next = NULL;
	return temp;
};
struct Node* insertNode(struct Node* new_node){
	if(start == NULL){
		start = new_node;
		tail = start;
	}else{
		tail->next = new_node;
		tail = new_node;
	}
}
struct Node* print_list(struct Node* start, int n){
	struct Node* temp;
	int j = 1;
	if(start == NULL){
		printf("No data found!");
	}
	else{
		temp = start;
		printf("List: ");
		while( temp != NULL){
			printf("%d ", temp -> data);
			j++;
			temp = temp -> next;
		}
	}
}

struct Node* deleteAlt(struct Node* start){
	struct Node* prev = start;
	struct Node* node = start -> next;
	
	while(prev != NULL && node != NULL){
		prev -> next = node -> next;
		free(node);
		prev = prev -> next;
		if(prev != NULL){
			node = node -> next;
		}
	}
	return start;
}

int main(){
	int n,x;
	printf("Enter the number of elements in the list: ");
	scanf("%d" ,&n);
	printf("Enter the elements: ");
	while(n--){
		scanf("%d", &x);
		struct Node *new_node = createNode(x);
		insertNode(new_node);
	} 
	deleteAlt(start);
	print_list(start,n);
}

