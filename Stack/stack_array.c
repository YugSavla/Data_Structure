#include <stdio.h>

void push(int stack[], int *top) {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    if (*top == 9) {  
        printf("Stack overflow\n");
        return;
    } else {
        (*top)++;               
        stack[*top] = data;   
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {  
        printf("Stack underflow\n");
        return;
    } else {
        printf("Popped element: %d\n", stack[*top]);
        (*top)--; 
    }
}

void peek(int stack[], int *top) {
    if (*top == -1) { 
        printf("No element in Stack\n");
        return;
    } else {
        printf("Top element: %d\n", stack[*top]);
    }
}

void display(int stack[], int *top) {
    if (*top == -1) { 
        printf("No element in Stack\n");
        return;
    } else {
        for (int i = *top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() { 
    int stack[10];
    int top = -1;
    int choice;

    printf("ARRAY IMPLEMENTATION OF STACK\n");
    printf("Enter 1 to push, 2 to pop, 3 to peek, 4 to display, 5 to exit: ");
    scanf("%d", &choice);

    while (choice != 5) {
        switch (choice) {
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
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("Enter 1 to push, 2 to pop, 3 to peek, 4 to display, 5 to exit: ");
        scanf("%d", &choice);
    }

    return 0;
}