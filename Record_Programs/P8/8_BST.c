#include <stdio.h>

int bst[1000];

void insert(int x) {
    int i = 1;
    while (i < 1000) {
        if (bst[i] == 0) {
            bst[i] = x;
            return;
        }
        if (x < bst[i]) i = 2 * i;
        else i = 2 * i + 1;
    }
}

void inorder(int i) {
    if (i >= 1000 || bst[i] == 0) return;
    inorder(2 * i);
    printf("%d ", bst[i]);
    inorder(2 * i + 1);
}

int main() {
    int n, x;
    printf("How many values: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(x);
    }

    printf("Inorder: \n");
    inorder(1);
    return 0;
}
