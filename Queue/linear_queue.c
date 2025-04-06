#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
int queue[max];
int front=-1;
int rear=-1;
int isFull(){
    if(rear==max-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty() {
    if(front == -1 || front > rear) {
        return 1;
    }
    return 0;
}
void display(){
    if(isEmpty()==1){
        printf("\nEmpty Queue");
    }
    else

    for (int i = front; i <= rear; i++)
    {
        
        printf("%d->",queue[i]);
    }
    printf("\n");
    
}
void delete() {
    if(isEmpty()) {
        printf("\nNo more Deletion Possible - Queue is Empty\n");
        return;
    }
    
    printf("\nDeleted element: %d\n", queue[front]);
    
    if(front == rear) {
        // Last element being deleted
        front = rear = -1;
    } else {
        front++;
    }
}
void insert(){
    int x;
    printf("Enter the number : \n");
    scanf("%d",&x);
    if(front==-1  && rear==-1){
        front=rear=0;
    }
    else if(isFull()) {
        printf("\nOverflow - Queue is Full\n");
        return;
    }
    else{
        rear++;
    } 
    queue[rear]=x;   
}
int main() {
    int k = 1;
    int ch;

    while (k == 1) {
        printf("Enter the choice:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
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