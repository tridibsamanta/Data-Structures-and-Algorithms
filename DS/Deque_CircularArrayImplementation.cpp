/**
 * Title     : Deque (Double Ended Queue) implementation (using circular array)
 * Author    : Tridib Samanta
**/

#include<iostream>
using namespace std;

#define MAX_SIZE 10

int deq[MAX_SIZE];
int front = -1;
int rear = -1;

void printDeque();
void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
int getFront();
int getRear();
int getSize();
bool isEmpty();

int main() {
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {
        int ch;
        cout << "*** Select an operation ***\n";
        cout << "1. Print Deque\n";
        cout << "2. Insert an element at the front\n";
        cout << "3. Insert an element at the rear\n";
        cout << "4. Delete an element from the front\n";
        cout << "5. Delete an element from the rear\n";
        cout << "6. Get element at the front position\n";
        cout << "7. Get element at the rear position\n";
        cout << "8. Check whether Deque is empty\n";
        cout << "9. Get the size\n";
        cout << "10. Exit\n";
        cout << "Enter your choice : ";
        cin >> ch;
        if (ch == 10)
            break;
        else {
            switch (ch) {
                case 1:
                    printDeque();
                    break;
                case 2:
                    int value1;
                    cout << "Enter the value : ";
                    cin >> value1;
                    insertFront(value1);
                    break;
                case 3:
                    int value2;
                    cout << "Enter the value : ";
                    cin >> value2;
                    insertRear(value2);
                    break;
                case 4:
                    deleteFront();
                    break;
                case 5:
                    deleteRear();
                    break;
                case 6:
                    if (getFront() == INT_MIN)
                        cout << "Deque is empty !\n";
                    else
                        cout << "Front element is : " << getFront() << '\n';
                    break;
                case 7:
                    if (getRear() == INT_MIN)
                        cout << "Deque is empty !\n";
                    else
                        cout << "Rear element is : " << getRear() << '\n';
                    break;
                case 8:
                    if (isEmpty())
                        cout << "Deque is empty !\n";
                    else
                        cout << "Deque is not empty !\n";
                    break;
                case 9:
                    cout << "Deque size is : " << getSize() << '\n';
                    break;
                default:
                    cout << "Incorrect choice !\n";
            }
        }
        cout << "Do you want to continue ? ( Y / N )\n";
        cin >> choice;
    }
    return 0;
}

void printDeque() {
    if (front == -1 && rear == -1) {
        cout << "Deque is empty !\n";
        return;
    }
    cout << "Deque is : ";
    int index, totalElements = (rear - front + MAX_SIZE) % MAX_SIZE + 1;
    for (int i = 0; i < totalElements; ++i) {
        index = (front + i) % MAX_SIZE;
        cout << deq[index] << ' ';
    }
    cout << '\n';
}

void insertFront(int value) {
    if ((front - 1 + MAX_SIZE) % MAX_SIZE == rear) {
        cout << "Deque is full ! Insertion failed.\n";
        return;
    }
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;

    deq[front] = value;
    cout << "Insertion successful !\n";
}

void insertRear(int value) {
    if ((rear + 1 + MAX_SIZE) % MAX_SIZE == front) {
        cout << "Deque is full ! Insertion failed.\n";
        return;
    }
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = (rear + 1 + MAX_SIZE) % MAX_SIZE;
    deq[rear] = value;
    cout << "Insertion successful !\n";
}

void deleteFront() {
    if (front == -1 && rear == -1) {
        cout << "Deque is empty ! Deletion failed.\n";
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;

    cout << "Deletion successful !\n";
}

void deleteRear() {
    if (front == -1 && rear == -1) {
        cout << "Deque is empty ! Deletion failed.\n";
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1) % MAX_SIZE;

    cout << "Deletion successful !\n";
}

int getFront() {
    if (front == -1 && rear == -1)
        return INT_MIN;
    else
        return deq[front];
}

int getRear() {
    if (front == -1 && rear == -1)
        return INT_MIN;
    else
        return deq[rear];
}

int getSize() {
    if (front == -1 && rear == -1)
        return 0;
    return (rear - front + MAX_SIZE) % MAX_SIZE + 1;
}

bool isEmpty() {
    if (front == -1 && rear == -1)
        return true;
    return false;
}


void printDeque();
void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
int getFront();
int getRear();
int getSize();
bool isEmpty();

/*
 ~ Time Complexity -
    ~ insertFront() : O(1)
    ~ insertRear()  : O(1)
    ~ deleteFront() : O(1)
    ~ deleteRear()  : O(1)
    ~ getFront()    : O(1)
    ~ getRear()     : O(1)
    ~ getSize()     : O(1)
    ~ isEmpty()     : O(1)
    ~ printQueue()  : O(n)

 ~ Space Complexity : O(n)

   where 'n' is the number of elements in the deque.
*/
