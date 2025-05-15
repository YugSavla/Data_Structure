#include <stdio.h>
#include <time.h> // For clock()

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // 🕒 Start the clock
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // 🔧 Sort the array
    insertionSort(arr, n);

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
