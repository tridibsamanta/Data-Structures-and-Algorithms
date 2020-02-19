#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * link;
};

struct Node * top;

void Push(int x) {
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=top;
    top=temp;
}

void Pop() {
    struct Node * temp;
    if(top==NULL) return;
    temp=top;
    top=top->link;
    free(temp);
}

int IsEmpty() {
    if(top==NULL)
        return 1;
    else
        return 0;
}

int Top() {
    return(top->data);
}

void Print() {
    struct Node * temp = top;
    if(temp==NULL) {
        printf("Hey ! Stack is empty..\n");
        return;
    }
    printf("Stack : \n");
    while(temp!=NULL) {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main() {
    top=NULL;
    //Perform some Push() and Pop() operations and Print() the stack contents
    Push(2); Push(4); Push(7); Print();
    Pop(); Print();
    Push(6); Print();
    //Check if Stack is empty or not
    printf("\nIs stack empty ?\n");
    if(IsEmpty())
        printf("Yes\n");
    else
        printf("No\n");

    int top_data = Top();
    printf("\nData at the top of stack = %d\n",top_data);

    return 0;
}
