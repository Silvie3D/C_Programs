#include <stdio.h>

int q[5];
int front = -1, rear = -1, n = 5;

void enqueue(int x) {
    if ((front == 0 && rear == n - 1) || (rear + 1 == front)) return;
    if (front == -1) front = rear = 0;
    else if (rear == n - 1) rear = 0;
    else rear++;
    q[rear] = x;
}

void dequeue(void) {
    if (front == -1) return;
    if (front == rear) front = rear = -1;
    else if (front == n - 1) front = 0;
    else front++;
}

void display(void) {
    int i = front;
    while (i != rear) {
        printf("%d ", q[i]);
        i = (i + 1) % n;
    }
    if (front != -1) printf("%d", q[rear]);
    printf("\n");
}

void main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    display();
}
