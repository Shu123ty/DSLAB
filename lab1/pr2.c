
/*WAP to print all the prime numbers between 1 and n using a) Call by Value b) call by reference*/

#include <stdio.h>

int prime1(int n){
    int p = 0;
    for (int i = 2; i <= n;i++){
        if (n%i == 0){
            p++;
        }
    }
    if (p == 1){
        return 1;
    }
    else {
        return 0;
    }
}

int prime2(int *n){
    int p = 0;
    for (int i = 2; i <= *n;i++){
        if (*n%i == 0){
            p++;
        }
    }
    if (p == 1){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    int x;
    scanf("%d",&x);
    
    for (int i = 1; i <= x;i++){
        if (prime1(i) == 1){
            printf("%d, ",i);
        }
    }
    printf("\n");
    int y;
    scanf("%d",&y);

    for (int i = 1; i <= y;i++){
        if (prime2(&i) == 1){
            printf("%d, ",i);
        }
    }

    return 0;
}
