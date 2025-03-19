#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display_linked_list(struct node *head) {
    struct node *temp = head->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insert_end(struct node *head) {
    struct node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = rand() % 20;
    new_node->next = head;
    temp->next = new_node;
}

void insert_after(struct node *head, int n) {
    struct node *temp = head;
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    while (temp -> next != head) {
        if (temp->data == n) {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = data;
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }
}

void delete_first(struct node *head) {
    struct node *temp = head->next;
    head->next = temp->next;
    free(temp);
}

void delete_end(struct node *head) {
    struct node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
}

void delete_node(struct node *head, int n) {
    struct node *temp = head;
    while (temp->next != head) {
        if (temp->next->data == n) {
            struct node *temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            break;
        }
        temp = temp->next;
    }
}

void search(struct node *head) {
    int flag = 0;
    int pos = 1;
    int el;
    printf("Enter element to search: ");
    scanf("%d", &el);
    struct node *temp = head -> next;
    while(temp -> next != head) {
        if (temp->data == el) {
            flag = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (flag == 0) {
        printf("Element not found\n");
    } else {
        printf("Element found at position %d\n", pos);
    }
}

void sort_linked_list(struct node *head) {
    struct node *temp = head->next;
    while (temp != head) {
        struct node *temp2 = temp->next;
        while (temp2 != head) {
            if (temp->data > temp2->data) {
                int t = temp->data;
                temp->data = temp2->data;
                temp2->data = t;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = head;
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        insert_end(head);
    }
    printf("Before sorting: ");
    display_linked_list(head);
    sort_linked_list(head);
    printf("\nAfter sorting: ");
    display_linked_list(head);

    printf("Enter 1 to display circular linked list, 2 to insert after given data in circular linked list, 3 to delete first element, 4 to delete random element, 5 to search for an element, 6 to stop: ");
    scanf("%d", &n);

    while(n != 6) {
        switch (n) {
            case 1:
                display_linked_list(head);
                break;
            case 2:
                printf("Enter element to insert after: ");
                scanf("%d", &n);
                insert_after(head, n);           
                break;
            case 3:
                delete_first(head);
                break;
            case 4:
                printf("Enter data to be deleted: ");
                scanf("%d", &val);
                delete_node(head, val); 
                break;
            case 5:
                search(head); 
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\nEnter 1 to display linked list, 2 to insert after given data in linked list, 3 to delete first element, 4 to delete random element, 5 to search for an element, 6 to stop: ");
        scanf("%d", &n);
        printf("\n");
    }
    printf("Exited with success");
}