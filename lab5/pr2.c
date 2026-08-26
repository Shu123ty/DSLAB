#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, value;
    struct node *next;
};

struct node *createList(int r, int c) {
    struct node *head = NULL, *temp = NULL, *newNode;
    int i, j, x;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &x);

            if (x != 0) {
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->row = i;
                newNode->col = j;
                newNode->value = x;
                newNode->next = NULL;

                if (head == NULL)
                    head = newNode;
                else
                    temp->next = newNode;

                temp = newNode;
            }
        }
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;

    printf("\nRow\tCol\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n",
               temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int r, c;
    struct node *head;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    head = createList(r, c);

    display(head);

    return 0;
}