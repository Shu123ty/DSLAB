/*create a stack using an array and perform the following::
a)push b)pop c)isEmpty d)Isfull e) display elements*/

#include <stdio.h>

int stack[5], top = -1;

void push() {
    int x;

    if (top == 4)
        printf("Stack is Full\n");
    else {
        printf("Enter element: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void isEmpty() {
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is not Empty\n");
}

void isFull() {
    if (top == 4)
        printf("Stack is Full\n");
    else
        printf("Stack is not Full\n");
}

void display() {
    int i;

    if (top == -1)
        printf("Stack is Empty\n");
    else {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(); break;
            case 5: display(); break;
            case 6: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}