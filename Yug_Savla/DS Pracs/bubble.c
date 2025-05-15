#include <stdio.h>
#include <time.h> // For clock()

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Push the biggest element to the end in each pass
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if elements are in wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // 🕒 Start time
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    // 🚀 Run Bubble Sort
    bubbleSort(arr, n);

    // 🕒 End time
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
