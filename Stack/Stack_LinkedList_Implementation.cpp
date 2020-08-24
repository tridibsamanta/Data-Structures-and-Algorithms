/**
 * Title     : Implement Stack using Linked List
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }
};

class Stack {
private:
    Node *head;
    int size;
public:
    Stack();
    void push(int);
    int pop();
    int getSize();
    bool isEmpty();
    int top();
    void printStack();
};

Stack :: Stack() {
    head = NULL;
    size = 0;
}

void Stack :: push(int element) {
    Node *newNode = new Node(element);
    newNode -> next = head;
    head = newNode;
    ++size;
}

int Stack :: pop() {
    if (size == 0)
        return INT_MIN;
    int topElement = head -> data;
    Node *temp = head;
    head = head -> next;
    delete temp;
    --size;
    return topElement;
}

int Stack :: getSize() {
    return size;
}

bool Stack :: isEmpty() {
    if (size == 0)
        return true;
    return false;
}

int Stack :: top() {
    if (size == 0)
        return INT_MIN;

    return head -> data;
}

void Stack :: printStack() {
    if (size == 0) {
        cout << "Stack is empty !\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        cout << temp -> data << '\n';
        temp = temp -> next;
    }
    cout << '\n';
}

int main() {

    Stack S;

    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {

        cout << "*** Select your choice ***\n";
        cout << "1. Push element into the stack\n";
        cout << "2. Pop elements from the stack\n";
        cout << "3. Print all stack elements\n";
        cout << "4. Get top element of the stack\n";
        cout << "5. Get stack size\n";
        cout << "6. Check stack is empty or not\n";
        cout << "Enter your choice : ";

        int ch = 0;
        cin >> ch;

        switch(ch) {
        case 1:
            {
            cout << "Enter the value : \n";
            int val;
            cin >> val;
            S.push(val);
            break;
            }
        case 2:
            {
            int deletedElement = S.pop();
            if (deletedElement == INT_MIN)
                cout << "Stack is already empty !\n";
            else
                cout << "Element " << deletedElement << " successfully deleted from stack !\n";
            break;
            }
        case 3:
            {
            if (!S.isEmpty())
                cout << "Stack elements are : \n";
            S.printStack();
            break;
            }
        case 4:
            {
            int topElement = S.top();
            if (topElement == INT_MIN)
                cout << "Stack is empty !\n";
            else
                cout << "Top element of the stack : " << topElement << '\n';
            break;
            }
        case 5:
            {
            int stackSize = S.getSize();
            cout << "Stack contains " << stackSize << " elements \n";
            break;
            }
        case 6:
            {
            if (S.isEmpty())
                cout << "Stack is empty !\n";
            else
                cout << "Stack is not empty !\n";
            break;
            }
        default:
            cout << "Incorrect Choice !\n";
        }

        cout << "Do you want to continue ? (Y / N) \n";
        cin >> choice;
    }

    return 0;
}

/*
 ~ Time Complexity
    ~ push()        : O(1)
    ~ pop()         : O(1)
    ~ getSize()     : O(1)
    ~ isEmpty()     : O(1)
    ~ top()         : O(1)
    ~ printStack()  : O(n)
*/
