#include <stdio.h>
#include <time.h> // For clock()

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; // You can use a bigger array to see time better
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // 🕒 Start the clock
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // 🧮 Run selection sort
    selectionSort(arr, n);

    // 🕒 End the clock
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // ⏱️ Print time taken
    printf("Time taken: %.6f seconds\n", cpu_time_used);

    return 0;
}
