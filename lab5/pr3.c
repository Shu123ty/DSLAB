#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList() {
    int n, i, x;
    struct node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);

        newNode = malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void countNodes() {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes = %d\n", count);
}

void reverseList() {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void sortList() {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
        for (j = i->next; j != NULL; j = j->next)
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

int main() {
    int choice;
    createList();

    printf("1. Count Nodes\n");
    printf("2. Reverse List\n");
    printf("3. Sort List\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: countNodes(); break;
        case 2: reverseList(); break;
        case 3: sortList(); break;
        case 4: display(); break;
        case 5: break;
        default: printf("Invalid choice\n");
    }
    return 0;
}