#include <stdio.h>

void push(int stack[], int *top, int n) {
	int value;
	if (*top == n - 1)
		printf("Stack Overflow\n");
	else {
		printf("Enter value to push: ");
		scanf("%d", &value);
		(*top)++;
		stack[*top] = value;
	}
}

void pop(int stack[], int *top) {
	if (*top == -1)
		printf("Stack Underflow\n");
	else {
		printf("Popped value: %d\n", stack[*top]);
		(*top)--;
	}
}

void display(int stack[], int top) {
	if (top == -1)
		printf("Stack is empty\n");
	else {
		printf("Stack elements:\n");
		for (int i = top; i >= 0; i--)
			printf("%d\n", stack[i]);
	}
}

void main() {
	int stack[100];
	int top = -1;
	int n, choice;

	printf("Enter the size of stack: ");
	scanf("%d", &n);

	do {
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1: push(stack, &top, n); break;
			case 2: pop(stack, &top); break;
			case 3: display(stack, top); break;
			case 4: printf("Exiting...\n"); break;
			default: printf("Invalid choice\n");
		}
	} while (choice != 4);
}

