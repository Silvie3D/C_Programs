#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node *head = NULL;

struct Node* newNode(int v) {
	struct Node *n = malloc(sizeof(struct Node));
	n->data = v; n->next = NULL; return n;
}

void insertFirst(int v) {
	struct Node *n = newNode(v);
	n->next = head; head = n;
	printf("Node with value %d inserted at beginning\n", v);
}

void insertLast(int v) {
	struct Node *n = newNode(v);
	if (!head) head = n;
	else {
		struct Node *t = head;
		while (t->next) t = t->next;
		t->next = n;
	}
	printf("Node with value %d inserted at end\n", v);
}

void insertAtPosition(int pos, int v) {
	if (pos == 1) { insertFirst(v); return; }
	struct Node *t = head;
	for (int i = 1; i < pos - 1 && t; i++) t = t->next;
	if (!t) { printf("Invalid position\n"); return; }
	struct Node *n = newNode(v);
	n->next = t->next; t->next = n;
	printf("Inserted %d at position %d\n", v, pos);
}

void deleteFirst() {
	if (!head) { printf("List is empty\n"); return; }
	struct Node *t = head;
	printf("Deleted value: %d\n", t->data);
	head = head->next; free(t);
}

void deleteAtPosition(int pos) {
	if (!head) { printf("List is empty\n"); return; }
	if (pos == 1) { deleteFirst(); return; }
	struct Node *t = head, *p = NULL;
	for (int i = 1; i < pos && t; i++) { p = t; t = t->next; }
	if (!t) { printf("Invalid position\n"); return; }
	p->next = t->next;
	printf("Deleted value: %d\n", t->data);
	free(t);
}

void deleteLast() {
	if (!head) { printf("List is empty\n"); return; }
	if (!head->next) { printf("Deleted value: %d\n", head->data); free(head); head = NULL; return; }
	struct Node *t = head, *p = NULL;
	while (t->next) { p = t; t = t->next; }
	p->next = NULL;
	printf("Deleted value: %d\n", t->data);
	free(t);
}

void display() {
	if (!head) { printf("List is empty\n"); return; }
	printf("Linked List elements: ");
	for (struct Node *t = head; t; t = t->next) printf("%d ", t->data);
	printf("\n");
}

void main() {
	int c = 0, v, pos;
	printf("\n1.Insert at beginning\n2.Insert at position\n3.Insert at end\n4.Delete from beginning\n5.Delete from position\n6.Delete from end\n7.Display\n8.Exit\n");
	while (c != 8) {
		printf("Enter choice: ");
		scanf("%d", &c);
		switch (c) {
			case 1: printf("Enter value: "); scanf("%d", &v); insertFirst(v); break;
			case 2: printf("Enter position: "); scanf("%d", &pos); printf("Enter value: "); scanf("%d", &v); insertAtPosition(pos, v); break;
			case 3: printf("Enter value: "); scanf("%d", &v); insertLast(v); break;
			case 4: deleteFirst(); break;
			case 5: printf("Enter position: "); scanf("%d", &pos); deleteAtPosition(pos); break;
			case 6: deleteLast(); break;
			case 7: display(); break;
			case 8: printf("Exiting program\n"); break;
			default: printf("Invalid choice\n");
		}
	}
}
