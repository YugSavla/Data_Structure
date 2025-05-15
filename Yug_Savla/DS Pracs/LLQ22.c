// 22. Write a Program to implement following operations on Singly Linked List:  (i) Sort the list  
// (ii) Delete the last node 
// (iii) Insert a node before a given value

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
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
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Display the list
void printList(struct Node* head) {
    printf("List: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// (i) Sort the list (Bubble Sort)
void sortList(struct Node* head) {
    if (!head) return;
    struct Node* i;
    struct Node* j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}

// (ii) Delete the last node
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted.\n");
}

// (iii) Insert before a given value
void insertBeforeValue(struct Node** head, int target, int value) {
    struct Node* newNode = createNode(value);

    // If list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If target is at head
    if ((*head)->data == target) {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d before %d.\n", value, target);
        return;
    }

    // Traverse to find the node before target
    struct Node* temp = *head;
    while (temp->next && temp->next->data != target)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value %d not found in the list.\n", target);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d before %d.\n", value, target);
}

int main() {
    struct Node* head = NULL;

    // Example usage
    insertEnd(&head, 40);
    insertEnd(&head, 10);
    insertEnd(&head, 30);
    insertEnd(&head, 20);

    printList(head);

    sortList(head);
    printList(head);

    deleteLast(&head);
    printList(head);

    insertBeforeValue(&head, 30, 25);
    printList(head);

    insertBeforeValue(&head, 10, 5);
    printList(head);

    insertBeforeValue(&head, 100, 50); // Not found case

    return 0;
}
