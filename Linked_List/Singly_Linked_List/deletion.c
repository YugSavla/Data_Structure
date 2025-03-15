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

Node* delete_begin(Node* head,Node*ptr){
    ptr=head;
    head=head->link;
    free(ptr);
    return head;

}

void delete_end(Node* head,Node*ptr){
    Node* pre;
    ptr = head;
    while (ptr->link!=NULL)
    {
        pre=ptr;
        ptr=ptr->link;
    }
    pre->link=NULL;
    free(ptr);
}


void delete_after(Node* head,Node* ptr){
    int data;
    printf("\nEnter the data after want to delete: ");
    scanf("%d",&data);
    ptr=head;
    Node* temp;
    Node* temp1;

    while(ptr->data!=data){
        
        ptr=ptr->link;
        temp=ptr->link;

    }
    temp1=temp->link;
    ptr->link=temp1;

    free(temp);

    
}

void delete_before(Node* head,Node*ptr){
    int data;
    printf("\nEnter the data Before want to delete: ");
    scanf("%d",&data);
    ptr=head;
    Node* temp;
    Node* temp1;
    while (ptr->data!=data)
    {
        temp1=temp;
        temp=ptr;
        ptr=ptr->link;
    }
    temp1->link=ptr;
    free(temp);
    
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
    // head=delete_begin(head,ptr);
    // delete_end(head,ptr);
    // delete_after(head,ptr);
    delete_before(head,ptr);
    display(head,ptr);
}