#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};

void insertFirst(struct Node **head, int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = *head;
	if (*head != NULL)
		(*head)->prev = newNode;
	*head = newNode;
	printf("Node with value %d inserted at beginning\n", value);
}

void insertLast(struct Node **head, int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;

	if (*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;
	} else {
		struct Node *temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}
	printf("Node with value %d inserted at end\n", value);
}

void insertAtPosition(struct Node **head, int pos, int value) {
	if (pos < 1) {
		printf("Invalid position\n");
		return;
	}

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->prev = newNode->next = NULL;

	if (pos == 1) {
		newNode->next = *head;
		if (*head != NULL)
			(*head)->prev = newNode;
		*head = newNode;
		printf("Inserted %d at position %d\n", value, pos);
		return;
	}

	struct Node *temp = *head;
	int i;
	for (i = 1; i < pos - 1 && temp != NULL; i++)
		temp = temp->next;

	if (temp == NULL) {
		printf("Invalid position\n");
		free(newNode);
		return;
	}

	newNode->next = temp->next;
	newNode->prev = temp;
	if (temp->next != NULL)
		temp->next->prev = newNode;
	temp->next = newNode;

	printf("Inserted %d at position %d\n", value, pos);
}

void deleteFirst(struct Node **head) {
	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node *temp = *head;
	printf("Deleted value: %d\n", temp->data);
	*head = temp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}

void deleteAtPosition(struct Node **head, int pos) {
	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node *temp = *head;

	if (pos == 1) {
		deleteFirst(head);
		return;
	}

	int i;
	for (i = 1; i < pos && temp != NULL; i++)
		temp = temp->next;

	if (temp == NULL) {
		printf("Invalid position\n");
		return;
	}

	printf("Deleted value: %d\n", temp->data);
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	free(temp);
}

void deleteLast(struct Node **head) {
	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct Node *temp = *head;
	if (temp->next == NULL) {
		printf("Deleted value: %d\n", temp->data);
		free(temp);
		*head = NULL;
		return;
	}

	while (temp->next != NULL)
		temp = temp->next;

	printf("Deleted value: %d\n", temp->data);
	temp->prev->next = NULL;
	free(temp);
}

void display(struct Node *head) {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	struct Node *temp = head;
	printf("Doubly Linked List (forward): ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main() {
	struct Node *head = NULL;
	int choice = 0, value, pos;

	while (choice != 8) {
		printf("\n1. Insert at beginning\n");
		printf("2. Insert at position\n");
		printf("3. Insert at end\n");
		printf("4. Delete from beginning\n");
		printf("5. Delete from position\n");
		printf("6. Delete from end\n");
		printf("7. Display\n");
		printf("8. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				insertFirst(&head, value);
				break;
			case 2:
				printf("Enter position: ");
				scanf("%d", &pos);
				printf("Enter value: ");
				scanf("%d", &value);
				insertAtPosition(&head, pos, value);
				break;
			case 3:
				printf("Enter value: ");
				scanf("%d", &value);
				insertLast(&head, value);
				break;
			case 4:
				deleteFirst(&head);
				break;
			case 5:
				printf("Enter position: ");
				scanf("%d", &pos);
				deleteAtPosition(&head, pos);
				break;
			case 6:
				deleteLast(&head);
				break;
			case 7:
				display(head);
				break;
			case 8:
				printf("Exiting program\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}

