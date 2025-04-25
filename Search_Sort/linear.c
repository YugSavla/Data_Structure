#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

int main() {
  int arr[] = {2, 5, 1, 9, 4, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 4;
  int index = linearSearch(arr, n, x);
  if (index == -1) {
    printf("Element is not found!\n");
  } else {
    printf("Element is found at index: %d\n", index);
  }
  return 0;
}