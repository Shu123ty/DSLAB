/* Q2> Serialize a BST by converting into a AVL. Represent BST/AVL using an Array.
       Initially BST is LL,LR,RR,RL. Input should be inorder.*/


#include <stdio.h>

#define MAX 100

int a[MAX], l[MAX], r[MAX], h[MAX];
int n, cnt = 0;

int max(int x, int y) {
    return x > y ? x : y;
}

int buildAVL(int low, int high) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    int node = cnt++;

    a[node] = mid;
    l[node] = buildAVL(low, mid - 1);
    r[node] = buildAVL(mid + 1, high);

    int hl = l[node] == -1 ? 0 : h[l[node]];
    int hr = r[node] == -1 ? 0 : h[r[node]];

    h[node] = 1 + max(hl, hr);

    return node;
}

void inorder(int node) {
    if (node == -1) return;

    inorder(l[node]);
    printf("%d ", a[node]);
    inorder(r[node]);
}

int main() {
    int root;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter BST inorder elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    root = buildAVL(0, n - 1);

    printf("\nAVL Inorder: ");
    inorder(root);


    return 0;
}