/* Q2> Implement queue using 2 stack and perform::
    a) Enqueue b)Dequeue c) isEmpty d) isFull*/

#include <stdio.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

int isEmpty() {
    return top1 == -1 && top2 == -1;
}

int isFull() {
    return top1 + top2 + 2 == MAX;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    stack1[++top1] = value;
}

int dequeue() {
    int value;

    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }

    value = stack2[top2--];

    return value;
}

int main(){
    
    enqueue(40);
    enqueue(80);
    enqueue(20);
    enqueue(10);
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(6);
    
    printf("Queue: ");

    for (int i = top2; i >= 0; i--){
        printf("%d ", stack2[i]);
    }

    for (int i = 0; i <= top1; i++){
        printf("%d ", stack1[i]);
    }
    
    printf("\n");
    return 0;
}