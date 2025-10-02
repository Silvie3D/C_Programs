#include <stdio.h>

void enqueue(int queue[], int *front, int *rear, int n) {
	int value;
	if ((*front == 0 && *rear == n - 1) || (*rear + 1 == *front)) {
		printf("Queue is full\n");
	} else {
		printf("Enter value: ");
		scanf("%d", &value);
		if (*front == -1) {
			*front = 0;
			*rear = 0;
			queue[*rear] = value;
		} else if (*rear == n - 1 && *front != 0) {
			*rear = 0;
			queue[*rear] = value;
		} else {
			*rear = *rear + 1;
			queue[*rear] = value;
		}
	}
}

void dequeue(int queue[], int *front, int *rear, int n) {
	if (*front == -1) {
		printf("Queue is empty\n");
	} else {
		printf("Deleted %d\n", queue[*front]);
		if (*front == *rear) {
			*front = -1;
			*rear = -1;
		} else if (*front == n - 1) {
			*front = 0;
		} else {
			*front = *front + 1;
		}
	}
}

void display(int queue[], int front, int rear, int n) {
	int i;
	if (front == -1) {
		printf("Queue is empty\n");
	} else {
		printf("Queue elements: ");
		if (rear >= front) {
			for (i = front; i <= rear; i++) {
				printf("%d ", queue[i]);
			}
		} else {
			for (i = front; i < n; i++) {
				printf("%d ", queue[i]);
			}
			for (i = 0; i <= rear; i++) {
				printf("%d ", queue[i]);
			}
		}
		printf("\n");
	}
}

void main() {
	int n;
	int front = -1;
	int rear = -1;
	int choice = 0;

	printf("Enter queue size: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Invalid size\n");
	} else {
		int queue[n];
		while (choice != 4) {
			printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
			printf("Enter choice: ");
			scanf("%d", &choice);

			switch (choice) {
				case 1:
					enqueue(queue, &front, &rear, n);
					break;
				case 2:
					dequeue(queue, &front, &rear, n);
					break;
				case 3:
					display(queue, front, rear, n);
					break;
				case 4:
					break;
				default:
					printf("Invalid choice\n");
			}
		}
	}
}

