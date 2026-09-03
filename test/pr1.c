#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node* insertMiddle(struct node *head, int value) {
    struct node *newnode, *temp;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    temp = head;

    // Move to 3rd node
    for(int i = 1; i < 3; i++)
        temp = temp->next;

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;

    return head;
}

void display(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct node *head = NULL, *temp, *newnode;
    int value;

    // Create 5 nodes
    for(int i = 1; i <= 5; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;
        newnode->prev = NULL;

        if(head == NULL)
            head = newnode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    printf("Enter element to insert in middle: ");
    scanf("%d", &value);

    head = insertMiddle(head, value);

    printf("Doubly linked list after insertion: ");
    display(head);

    return 0;
}