#include <stdio.h>

void convert(int a[10][10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            a[i][j] = a[j][i];
            a[j][i] = 0;
        }
    }
}

void display(int a[10][10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main() {
    int a[10][10], n;

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter upper triangular matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    convert(a, n);

    printf("Lower triangular matrix:\n");
    display(a, n);

    return 0;
}