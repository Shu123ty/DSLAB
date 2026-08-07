/* Q) Write a Menu-Driven program to create structure to represent complex numbers and perform::
a)Addition of 2 complex numbers(call by value)
a)Multiplication of 2 complex numbers(call by reference) */

#include <stdio.h>


typedef struct{
    float real;
    float imag;
}Complex;

void add(Complex c1, Complex c2){
    Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    printf("Addition = %f + %fi\n", sum.real, sum.imag);
}


void multiply(Complex *c1, Complex *c2){
    Complex result;

    result.real = (c1->real * c2->real) - (c1->imag * c2->imag);
    result.imag = (c1->real * c2->imag) + (c1->imag * c2->real);

    printf("Multiplication = %f + %fi\n", result.real, result.imag);
}

int main(){
    Complex c1, c2;
    int choice;

    printf("Enter first complex number:\n");
    printf("Real part: ");
    scanf("%f", &c1.real);
    printf("Imaginary part: ");
    scanf("%f", &c1.imag);

    printf("Enter second complex number:\n");
    printf("Real part: ");
    scanf("%f", &c2.real);
    printf("Imaginary part: ");
    scanf("%f", &c2.imag);

    
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            add(c1, c2);
            break;

        case 2:
            multiply(&c1, &c2);
            break;

        default:
            printf("Invalid Choice!\n");
        }

    return 0;
}