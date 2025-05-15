#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    return (top != -1) ? stack[top] : '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* exp) {
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];

        if (isalnum(c)) {
            printf("%c", c); // Operand: print directly
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(')
                printf("%c", pop());
            pop(); // remove '('
        } else { // Operator
            while (precedence(peek()) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }

    while (top != -1)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[100];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    printf("Postfix: ");
    infixToPostfix(exp);
    return 0;
}
