#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node *head = NULL, *tail = NULL;

struct Node* newNode(int v) {
	struct Node *n = malloc(sizeof(struct Node));
	n->data = v; n->next = NULL; return n;
}

void enqueue(int v) {
	struct Node *n = newNode(v);
	if (!head) head = tail = n;
	else tail->next = n, tail = n;
	printf("Enqueued %d\n", v);
}

void dequeue() {
	if (!head) { printf("Queue is empty\n"); return; }
	struct Node *t = head;
	printf("Dequeued %d\n", t->data);
	head = head->next; free(t);
	if (!head) tail = NULL;
}

void display() {
	if (!head) { printf("Queue is empty\n"); return; }
	printf("Queue elements: ");
	for (struct Node *t = head; t; t = t->next) printf("%d ", t->data);
	printf("\n");
}

void main() {
	int c = 0, v;
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
	while (c != 4) {
		printf("Enter choice: ");
		scanf("%d", &c);
		switch (c) {
			case 1: printf("Enter value: "); scanf("%d", &v); enqueue(v); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			case 4: printf("Exiting program\n"); break;
			default: printf("Invalid choice\n");
		}
	}
}
