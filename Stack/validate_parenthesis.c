#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
void push(char symbol){
    stack[++top]=symbol;
}
char pop(){
    char c=stack[top];
    stack[top]='\0';
    top--;
    return c;
}
int toValidate(){
    int k=1;
    if(strlen(stack)%2!=0){
        
        return 0;
    }
    else 
    {
        
        for (int i = 0; i < strlen(stack); i++)
        {
            char par=pop();
            if(par==')' || par =='}' || par==']'){
                if(par=='(' && (stack[top]=='}' && stack[top]==']')){
                    k=0;
                }
                else if(par=='{' && (stack[top]==')' && stack[top]==']')){
                    k=0;
                }
                else if(par=='[' && (stack[top]=='}' && stack[top]==')')){
                    k=0;
                }
            }
            
        }
               
    }
    return k; 
}
int main(){
    printf("Enter the paranthesis : \n");
    gets(stack);
    int val=toValidate();
    if(val==0){
        printf("Not valid");
    }
    else
    {
        printf("Valid");
    }
    
}