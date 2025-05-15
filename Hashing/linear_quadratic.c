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

void linearProbing(int table[], int key) {
    int index = hashFunction(key);
    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index] = key;
}

void quadraticProbing(int table[], int key) {
    int index = hashFunction(key);
    int i = 1;
    while (table[index] != -1) {
        index = (index + i * i) % TABLE_SIZE;
        i++;
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
        printf("\n1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                linearProbing(table, key);
                break;
            case 2:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                quadraticProbing(table, key);
                break;
            case 3:
                displayTable(table, TABLE_SIZE);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}