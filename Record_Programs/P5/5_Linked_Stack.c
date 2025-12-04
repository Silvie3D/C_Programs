#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void push(struct Node **head, int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
	} else {
		struct Node *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	printf("Pushed %d\n", value);
}

void pop(struct Node **head) {
	if (*head == NULL) {
		printf("Stack is empty\n");
		return;
	}
	if ((*head)->next == NULL) {
		printf("Popped %d\n", (*head)->data);
		free(*head);
		*head = NULL;
		return;
	}
	struct Node *temp = *head;
	struct Node *prev = NULL;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	printf("Popped %d\n", temp->data);
	free(temp);
	prev->next = NULL;
}

void display(struct Node *head) {
	if (head == NULL) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements: ");
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main() {
	struct Node *head = NULL;
	int choice = 0, value;
	printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
	while (choice != 4) {
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				push(&head, value);
				break;
			case 2:
				pop(&head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				printf("Exiting program\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}

