#include<stdio.h>
void push(int stack[],int top){
    int x;
    top++;
    if(top==10){
        printf("\nOverflow");
    }
    else{
        printf("\nEnter the number : ");
        scanf("%d",&x);
        stack[top]=x;
    }
    
}
void pop(int stack[],int top){
    
}
int main(){
    int stack[10];
    int top=-1;

}
