#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char stack[max];
char infix[max];
char postfix[max];
int top=-1;
int j=0;
int prec(char c) {
    
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void push(char symbol){
    stack[++top]=symbol;
}
char pop(){
    char c=stack[top];
    stack[top]='\0';
    top--;
    return c;
}
void inToPost(){
    char symbol,next;
    
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol=infix[i];
        if(symbol=='('){
            push(symbol);    
        }
        else if(symbol==')'){
            while (top!=-1 && stack[top]!='('){
                next=pop();
                
                postfix[j++]=next;
            }
            if (top != -1) {
                pop();  // Pop the '(' but don't add to result
            }
            //postfix[j++]=symbol
            
        }
        else if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^'){
            // Handle right associativity for '^' operator
            if (symbol == '^') {
                while(top!=-1 && (prec(stack[top]) > prec(symbol))){
                    next=pop();
                    postfix[j++]=next;    
                }
            } else {
                while(top!=-1 && (prec(stack[top]) >= prec(symbol))){
                    next=pop();
                    postfix[j++]=next;    
                }
            }
            push(symbol);
        }
        else{
            postfix[j++]=symbol;
        }
    }
    while(top!=-1){
        postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
    
}
int main() {
    printf("Enter the infix: \n");
    fgets(infix, sizeof(infix), stdin);  // Use fgets to avoid unsafe gets
    infix[strcspn(infix, "\n")] = '\0';  // Remove the newline character from fgets input
    inToPost();
    
    printf("checking stack: ");
    puts(stack);
    printf("Postfix: ");
    puts(postfix);  // Print the postfix expression

    return 0;
}