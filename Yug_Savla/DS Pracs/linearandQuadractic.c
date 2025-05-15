#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize table with -1
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void linearProbing(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1)
        i++;
    hashTable[(index + i) % SIZE] = key;
}

void quadraticProbing(int key) {
    int index = key % SIZE;
    int i = 0;
    while (hashTable[(index + i * i) % SIZE] != -1)
        i++;
    hashTable[(index + i * i) % SIZE] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d: %d\n", i, hashTable[i]);
}

int main() {
    init();
    printf("Using Linear Probing:\n");
    linearProbing(23);
    linearProbing(43);
    linearProbing(13);
    linearProbing(27);
    display();

    init();  // reset
    printf("\nUsing Quadratic Probing:\n");
    quadraticProbing(23);
    quadraticProbing(43);
    quadraticProbing(13);
    quadraticProbing(27);
    display();

    return 0;
}
