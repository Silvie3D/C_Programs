#include <stdio.h>

void insertArray(int arr[], int size) {
	printf("Enter %d elements:\n", size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
}

void sortArray(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j])
			merged[k++] = arr1[i++];
		else
			merged[k++] = arr2[j++];
	}
	while (i < size1)
		merged[k++] = arr1[i++];
	while (j < size2)
		merged[k++] = arr2[j++];
}

void main() {
	int n1, n2;

	printf("Enter size of first array: ");
	scanf("%d", &n1);
	printf("Enter size of second array: ");
	scanf("%d", &n2);

	int arr1[n1], arr2[n2], merged[n1 + n2];

	insertArray(arr1, n1);
	insertArray(arr2, n2);

	sortArray(arr1, n1);
	sortArray(arr2, n2);

	mergeArrays(arr1, n1, arr2, n2, merged);

	printf("\nMerged sorted array: ");
	for (int i = 0; i < n1 + n2; i++)
		printf("%d ", merged[i]);
}

