#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node * next;
    };

struct Node * head;

void Insert(int data, int n);
void Print();

int main() {
    head=NULL; //empty list
    printf("How many nodes you want to insert ?\n");
    int nodes,i,data,pos;
    scanf("%d",&nodes);
    for(i=0;i<nodes;i++) {
        printf("Enter the data - \n");
        scanf("%d",&data);
        printf("Enter the position - \n");
        scanf("%d",&pos);
        Insert(data,pos);
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
    struct Node * temp = head;
    printf("The list is - \n");
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
