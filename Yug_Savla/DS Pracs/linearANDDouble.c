#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize table with -1
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);  // Must be non-zero and co-prime with SIZE
}

void linearProbing(int key) {
    int index = hash1(key);
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1)
        i++;
    hashTable[(index + i) % SIZE] = key;
}

void doubleHashing(int key) {
    int index = hash1(key);
    int step = hash2(key);
    int i = 0;
    while (hashTable[(index + i * step) % SIZE] != -1)
        i++;
    hashTable[(index + i * step) % SIZE] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d: %d\n", i, hashTable[i]);
}

int main() {
    init();
    printf("Linear Probing:\n");
    linearProbing(19);
    linearProbing(29);
    linearProbing(39);
    linearProbing(49);
    display();

    init();
    printf("\nDouble Hashing:\n");
    doubleHashing(19);
    doubleHashing(29);
    doubleHashing(39);
    doubleHashing(49);
    display();

    return 0;
}
