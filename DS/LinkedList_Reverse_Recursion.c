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

void Reverse(struct Node * p) {
    if(p->next==NULL) {
        head=p;
        return;
    }
    Reverse(p->next);
    struct Node * q = p->next;
    q->next=p;
    p->next=NULL;
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
    printf("Before reversal : \n");
    Print(head);
    Reverse(head);
    printf("\nAfter reversal : \n");
    Print(head);
    return 0;
}
