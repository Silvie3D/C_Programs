#include <stdio.h>

void enqueue(int queue[], int *front, int *rear, int n) {
	int value;
	if (*rear == n - 1) {
		printf("Queue is full\n");
	} else {
		printf("Enter value: ");
		fflush(stdout);
		scanf("%d", &value);
		if (*front == -1)
			*front = 0;
		*rear = *rear + 1;
		queue[*rear] = value;
	}
}

void dequeue(int queue[], int *front, int *rear) {
	if (*front == -1 || *front > *rear) {
		printf("Queue is empty\n");
	} else {
		printf("Deleted: %d\n", queue[*front]);
		if (*front == *rear) {
			*front = -1;
			*rear = -1;
		} else {
			*front = *front + 1;
		}
	}
}

void display(int queue[], int front, int rear) {
	int i;
	if (front == -1 || front > rear) {
		printf("Queue is empty\n");
	} else {
		printf("Queue elements: ");
		for (i = front; i <= rear; i++) {
			printf("%d ", queue[i]);
		}
		printf("\n");
	}
}

void main() {
	int n, choice;
	int front = -1, rear = -1;

	printf("Enter queue size:\n");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Invalid size\n");
	} else {
		int queue[n];
		choice = 0;
		while (choice != 4) {
			printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
			printf("Enter choice:\n");
			scanf("%d", &choice);

			switch (choice) {
				case 1:
					enqueue(queue, &front, &rear, n);
					break;
				case 2:
					dequeue(queue, &front, &rear);
					break;
				case 3:
					display(queue, front, rear);
					break;
				case 4:
					break;
				default:
					printf("Invalid choice\n");
			}
		}
	}
}

