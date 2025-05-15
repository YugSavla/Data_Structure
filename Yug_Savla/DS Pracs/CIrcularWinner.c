#include <stdio.h>

int findTheWinner(int n, int k) {
    int queue[500], front = 0, rear = n - 1;

    // Fill initial queue with 1 to n
    for (int i = 0; i < n; i++)
        queue[i] = i + 1;

    while (front < rear) {
        // Skip (k - 1) friends
        for (int i = 0; i < k - 1; i++) {
            queue[++rear] = queue[front++]; // rotate
        }
        front++; // eliminate k-th friend
    }

    return queue[front]; // last remaining friend
}

int main() {
    int n, k;
    printf("Enter number of friends (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    int winner = findTheWinner(n, k);
    printf("The winner is: %d\n", winner);
    return 0;
}
