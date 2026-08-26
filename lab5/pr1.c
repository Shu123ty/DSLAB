#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertAtPosition() {
    int value, position, i;
    struct node *newNode, *temp;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }

        head = newNode;

        printf("Element inserted successfully.\n");
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("Element inserted successfully.\n");
}


void traverse() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;

    printf("Doubly Linked List:\n");
    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL) {
            printf(" <-> ");
        }

        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    printf("1. Insert Element at Specific Position\n");
    printf("2. Traverse List\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertAtPosition();
            break;
        case 2:
            traverse();
            break;
        default:
            printf("Invalid choice.\n");
        }    
    return 0;
}