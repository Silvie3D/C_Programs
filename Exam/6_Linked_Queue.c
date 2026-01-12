#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
struct Node *head = NULL, *tail = NULL;

void enqueue(int v) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = v; n->next = NULL;
    if (!head) head = tail = n;
    else tail->next = n, tail = n;
}

void dequeue(void) {
    if (!head) return;
    struct Node *t = head;
    head = head->next;
    free(t);
    if (!head) tail = NULL;
}

void display(void) {
    for (struct Node *t = head; t; t = t->next)
        printf("%d ", t->data);
    printf("\n");
}

void main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();  
    display();  
}
