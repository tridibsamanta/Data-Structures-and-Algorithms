#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head; // Global

void Insert(int x);
void Print();

int main() {

    head=NULL; //empty list
    printf("How many numbers ? \n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("\nEnter the number \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
    return 0;
}

void Insert(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}

void Print()
{
    struct Node* temp=head;
    printf("List is : ");
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

