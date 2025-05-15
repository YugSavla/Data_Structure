#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Declare the queue and two pointers
int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to insert an element into the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full!\n");
    } else {
        if (front == -1)  // If queue is empty
            front = 0;
        rear = (rear + 1) % MAX;  // Circular increment
        queue[rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

// Function to delete an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return -1;
    } else {
        int dequeuedValue = queue[front];
        if (front == rear) {  // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;  // Circular increment
        }
        return dequeuedValue;
    }
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);  // This should print "Queue is Full!"

    display();

    printf("%d dequeued from the queue\n", dequeue());
    printf("%d dequeued from the queue\n", dequeue());

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
