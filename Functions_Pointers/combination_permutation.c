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

int permutation(int n,int r){
    return factorial(n) /  factorial(n - r);
}

int main() {
    int n,r;
    printf("Enter the N and R : ");
    scanf("%d %d",&n,&r);
    printf("Combination of 5C3 is : %d\n", combination(n, r));
    printf("Permutation of 5P3 is : %d", permutation(n, r));

    return 0;
}
