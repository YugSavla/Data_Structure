#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* link; 
}Node;
void s_last_node_data(Node* head,Node* ptr,int n){
    ptr=head;
    //  for (int i = 0; i < n-1; i++)
    //  {
    //         if(i==n-2){
    //             printf("\nSecond last Node : %d",ptr->data);
    //         }
    //         ptr=ptr->link;
    //  }
    while (ptr->link->link!=NULL)
    {
        ptr=ptr->link;
        if(ptr->link->link==NULL){
            printf("\nSecond last Node : %d",ptr->data);
        }
        
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
    
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    // last_node_data(head,ptr);
    s_last_node_data(head,ptr,n);
}