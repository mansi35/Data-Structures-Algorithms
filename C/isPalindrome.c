#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
} *tail;
struct Node* head;

struct Node* createNode(int val){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = val;
	temp -> next = NULL;
	return temp;
};
struct Node* insertNode(struct Node* new_node){
	if(head == NULL){
		head = new_node;
		tail = head;
	}else{
		tail->next = new_node;
		tail = new_node;
	}
}

struct Node* printList(struct Node* head){
	struct Node* temp = head;
	printf("List: ");
	while(temp != NULL){
		printf("%d ",temp -> data);
	}
}

int isPal(struct Node* head, int n){
	int i = 0, j;
    struct Node *front = head, *rear = NULL;
 
    while (i != n / 2){
        for (j = 0; j < i; j++){
            front = front->next;
        }
        for (j = 0; j <n - (i + 1); j++){
            rear = rear->next;
        }
        if (front->data != rear->data){
            return 0;
        }
        else{
            i++;
        }
    }
    return 1;
}
void release (struct Node **head)
{
    struct Node *temp = *head;
 
    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
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
	int result = isPal(head, n);
	if(result == 1){
		printf("True");
	}else if(result == 0){
		printf("False");
	}
	release(&head);
}
