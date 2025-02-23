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
    
}
Node* insert_beg(Node* head){
    int n;
    Node* tem;
    printf("\nInsertion at the beginning : ");
    printf("\nEnter the node of data how many times : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        tem=(Node*) malloc(sizeof(Node));
        printf("Enter the data of the node : ");
        scanf("%d",&tem->data);
        tem->link=head;
        head=tem;
    }
    return head;
    
}
void insert_end(Node* head,Node* ptr){
    int n;
    ptr=head;
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    printf("\nInsertion at the Ending : ");
    printf("\nEnter the node of data how many times : ");
    scanf("%d",&n);
    Node* temp;
    for (int i = 0; i < n; i++)
    {
        temp=(Node*) malloc(sizeof(Node));
        printf("Enter the data of the node : ");
        scanf("%d",&temp->data);
        ptr->link=temp;
        temp->link=NULL;
        ptr=ptr->link;
    }
    
    
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

    // head=insert_beg(head);
    insert_end(head,ptr);
    
    display(head,ptr);
}