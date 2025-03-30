#include <stdio.h>

void push(int stack[], int *top) {
    int x;
    (*top)++; // Increment top
    if (*top == 10) {
        printf("\nOverflow\n");
    } else {
        printf("\nEnter the number: ");
        scanf("%d", &x);
        stack[*top] = x;
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("\nUnderflow\n");
    } else {
        stack[*top] = 0;
        (*top)--; // Decrement top
    }
}

void peek(int stack[], int *top) {
    if (*top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nTop most element is %d\n", stack[*top]);
    }
}

void display(int stack[], int *top) {
    if (*top == -1) {
        printf("No elements in Stack\n");
    } else {
        printf("Stack elements: ");
        for (int i = *top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[10];
    int top = -1;
    int ch = 0; // Initialize ch
    while (ch != 5) {
        printf("\nEnter 1 to push, 2 to pop, 3 to peek, 4 to display, 5 to exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, &top);
                break;
            case 4:
                display(stack, &top);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
