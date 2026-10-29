/* Q1> WAP to create an AVL tree from input given by user one at a time.
       Tree should be represented using an Array. Input should be inorder */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int key[MAX], left[MAX], right[MAX], height[MAX];
int n = 0, root = -1;

int max(int a, int b) {
    return a > b ? a : b;
}

int newNode(int x) {
    int i = n++;
    key[i] = x;
    left[i] = right[i] = -1;
    height[i] = 1;
    return i;
}

int h(int i) {
    return i == -1 ? 0 : height[i];
}

int balance(int i) {
    return i == -1 ? 0 : h(left[i]) - h(right[i]);
}

int rotateRight(int y) {
    int x = left[y];
    int t = right[x];

    right[x] = y;
    left[y] = t;

    height[y] = 1 + max(h(left[y]), h(right[y]));
    height[x] = 1 + max(h(left[x]), h(right[x]));

    return x;
}

int rotateLeft(int x) {
    int y = right[x];
    int t = left[y];

    left[y] = x;
    right[x] = t;

    height[x] = 1 + max(h(left[x]), h(right[x]));
    height[y] = 1 + max(h(left[y]), h(right[y]));

    return y;
}

int insert(int node, int x) {
    if (node == -1)
        return newNode(x);

    if (x < key[node])
        left[node] = insert(left[node], x);
    else if (x > key[node])
        right[node] = insert(right[node], x);
    else
        return node;

    height[node] = 1 + max(h(left[node]), h(right[node]));

    int b = balance(node);

    if (b > 1 && x < key[left[node]])
        return rotateRight(node);

    if (b < -1 && x > key[right[node]])
        return rotateLeft(node);

    if (b > 1 && x > key[left[node]]) {
        left[node] = rotateLeft(left[node]);
        return rotateRight(node);
    }

    if (b < -1 && x < key[right[node]]) {
        right[node] = rotateRight(right[node]);
        return rotateLeft(node);
    }

    return node;
}

void inorder(int node) {
    if (node == -1) return;
    inorder(left[node]);
    printf("%d ", key[node]);
    inorder(right[node]);
}


int main() {
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("\nInorder: ");
    inorder(root);

    return 0;
}