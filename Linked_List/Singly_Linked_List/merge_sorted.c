#include <stdio.h>
#include <stdlib.h>

// Typedef for Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end
void appendNode(Node** head_ref, int value) {
    Node* newNode = createNode(value);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
Node* merge_link(Node* l1,Node* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if (l1->data < l2->data) {
        l1->next = merge_link(l1->next, l2);
        return l1;
    } else {
        l2->next = merge_link(l1, l2->next);
        return l2;

    }
 }


// Function to print the list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Manually chosen random values in ascending order
    int values1[] = {3, 15, 27, 42, 59};   // Random ascending
    int values2[] = {6, 18, 33, 45, 72};   // Random ascending

    for (int i = 0; i < 5; i++) {
        appendNode(&list1, values1[i]);
        appendNode(&list2, values2[i]);
    }

    // Show both lists
    printf("List 1 (sorted): ");
    printList(list1);

    printf("List 2 (sorted): ");
    printList(list2);
    Node* list3=NULL;
    list3= merge_link(list1,list2);
    printList(list3);

    // 👉 Now you can write a function to merge these two sorted lists into one

    return 0;
}
