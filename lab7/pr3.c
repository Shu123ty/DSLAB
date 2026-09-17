/* count number of elements in queue for both cases using array::
    a)front>rear(circular and linear)
    b)rear>front(circular and linear)*/

#include <stdio.h>
#define MAX 5

int queue[MAX], front, rear;

void linear() {
    if (front == -1){
        printf("Linear Count = 0\n");
    }
    else{
        printf("Linear Count = %d\n", rear - front + 1);
    }
}

void circular() {
    if (front == -1){
        printf("Circular Count = 0\n");
    }
    else if (front <= rear){
        printf("Circular Count = %d\n", rear - front + 1);
    }
    else{
        printf("Circular Count = %d\n", MAX - front + rear + 1);
    }
}

int main() {
    printf("Enter front and rear: ");
    scanf("%d %d", &front, &rear);

    linear();
    circular();

    return 0;
}