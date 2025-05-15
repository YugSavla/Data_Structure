#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char symbol) {
    if (top < MAX - 1) {
        stack[++top] = symbol;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) return 0; // Odd length cannot be balanced

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c); // Push opening brackets onto the stack
        } else {
            if (top == -1) return 0; // No opening bracket to match
            char top_char = pop();
            if ((c == ')' && top_char != '(') ||
                (c == '}' && top_char != '{') ||
                (c == ']' && top_char != '[')) {
                return 0; // Mismatched brackets
            }
        }
    }
    return top == -1; // Stack must be empty at the end
}

int main() {
    char input[MAX];
    printf("Enter the parentheses: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    if (isValid(input)) {
        printf("Valid\n");
    } else {
        printf("Not valid\n");
    }
    return 0;
}