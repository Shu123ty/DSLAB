/*infix to prefix using array for stack*/

#include <stdio.h>

char s[100];
int top = -1;

void push(char x) {
    s[++top] = x;
}

char pop() {
    return s[top--];
}

int pre(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int operand(char x) {
    return (x >= 'A' && x <= 'Z') ||
           (x >= 'a' && x <= 'z') ||
           (x >= '0' && x <= '9');
}

void reverse(char a[]) {
    int i = 0, j = 0;
    char t;

    while (a[j]) j++;
    j--;

    while (i < j) {
        t = a[i];
        a[i++] = a[j];
        a[j--] = t;
    }
}

void prefix(char a[]) {
    char p[100];
    int i = 0, j = 0;

    reverse(a);

    while (a[i]) {
        if (a[i] == '(') a[i] = ')';
        else if (a[i] == ')') a[i] = '(';
        i++;
    }

    top = -1;
    i = 0;

    while (a[i]) {
        if (operand(a[i]))
            p[j++] = a[i];
        else if (a[i] == '(')
            push(a[i]);
        else if (a[i] == ')') {
            while (s[top] != '(')
                p[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && s[top] != '(' &&
                   pre(s[top]) > pre(a[i]))
                p[j++] = pop();
            push(a[i]);
        }
        i++;
    }

    while (top != -1)
        p[j++] = pop();

    p[j] = '\0';
    reverse(p);

    printf("Prefix: %s", p);
}

int main() {
    char a[100];

    printf("Enter infix: ");
    scanf("%s", a);

    prefix(a);

    return 0;
}