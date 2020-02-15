#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node * next;
    };

struct Node * head; //Global head pointer

void Insert(int data, int pos_insert);
void Print();
void Delete(int pos_delete);

int main() {
    head=NULL; //empty list
    int nodes_insert,nodes_delete,i,data_insert,pos_insert,pos_delete;
    printf("How many nodes you want to insert ?\n");
    scanf("%d",&nodes_insert);
    for(i=0;i<nodes_insert;i++) {
        printf("Enter the data - \n");
        scanf("%d",&data_insert);
        printf("Enter the position - \n");
        scanf("%d",&pos_insert);
        Insert(data_insert,pos_insert);
    }
    Print();
    printf("How many nodes you want to delete ?\n");
    scanf("%d",&nodes_delete);
    for(i=0;i<nodes_delete;i++) {
        printf("Enter the position - \n");
        scanf("%d",&pos_delete);
        Delete(pos_delete);
    }
    Print();
    return 0;
}

void Insert(int data, int n) {
    struct Node * temp1 = (struct Node *)malloc(sizeof(struct Node *));
    temp1->data=data;
    temp1->next=NULL;
    if(n==1) {
        temp1->next=head;
        head=temp1;
        return;
    }
    struct Node * temp2 = head;
    int i;
    for(i=0;i<n-2;i++) {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void Print() {
    if(head==NULL)
        printf("\nHey ! The list is empty.\n");
        return;
    struct Node * temp = head;
    printf("The list is - \n");
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Delete(int n) {
    struct Node * temp1 = head;
    if(n==1) {
        head=temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<n-2;i++) {
        temp1 = temp1->next; //(n-1)th Node
    }
    struct Node * temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    free(temp2);
}
