#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* link; 
}Node;
Node* sort_it(Node* ptr1,Node* ptr2){
    Node* head3=(Node*)malloc(sizeof(Node));
    head3->link=NULL;
    Node* ptr3=head3;
    while(ptr1!=NULL && ptr2!=NULL){

        Node* temp=(Node*)malloc(sizeof(Node));
        temp->link=NULL;
        if(ptr1->data <= ptr2->data){
                       
            temp->data=ptr1->data;
            
            ptr1=ptr1->link;
               
        }
        else{
            temp->data=ptr2->data;
            
            ptr2=ptr2->link;
        }
        if(head3==ptr3){
            continue;
        }
        else{
            ptr3->link=temp;
            ptr3=temp;
        }
        }
    return head3; 
    }
void display(Node* head,Node* ptr){
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d->",ptr->data);
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

    Node *head1 = NULL, *temp;
    head1=(Node*)malloc(sizeof(Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head1->data);
    head1->link = NULL; // The first node points to NULL initially

    // Pointer to the current node
    Node* ptr = head1;

    // Create and link the remaining nodes
    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ",i);
        temp = (Node*) malloc(sizeof(Node));
        scanf("%d",&temp->data);
        
        ptr->link=temp;
        ptr=ptr->link;
        temp->link=NULL;
        
    }
    Node *head2 = NULL;
    head2=(Node*)malloc(sizeof(Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head2->data);
    head2->link = NULL; // The first node points to NULL initially

    // Pointer to the current node
    ptr = head2;

    // Create and link the remaining nodes
    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ",i);
        temp = (Node*) malloc(sizeof(Node));
        scanf("%d",&temp->data);
        
        ptr->link=temp;
        ptr=ptr->link;
        temp->link=NULL;
        
    }
    Node* ptr1,*ptr2;
    ptr1=head1;
    ptr2=head2;
    sort_it(ptr1,ptr2);
   
    display(head1,ptr);
    display(head2,ptr);
    Node* head3=NULL;
    head3=sort_it(head3,ptr);
    display(head3,ptr);
}