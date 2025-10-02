#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void insertLast(struct Node **head, int value) {
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
	printf("Node with value %d inserted at end\n", value);
}

void deleteLast(struct Node **head) {
	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}
	if ((*head)->next == NULL) {
		printf("Deleted value: %d\n", (*head)->data);
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
	printf("Deleted value: %d\n", temp->data);
	free(temp);
	prev->next = NULL;
}

void insertAtPosition(struct Node **head, int pos, int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if (pos == 1) {
		newNode->next = *head;
		*head = newNode;
		printf("Inserted %d at position %d\n", value, pos);
		return;
	}
	struct Node *temp = *head;
	int i;
	for (i = 1; i < pos - 1 && temp != NULL; i++) {
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Invalid position\n");
		free(newNode);
	} else {
		newNode->next = temp->next;
		temp->next = newNode;
		printf("Inserted %d at position %d\n", value, pos);
	}
}

void deleteAtPosition(struct Node **head, int pos) {
	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node *temp = *head;
	if (pos == 1) {
		*head = (*head)->next;
		printf("Deleted value: %d\n", temp->data);
		free(temp);
		return;
	}
	struct Node *prev = NULL;
	int i;
	for (i = 1; i < pos && temp != NULL; i++) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("Invalid position\n");
	} else {
		prev->next = temp->next;
		printf("Deleted value: %d\n", temp->data);
		free(temp);
	}
}

void display(struct Node *head) {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node *temp = head;
	printf("Linked List elements: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main() {
	struct Node *head = NULL;
	int choice = 0, value, pos;
	while (choice != 6) {
		printf("\n1. Insert at end\n");
		printf("2. Delete from end\n");
		printf("3. Insert at position\n");
		printf("4. Delete from position\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				insertLast(&head, value);
				break;
			case 2:
				deleteLast(&head);
				break;
			case 3:
				printf("Enter position: ");
				scanf("%d", &pos);
				printf("Enter value: ");
				scanf("%d", &value);
				insertAtPosition(&head, pos, value);
				break;
			case 4:
				printf("Enter position: ");
				scanf("%d", &pos);
				deleteAtPosition(&head, pos);
				break;
			case 5:
				display(head);
				break;
			case 6:
				printf("Exiting program\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}

