/* Q) Create a 1-D array of 'n' elements and perform operations using switch::
a> Insert at any position.
b> Delete at any position.
c> Binary Search an element.
d> Linear Traversal of array.*/

#include <stdio.h>
#include <stdlib.h>

void Insert_element(int **arr, int *s){
    int n;
    printf("Enter the index at which to input::");
    scanf("%d",&n);

    if (n < 0 || n > *s) {
        printf("Invalid index\n");
        return;
    }

    (*s)++;
    int *temp = realloc(*arr, (*s) * sizeof(int));
    if (temp == NULL){
        return;
    }
    *arr = temp;

    for(int i = *s - 1; i > n; i--){
        (*arr)[i] = (*arr)[i-1];
    }

    printf("Enter new element::");
    scanf("%d", &(*arr)[n]);
}

void Delete_element(int **arr, int *s){
    int n;
    printf("Enter the index at which to delete::");
    scanf("%d",&n);

    if (n < 0 || n >= *s) {
        printf("Invalid index\n");
        return;
    }

    for(int i = n; i < *s - 1; i++){
        (*arr)[i] = (*arr)[i + 1];
    }

    (*s)--;
    int *temp = realloc(*arr, (*s) * sizeof(int));
    if (temp != NULL || *s == 0){
        *arr = temp;
    }
}

int BS_array(int *arr, int s){
    int n;
    printf("Enter the value to be searched::");
    scanf("%d",&n);

    int left = 0;
    int right = s - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == n){
            return mid;
        }
        else if(arr[mid] < n){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return -1;   
}

void LT_array(int *arr, int s){
    printf("Elemnts of a array::\n");
    for (int i = 0; i < s; i++){
        printf("%d\n", arr[i]);
    }
}

int main(){
    int n, choice;
    printf("enter size of array::");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        scanf("%d", arr+i);
    }

    printf("Enter your choice\n");
    printf("1. insert in array\n");
    printf("2. delete from array\n");
    printf("3. binary search array\n");
    printf("4. linear traverse array\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            Insert_element(&arr, &n);
            break;
        case 2:
            Delete_element(&arr, &n);
            break;
        case 3: {
            int index = BS_array(arr, n);
            if (index != -1){
                printf("Element exists");
            }
            else {
                printf("Element does not exist");
            }
            break;
        }
        case 4:
            LT_array(arr, n);
            break;
        default:
            break;
    }
    
    free(arr);
    arr = NULL;

    return 0;    
}