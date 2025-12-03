#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void enqueue(struct Node **head, struct Node **tail, int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
		*tail = newNode;
	} else {
		(*tail)->next = newNode;
		*tail = newNode;
	}
	printf("Enqueued %d into queue\n", value);
}

void dequeue(struct Node **head, struct Node **tail) {
	if (*head == NULL) {
		printf("Queue is empty\n");
		return;
	}
	struct Node *temp = *head;
	printf("Dequeued %d from queue\n", temp->data);
	*head = (*head)->next;
	free(temp);
	if (*head == NULL) {
		*tail = NULL;
	}
}

void display(struct Node *head) {
	if (head == NULL) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements: ");
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main() {
	struct Node *head = NULL;
	struct Node *tail = NULL;
	int choice = 0, value;
	while (choice != 4) {
		printf("\n1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter value to enqueue: ");
				scanf("%d", &value);
				enqueue(&head, &tail, value);
				break;
			case 2:
				dequeue(&head, &tail);
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

