#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* link; 
}Node;
void display(Node* head){
    Node* ptr=head;
    while (ptr->link!=NULL)
    {
        printf("%d -> ",ptr->link->data);
        ptr=ptr->link;
    }
}
void s_last_node_data(Node* head,Node* ptr,int n){
    ptr=head;
    //  for (int i = 0; i < n-1; i++)
    //  {
    //         if(i==n-2){
    //             printf("\nSecond Largest Node : %d",ptr->data);
    //         }
    //         ptr=ptr->link;
    //  }
    while (ptr->link->link!=NULL)
    {
        if(ptr->link->link==NULL){
            printf("\nSecond Largest Node : %d",ptr->data);
        }
        ptr=ptr->link;
    }
    
     
}
void last_node_data(Node* head,Node* ptr){
    ptr=head;
    while (ptr!=NULL)
    {
        if(ptr->link==NULL){
            printf("\nLast Node Data : %d ",ptr->data);
        }
        
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
    display(head);

    // last_node_data(head,ptr);
    // s_last_node_data(head,ptr,n);
}