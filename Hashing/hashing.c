#include <stdio.h>

#define SIZE 7

int arr[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        arr[i] = -1;
}

void insert(int value) {
    int key = value % SIZE;
    if (arr[key] == -1) {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    } else {
        printf("Collision: arr[%d] already contains %d\n", key, arr[key]);
        printf("Unable to insert %d\n", value);
    }
}

void del(int value) {
    int key = value % SIZE;
    if (arr[key] == value) {
        arr[key] = -1;
        printf("%d deleted from arr[%d]\n", value, key);
    } else {
        printf("%d not found in the hash table\n", value);
    }
}

void search(int value) {
    int key = value % SIZE;
    if (arr[key] == value)
        printf("%d found at arr[%d]\n", value, key);
    else
        printf("%d not found in the hash table\n", value);
}

void print() {
    for (int i = 0; i < SIZE; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

int main() {
    int choice, value;
    init();

    do {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                del(value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                printf("Hash Table contents:\n");
                print();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
