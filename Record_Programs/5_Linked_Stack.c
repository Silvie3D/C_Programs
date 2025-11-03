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
	printf("Pushed %d onto stack\n", value);
}

void pop(struct Node **head) {
	if (*head == NULL) {
		printf("Stack is empty\n");
		return;
	}
	if ((*head)->next == NULL) {
		printf("Popped %d from stack\n", (*head)->data);
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
	printf("Popped %d from stack\n", temp->data);
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
	while (choice != 4) {
		printf("\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value to push: ");
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

