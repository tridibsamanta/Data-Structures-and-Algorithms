#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int x);
void Print();
void Reverse();

int main() {

    head=NULL; //empty list
    printf("Number of elements in the linked list ? \n");
    int n,i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        printf("Enter the %d element = \n",i);
        scanf("%d",&x);
        Insert(x);
    }
    Print();
    Reverse();
    printf("\nAfter Reversing");
    Print();
    return 0;
}

void Insert(int x)
{
    Node* temp=new Node;
    temp->data=x;
    temp->next=head;
    head=temp;
}

void Print()
{
    if(head==NULL) {
        printf("\nEmpty List!");
        return;
    }
    struct Node* temp=head;
    printf("\nList is : ");
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void Reverse() {
    if(head==NULL)
        return;
    stack<struct Node*> S;
    Node * temp = head;
    while(temp!=NULL) {
        S.push(temp);
        temp=temp->next;
    }
    temp=S.top();
    head=temp;
    S.pop();
    while(!S.empty()) {
        temp->next=S.top();
        S.pop();
        temp=temp->next;
    }
    temp->next=NULL;
}
