#include <stdio.h>

// 🔍 Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// 🔍 Binary Search (array must be sorted)
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right)/2;

        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 20;

    // Linear Search
    int linIndex = linearSearch(arr, n, key);
    printf("Linear Search: ");
    if (linIndex != -1)
        printf("Found %d at index %d\n", key, linIndex);
    else
        printf("Not found\n");

    // Binary Search (needs sorted array)
    int binIndex = binarySearch(arr, 0, n - 1, key);
    printf("Binary Search: ");
    if (binIndex != -1)
        printf("Found %d at index %d\n", key, binIndex);
    else
        printf("Not found\n");

    return 0;
}
