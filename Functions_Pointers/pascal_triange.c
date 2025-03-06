#include<stdio.h>

int factorial(int n) {
    int k = 1;
    for (int i = 1; i <= n; i++) {
        k = k * i;
    }
    return k;
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r)); // Correct formula
}
int main() {
    int n,r;
    printf("Enter the N and R : ");
    scanf("%d %d",&n,&r);
    for (int i = 0; i <= n; i++)
    {
        for (int l = 0; l < r-i; l++)
        {
            printf(" ");
        }
        
        for (int t = 0; t <= i; t++)
        {
            printf("%d ",(combination(i,t)));
        }
        printf("\n");
        
    }
    return 0;
    
}