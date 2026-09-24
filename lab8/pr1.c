/* Q1> Implement stack using 2 queues and perform::
    a) Push b)pop c) peek d) isEmpty e)isFull*/
    
#include <stdio.h>

#define MAX 100

int queue1[MAX], queue2[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;


int isEmptyQueue1() {
    return front1 > rear1;
}


int isEmptyQueue2() {
    return front2 > rear2;
}


int isEmpty() {
    return isEmptyQueue1();
}


int isFull() {
    return (rear1 - front1 + 1) == MAX;
}


void push(int value) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }

    while (!isEmptyQueue1()) {
        queue2[++rear2] = queue1[front1++];
    }

    queue1[++rear1] = value;

    while (!isEmptyQueue2()) {
        queue1[++rear1] = queue2[front2++];
    }

    front2 = 0;
    rear2 = -1;

    if (front1 > rear1) {
        front1 = 0;
        rear1 = -1;
    }
}


int pop() {

    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }

    return queue1[front1++];
}

int peek() {

    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }

    return queue1[front1];
}

int main(){
    push(40);
    push(80);
    push(20);
    push(10);
    pop();
    pop();
    push(5);
    push(6);

    printf("Stack: ");
    for (int i = rear1; i >= front1; i--) {
        printf("%d ", queue1[i]);
    }

    printf("\n");
    return 0;
}