#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* link; 
}Node;
void display(Node* head,Node* ptr){
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
    
}
Node* copy(Node* new_head,Node* head,int n){
    Node* ptr;
    Node* ptr1=head;
    Node* temp;
    ptr=temp;
    temp=(Node*) malloc(sizeof(Node));
    new_head=temp;
    new_head->data=head->data;
    ptr=new_head;
    ptr->link=NULL;
    for (int i = 2; i <= n; i++)
    {
        
        temp=(Node*) malloc(sizeof(Node));
        ptr->link=temp;
        temp->data=ptr1->data;
        ptr=ptr->link;
        temp->link=NULL;

    }
    return new_head;
    
}
int main(){
    int n;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // If the user enters a non-positive number of nodes, exit the program
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    Node *head = NULL, *temp;
    head=(Node*)malloc(sizeof(Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->link = NULL; // The first node points to NULL initially

    // Pointer to the current node
    Node* ptr = head;

    // Create and link the remaining nodes
    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ",i);
        temp = (Node*) malloc(sizeof(Node));
        scanf("%d",&temp->data);
        
        ptr->link=temp;
        ptr=ptr->link;
        temp->link=NULL;
        
    }
    display(head,ptr);
    Node* new_head;
    new_head=copy(new_head,head,n);
    display(head,ptr);
}