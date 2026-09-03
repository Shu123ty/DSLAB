/* do q1 using linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(){
    int x;
    struct node *newnode;

    printf("Enter element: ");
    scanf("%d", &x);

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL){
        printf("Stack is Full\n");
        return;
    }

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully\n");
}

void pop(){
    struct node *temp;

    if (top == NULL){
        printf("Stack is Empty\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}

void isEmpty(){
    if (top == NULL){
        printf("Stack is Empty\n");}
    else{
        printf("Stack is not Empty\n");}
}

void isFull(){
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL){
        printf("Stack is Full\n");}
    else{
        printf("Stack is not Full\n");
        free(temp);
    }
}

void display(){
    struct node *temp;

    if (top == NULL){
        printf("Stack is Empty\n");
        return;
    }

    temp = top;

    printf("Stack elements:\n");

    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    int choice;

    do
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:isEmpty();break;
            case 4:isFull();break;
            case 5:display();break;
            case 6:
                printf("Program terminated\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}