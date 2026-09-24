/* Q4> Implement a full binary tree with n number of nodes using array*/

#include <stdio.h>

#define MAX 100

int tree[MAX];
int n;

void create() {
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &tree[i]);
    }
}

void preorder(int i) {
    if (i >= n)
        return;

    printf("%d ", tree[i]);
    preorder(2 * i + 1);
    preorder(2 * i + 2);
}

void inorder(int i) {
    if (i >= n)
        return;

    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}

void postorder(int i) {
    if (i >= n)
        return;

    postorder(2 * i + 1);
    postorder(2 * i + 2);
    printf("%d ", tree[i]);
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of nodes\n");
        return 0;
    }
    create();
    printf("Preorder: ");
    preorder(0);
    printf("\nInorder: ");
    inorder(0);
    printf("\nPostorder: ");
    postorder(0);

    printf("\n");
    return 0;
}