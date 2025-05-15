// Write a Program to implement following operations on Singly Linked List: 
// i) Reverse the given link list
// ii) Delete the first node 
// iii) Search a given value

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display list
void printList(struct Node* head) {
    printf("Linked List: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// i) Reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    *head = prev;
    printf("List reversed successfully.\n");
}

// ii) Delete the first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}

// iii) Search a value
void search(struct Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Value %d not found in the list.\n", key);
}

int main() {
    struct Node* head = NULL;

    // Example list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printList(head);

    reverseList(&head);
    printList(head);

    deleteFirst(&head);
    printList(head);

    search(head, 30);
    search(head, 99);

    return 0;
}
