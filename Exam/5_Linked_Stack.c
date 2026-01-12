#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node *head = NULL;

struct Node* newNode(int v) {
	struct Node *n = malloc(sizeof(struct Node));
	n->data = v; n->next = NULL; return n;
}

void push(int v) {
	struct Node *n = newNode(v);
	if (!head) head = n;
	else {
		struct Node *t = head;
		while (t->next) t = t->next;
		t->next = n;
	}
	printf("Pushed %d\n", v);
}

void pop() {
	if (!head) { printf("Stack is empty\n"); return; }
	if (!head->next) {
		printf("Popped %d\n", head->data);
		free(head); head = NULL; return;
	}
	struct Node *t = head, *p = NULL;
	while (t->next) { p = t; t = t->next; }
	printf("Popped %d\n", t->data);
	free(t); p->next = NULL;
}

void display() {
	if (!head) { printf("Stack is empty\n"); return; }
	printf("Stack elements: ");
	for (struct Node *t = head; t; t = t->next) printf("%d ", t->data);
	printf("\n");
}

void main() {
	int c = 0, v;
	printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
	while (c != 4) {
		printf("Enter choice: ");
		scanf("%d", &c);
		switch (c) {
			case 1: printf("Enter value: "); 
			scanf("%d", &v); push(v); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: printf("Exiting program\n"); break;
			default: printf("Invalid choice\n");
		}
	}
}
