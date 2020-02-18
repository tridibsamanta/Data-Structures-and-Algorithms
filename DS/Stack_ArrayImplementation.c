#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top=-1;

void Push(int x) {
    if(top==MAX_SIZE-1) {
        printf("Error : Stack Overflow !\n");
        return;
    }
    top++;
    A[top]=x;
}

void Pop() {
    if(top==-1) {
        printf("Error : Stack is empty !\n");
        return;
    }
    top--;
}

int Top() {
    return A[top];
}

void Print() {
    if(top==-1) {
        printf("Stack is empty !\n");
        return;
    }
    int i;
    printf("Stack : ");
    for(i=0;i<=top;i++)
        printf("%d ",A[i]);
    printf("\n");
}

int main() {
    printf("1->Push\n");
    printf("2->Pop\n");
    printf("3->Print\n");
    printf("Enter your choice ? \n");
    int ch,val;
    scanf("%d",&ch);
    switch(ch) {
    case 1:
        printf("Enter the value : \n");
        scanf("%d",&val);
        Push(val);
        break;
    case 2:
        printf("Executing Pop function !\n");
        Pop();
        break;
    case 3:
        Print();
        break;
    default:
        printf("Enter the choice correctly !\n");
    }
    int cnt;
    printf("\nDo you want to continue ? 1->Yes 0->Exit \n");
    scanf("%d",&cnt);
    if(cnt==1)
        main();
    printf("\n");
    return 0;
}
