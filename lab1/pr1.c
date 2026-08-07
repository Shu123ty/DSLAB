
/* Q> WAP that reads 2 numbers to compare them using a) Call by value b) Call by Reference. */

#include <stdio.h>


void compare1(int a, int b){
	if (a > b){
		printf("%d is bigger than %d\n", a,b);
	}
	else if (a == b){
		printf("%d is equal to %d\n",b,a);
	}
	else{
		printf("%d is bigger than %d\n",b,a);
	}
}


void compare2(int *a, int *b){
	if (*a > *b){
		printf("%d is bigger than %d\n", *a,*b);
	}
	else if (*a == *b){
		printf("%d is equal to %d\n",*b,*a);
	}
	else{
		printf("%d is bigger than %d\n",*b,*a);
	}

}

int main(){
int x,y,p,q;
	
printf("enter variable values to compare first two numbers using call by Value \n");
scanf("%d",&x);
scanf("%d",&y);
compare1(x,y);
  
printf("enter variable values to compare next two numbers using call by Reference \n");
scanf("%d",&p);
scanf("%d",&q);
compare2(&p,&q);
	
  return 0;
}
