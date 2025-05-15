#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

void initializeTable(int table[], int size) {
    for(int i = 0; i < size; i++) {
        table[i] = -1;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int secondHashFunction(int key) {
    return 7 - (key % 7);
}

void doubleHashing(int table[], int key) {
    int index = hashFunction(key);
    int step = secondHashFunction(key);
    while (table[index] != -1) {
        index = (index + step) % TABLE_SIZE;
    }
    table[index] = key;
}

void displayTable(int table[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        if(table[i] == -1) {
            printf("Empty\n");
        } else {
            printf("%d\n", table[i]);
        }
    }
}

int main() {
    int table[TABLE_SIZE];
    int choice, key;
    initializeTable(table, TABLE_SIZE);

    while (1) {
        printf("\n1. Insert using Double Hashing\n");
        printf("2. Display Hash Table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d",&key);
                doubleHashing(table, key);
                break;
            case 2:
                displayTable(table, TABLE_SIZE);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}