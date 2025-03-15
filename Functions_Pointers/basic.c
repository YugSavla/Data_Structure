#include<stdio.h>
void greet(){
    printf("Namaste ");
    return ;
}
int main(){
    // greet();
    // greet();
    int x=5;
    int* ptr;
    ptr=&x;
    printf("\n%d",*ptr);
    *ptr=7;
    printf("\n%d",*ptr);
    printf("\n%p",&x);
    printf("\n%p",ptr);
    printf("\n%p",&ptr);
    return 0;
}