#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Cannot create new Node");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createList(int n)
{
    struct Node *temp = NULL;
    struct Node *head = NULL;
    int data;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth value for the linked list:", i);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    printf("The linked list is :\n");

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *insertAtBeginning(struct Node **head, int newdata)
{
    struct Node *newNode = createNode(newdata);
    newNode->next = *head;
    *head = newNode;
    return *head;
}

struct Node *insertAtEnd(struct Node **head, int newdata)
{
    struct Node *newNode = createNode(newdata);
    if (*head == NULL)
    {
        *head = newNode;
        return *head;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return *head;
}

struct Node *insertAfterValue(struct Node **head, int value, int newdata)
{
    struct Node *temp = *head;

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return *head;
    }

    struct Node *newNode = createNode(newdata);
    newNode->next = temp->next;
    temp->next = newNode;
    return *head;
}

struct Node *insertBeforeValue(struct Node **head, int value, int newdata)
{
    struct Node *newNode = createNode(newdata);

    if (*head == NULL)
        return newNode;

    if ((*head)->data == value)
    {
        newNode->next = *head;
        *head = newNode;
        return *head;
    }

    struct Node *prev = NULL;
    struct Node *curr = *head;

    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("Value %d not found in the list.\n", value);
        return *head;
    }

    prev->next = newNode;
    newNode->next = curr;
    return *head;
}

struct Node *insertAtIndex(struct Node **head, int index, int newdata)
{
    struct Node *newNode = createNode(newdata);

    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return *head;
    }

    struct Node *temp = *head;
    for (int i = 0; i < index - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Index out of bounds.\n");
        return *head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return *head;
}

int main()
{
    struct Node *head = NULL;
    int n, choice, data, value, index;

    printf("Enter the size of the linked list: ");
    scanf("%d", &n);

    head = createList(n);
    printList(head);
    while (1)
    {
        printf("1)Insertion at beginning\n2)Insertion at end\n3)Insertion after a given value\n4)Insertion before a give value\n5)Insertion at given index\n6)Exit\nEnter the choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            printList(head);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            printList(head);
            break;
        case 3:
            printf("Enter value after which to insert: ");
            scanf("%d", &value);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAfterValue(&head, value, data);
            printList(head);
            break;
        case 4:
            printf("Enter value before which to insert: ");
            scanf("%d", &value);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertBeforeValue(&head, value, data);
            printList(head);
            break;
        case 5:
            printf("Enter index at which to insert: ");
            scanf("%d", &index);
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtIndex(&head, index, data);
            printList(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}