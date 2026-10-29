/* Q3> WAP program to calculate number of rotations to balance the BST. Originally BST
       have 10 nodes ->      a
                        b       c
                      d      h  i
                    e  f    j
                      g             input should be inorder*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int rotations = 0;

int countNodes(struct Node *root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

struct Node* balanceBST(struct Node *root) {
    struct Node dummy;
    dummy.left = NULL;
    dummy.right = root;

    struct Node *tail = &dummy;
    struct Node *rest = root;

    while (rest != NULL) {
        if (rest->left != NULL) {
            struct Node *temp = rest->left;

            rest->left = temp->right;
            temp->right = rest;
            tail->right = temp;

            rest = temp;
            rotations++;
        } else {
            tail = rest;
            rest = rest->right;
        }
    }

    int n = countNodes(dummy.right);
    int m = 1;

    while (m <= n + 1)
        m *= 2;

    m = m / 2 - 1;

    struct Node *scanner = &dummy;

    int k = n - m;

    for (int i = 0; i < k; i++) {
        struct Node *child = scanner->right;
        struct Node *grand = child->right;

        scanner->right = grand;
        child->right = grand->left;
        grand->left = child;

        scanner = grand;
        rotations++;
    }

    while (m > 1) {
        m /= 2;
        scanner = &dummy;

        for (int i = 0; i < m; i++) {
            struct Node *child = scanner->right;
            struct Node *grand = child->right;

            scanner->right = grand;
            child->right = grand->left;
            grand->left = child;

            scanner = grand;
            rotations++;
        }
    }

    return dummy.right;
}

int main() {
    struct Node *root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter BST insertion elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    root = balanceBST(root);

    printf("Number of rotations = %d\n", rotations);


    return 0;
}