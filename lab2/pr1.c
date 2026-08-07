/* Q) Create a array of "n" elements using dynamic memory allocation. Calculate
the sum of all the prime numbers in the array using function call. De-allocate the 
memory. */



#include <stdio.h>
#include <stdlib.h>

int isprime(int n){
    int cnt = 0;
    for (int i = 2; i<=n; i++){
        if (n%i == 0){
            cnt++;
        }
    }

    if (cnt == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    printf("Enter number of elements::\n");
    scanf("%d",&n);

    int *arr = (int*)malloc(sizeof(int)*n);
    if (arr == NULL){
        printf("Memory not allocated");
        exit(1);
    }

    printf("enter array elements::\n");
    for(int i = 0; i<n; i++){
        scanf("%d",arr+i);
    }

    int sum = 0;
    for (int i = 0; i<n; i++){
        if (isprime(*(arr + i)) == 1){
            sum = sum + *(arr+i);
        }
    }

    printf("The sum of all the prime numbers of array is = %d", sum);
    free(arr);
    arr = NULL;
    return 0;
}