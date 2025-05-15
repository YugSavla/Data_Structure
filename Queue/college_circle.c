#include <stdio.h>
int findWinner(int n, int k) {
   int winner = 0;
   for (int i = 2; i <= n; i++)
       winner = (winner + k) % i;
   return winner +1;    
}
int main() {
    int n = 5, k = 2;
    printf("Winner is person %d\n", findWinner(n, k));
    return 0;
 }