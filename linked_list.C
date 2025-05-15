#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
	
}Node;
Node* head=NULL;

void display(Node* head){
    Node* temp= head;
    while(temp!=NULL){
	printf("%d->",temp->data);
	temp=temp->next;
    }
    printf("\n");
}

Node* initial(Node* head){
    int data=0;
    printf("Initialize it !!!!!!!!!!!!!!!!!\n");
    head = (Node*)malloc(sizeof(Node));
    printf("Enter Data : ");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    return head;
}

Node* insert_beg(Node* head){
    Node* ptr=head;
    int data;
    printf("Insert at the beginning\n");
    Node* temp = (Node*)malloc(sizeof(Node));
    printf("Enter Data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=ptr;
    head=temp;
    return head;
    temp=NULL;
}

void insert_end(Node* head){
    Node* ptr=head;
    int data=0;
    printf("Insert at the END !!!!!!!!!\n");

    while(ptr->next!=NULL){
	ptr=ptr->next;
    }
    Node* temp=(Node*)malloc(sizeof(Node));
    printf("Enter Data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    ptr->next=temp;
}

void insert_after(Node* head,int aft){
    Node* ptr=head;
    int data=0;
    printf("Insert after the node\n");

    while(ptr->data!=aft){
	ptr=ptr->next;
    }
    Node* temp=(Node*)malloc(sizeof(Node));
    printf("Enter Data : ");
    scanf("%d",&data);
    temp->data=data;
    temp->next=ptr->next;
    ptr->next=temp;  
}

void insert_before(Node* before,int bef){
    Node* ptr=head;
    Node* tem=ptr;
    int data=0;
    printf("Insert befor the node\n");

    while(ptr->data!=bef){
        tem=ptr;
	ptr=ptr->next;
    }
    Node* temp=(Node*)malloc(sizeof(Node));
    printf("Enter Data : ");
    scanf("%d",&data);
    temp->data=data;
    tem->next=temp;
    temp->next=ptr;

}
Node* delete_beg(Node* head){
    Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

void* delete_end(Node* head){
    Node* ptr = head;
    while(ptr->next!=NULL){
	ptr=ptr->next;
    }
    free(ptr);
}

int main(){
    head=initial(head);
    head=insert_beg(head);
    insert_end(head);
    insert_after(head,1);
    insert_before(head,1);
    display(head);
    head=delete_beg(head);
    delete_end(head);
    display(head);
}
