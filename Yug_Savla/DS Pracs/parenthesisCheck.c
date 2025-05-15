#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char* expr) {
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
            push(c);
        else if (c == ')' || c == '}' || c == ']') {
            char open = pop();
            if (!isMatchingPair(open, c))
                return 0;
        }
    }
    return (top == -1);
}

int main() {
    char expr[100];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Balanced parentheses \n");
    else
        printf("Unbalanced parentheses \n");

    return 0;
}
