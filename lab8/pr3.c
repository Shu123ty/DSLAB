/* Q3> Implement a circular queue using 2 connected stack and perform::
    a) Enqueue b)Dequeue c) isEmpty d) isFull */

#include <stdio.h>

#define MAX 5

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;
int front = 0, rear = -1;
int count = 0;

int isEmpty() {
    return count == 0;
}

int isFull() {
    return count == MAX;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    rear = (rear + 1) % MAX;
    stack1[rear] = value;
    count++;
}

int dequeue() {
    int value;

    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }

    value = stack1[front];
    front = (front + 1) % MAX;
    count--;

    return value;
}

int main() {
    enqueue(40);
    enqueue(80);
    enqueue(20);
    enqueue(10);
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(6);

    printf("Queue: ");

    for (int i = 0; i < count; i++) {
        printf("%d ", stack1[(front + i) % MAX]);
    }

    printf("\n");
    return 0;
}

