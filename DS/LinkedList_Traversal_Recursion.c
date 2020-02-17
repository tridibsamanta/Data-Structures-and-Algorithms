#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node * next;
    };

struct Node * head = NULL;

void Print(struct Node * temp) {
    if(temp==NULL)
        return;
    printf("%d ",temp->data);
    Print(temp->next);
}

void ReversePrint(struct Node * temp) {
    if(temp==NULL)
        return;
    ReversePrint(temp->next);
    printf("%d ",temp->data);
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

int main() {
    head=NULL;
    Insert(20,1);
    Insert(40,2);
    Insert(60,3);
    Insert(50,4);
    printf("The list is : \n");
    Print(head);
    printf("\nThe reversed list is : \n");
    ReversePrint(head);
    return 0;
}
