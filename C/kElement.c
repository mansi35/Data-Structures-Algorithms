#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

int getKthFromtheEnd(struct Node* node, int k)
{
	if (node == NULL)
		return 0;

	int count = getKthFromtheEnd(node->next, k) + 1;

	if (count == k)
		printf("K'th node from the end is %d", node->data);

	return count;
}

int main(void)
{
	int keys[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(keys) / sizeof(keys[0]);

	struct Node* head = NULL;
	for (int i = n - 1; i >= 0; i--)
		push(&head, keys[i]);

	int k = 3;
	getKthFromtheEnd(head, k);

	return 0;
}