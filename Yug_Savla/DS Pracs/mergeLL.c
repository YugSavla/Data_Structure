#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct Node* result = NULL;

    if (l1->data < l2->data) {
        result = l1;
        result->next = mergeSorted(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSorted(l1, l2->next);
    }
    return result;
}

int main() {
    // List 1: 1 -> 3 -> 5
    struct Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    // List 2: 2 -> 4 -> 6
    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    struct Node* merged = mergeSorted(l1, l2);
    printf("Merged List: ");
    printList(merged);

    return 0;
}
