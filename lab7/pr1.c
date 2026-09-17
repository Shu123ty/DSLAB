/* Q1> create a linear queue using Array and perform the following::
    a) Enqueue b) Dequeue c) Traverse d) isEmpty e) isFull*/

#include <stdio.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;


void enqueue(){
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;

    printf("%d inserted into queue\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);
    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void Traverse() {
    int i;

    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    for (i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void isEmpty() {
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");
}

void isFull() {
    if (rear == MAX - 1)
        printf("Queue is Full\n");
    else
        printf("Queue is Not Full\n");
}

int main(){
    int choice;
    
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Exit\n");
        scanf("%d",&choice);

    
        switch (choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Traverse();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        default:
            break;
        }
    }while(choice != 6);
   
    return 0;
}
