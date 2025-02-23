#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* link; 
}Node;

int main(){
    Node* head, *second,*third;
    
    // Allocate memory for the nodes in the heap in the linked list
    head = (Node*) malloc(sizeof(Node));
    second = (Node*) malloc(sizeof(Node));
    third = (Node*) malloc(sizeof(Node));

    //Allocate ptr after allocating to memory as it has been not alloted yet
    Node* ptr=head;

    //Link first and second nodes
    head->data=7;
    head->link=second;

    //Link 2nd and 3rd node
    second->data=10;
    second->link=third;

    //No more link
    third->data=13;
    third->link=NULL;

    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
    free(head);
    free(second);
    free(third);
    return 0;
}