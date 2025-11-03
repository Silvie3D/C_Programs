#include <stdio.h>

void enqueue(int queue[], int *rear, int *front, int n) {
	int value;
	if (*rear == n - 1) {
		printf("Queue Overflow\n");
		return;
	}
	printf("Enter value to insert: ");
	scanf("%d", &value);
	if (*front == -1)
		*front = 0;
	(*rear)++;
	queue[*rear] = value;
	printf("Inserted %d into queue\n", value);
}

void dequeue(int queue[], int *rear, int *front) {
	if (*front == -1 || *front > *rear) {
		printf("Queue Underflow\n");
		return;
	}
	printf("Deleted %d from queue\n", queue[*front]);
	(*front)++;
	if (*front > *rear) {
		*front = *rear = -1;
	}
}

void display(int queue[], int rear, int front) {
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
	int n, choice, front = -1, rear = -1;
	int exit = 0;

	printf("Enter size of queue: ");
	scanf("%d", &n);

	int queue[n];

	while (exit == 0) {
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				enqueue(queue, &rear, &front, n);
				break;
			case 2:
				dequeue(queue, &rear, &front);
				break;
			case 3:
				display(queue, rear, front);
				break;
			case 4:
				printf("Exiting...\n");
				exit = 1;
				break;
			default:
				printf("Invalid choice\n");
		}
	}
}

