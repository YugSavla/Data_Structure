#include <stdio.h>
#include <stdlib.h>

// 7.	Write a Program to implement following operations on Singly Linked List: 
// i) Insertion after a given node 
// ii) Deletion after a given node 
// iii) Search a given value 


struct Node {
    int data;
    struct Node* next;
};

// Insert after given node
void insertAfter(struct Node* prev, int newData) {
    if (prev == NULL) return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prev->next;
    prev->next = newNode;
}

// Delete after given node
void deleteAfter(struct Node* prev) {
    if (prev == NULL || prev->next == NULL) return;

    struct Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// Search a value
struct Node* search(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return head;
        head = head->next;
    }
    return NULL;
}

// Print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    insertAfter(head, 20);
    insertAfter(head->next, 30);

    printf("List: ");
    printList(head);

    printf("Deleting after node with data 10...\n");
    deleteAfter(head);

    printf("List after deletion: ");
    printList(head);

    int key = 30;
    struct Node* found = search(head, key);
    if (found)
        printf("Found %d in list.\n", key);
    else
        printf("%d not found in list.\n", key);

    return 0;
}
