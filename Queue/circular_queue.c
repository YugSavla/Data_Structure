#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
int isFull(){
    if((rear==max-1 && front==0) || rear==front-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(front==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(){
    int x;
    printf("Enter the number : \n");
    scanf("%d",&x);
    if(isFull()==1){
        printf("\nOverflow ");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front=rear=0;
        }
        else if(front!=0 && rear==max-1){
            rear=0;
        }
        else{
            rear++;
        }
    }
    queue[rear]=x;
}
void dequeue(){
    if(isEmpty()==1){
        printf("\nUnderflow\n");
        return;
    }
    else{
        if(front==rear){
            front=rear=-1;
        }
        else if(front==max-1){
            front=0;
        }
        else{
            front++;
        }
    }
}
void display() {
    if (isEmpty() == 1) {
        printf("\nEmpty Queue\n");
    } else {
        int i = front;
        printf("Queue: ");
        while (i != rear) {
            printf("%d -> ", queue[i]);
            i = (i + 1) % max;  // Circular increment
        }
        printf("%d\n", queue[rear]);  // Print last element
    }
}
int main() {
    int k = 1;
    int ch;

    while (k == 1) {
        printf("Enter the choice:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                k = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}