#include <stdio.h>

int queue[100], front = -1, rear = -1, n;

void enqueue() {
    int value;
    if (rear == n - 1) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d\n", queue[front++]);
    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void main() {
    int choice;
    printf("Enter size of queue: ");
    scanf("%d", &n);

    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); return;
            default: printf("Invalid choice\n");
        }
    }
}
