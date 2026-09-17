/* Q2> create a linear queue using SLL and perform the following::
    a) Enqueue b) Dequeue c) Traverse d) isEmpty e) isFull 
    using two separate linked list where a> head->rear, tail->front
                                         b> head->front, tail->rear*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;
int type;

void enqueue() {
    struct node *p = malloc(sizeof(struct node));
    if (!p) {
        printf("Full\n");
        return;
    }

    printf("Enter the data:: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (head == NULL)
        head = tail = p;
    else if (type == 1) {
        p->next = head;
        head = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

void dequeue() {
    struct node *p, *q;

    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    if (type == 2) {
        p = head;
        head = head->next;
        printf("Deleted: %d\n", p->data);
        free(p);
        if (head == NULL) tail = NULL;
    } else {
        if (head == tail) {
            printf("Deleted: %d\n", tail->data);
            free(tail);
            head = tail = NULL;
            return;
        }

        p = head;
        while (p->next != tail)
            p = p->next;

        q = tail;
        printf("Deleted: %d\n", q->data);
        tail = p;
        tail->next = NULL;
        free(q);
    }
}

void traverse() {
    struct node *p = type == 1 ? tail : head;

    if (p == NULL) {
        printf("Empty\n");
        return;
    }

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void isEmpty() {
    printf(head == NULL ? "Empty\n" : "Not Empty\n");
}

void isFull() {
    struct node *p = malloc(sizeof(struct node));

    if (p == NULL)
        printf("Full\n");
    else {
        printf("Not Full\n");
        free(p);
    }
}

int main() {
    int choice;

    
    printf("1. Head=Rear, Tail=Front\n");
    printf("2. Head=Front, Tail=Rear\n");
    scanf("%d", &type);

    do{
        printf("\n1.Enqueue 2.Dequeue 3.Traverse 4.IsEmpty 5.IsFull 6.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: traverse(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            default: break;
        }
        
    }while(choice != 6);
    return 0;
}