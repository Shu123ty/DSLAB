/* infix to postfix using array stack*/

#include <stdio.h>

char stack[100];
int top = -1;

void push(char x){
    top++;
    stack[top] = x;
}

char pop(){
    char x = stack[top];
    top--;
    return x;
}

int precedence(char x){
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int isOperand(char x){
    if ((x >= 'A' && x <= 'Z') ||
        (x >= 'a' && x <= 'z') ||
        (x >= '0' && x <= '9'))
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[]){
    char postfix[100];
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0'){
        x = infix[i];

        if (isOperand(x)){
            postfix[j] = x;
            j++;
        }
        else if (x == '('){
            push(x);
        }
        else if (x == ')'){
            while (top != -1 && stack[top] != '('){
                postfix[j] = pop();
                j++;
            }

            if (top != -1)
                pop();
        }
        else{
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(x)){
                postfix[j] = pop();
                j++;
            }

            push(x);
        }

        i++;
    }

    while (top != -1){
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int main(){
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}