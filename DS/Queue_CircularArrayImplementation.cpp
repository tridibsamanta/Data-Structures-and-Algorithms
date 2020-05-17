/**
 * Title     : Queue implementation (Using circular array)
 * Author    : Tridib Samanta
**/

#include<iostream>
using namespace std;

#define MAX_SIZE 10     // Limiting the capacity of the queue to 10 elements

int Q[MAX_SIZE];        // Integer type global array with size equal to MAX_SIZE
int front = -1;         // Global front pointer points to -1 initially, empty queue
int rear = -1;          // Global rear pointer points to -1 initially, empty queue

void printQueue();      // Prints all the elements present in the queue
void enqueue(int);      // Inserts an element at the rear end of the queue
void dequeue();         // Deletes an element from the front end of the queue
int getFront();         // Returns the element at the front of the queue
int getSize();          // Returns the number of elements presently stored in the queue
bool isEmpty();         // Checks whether the queue is empty

int main() {
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {
        int ch;
        cout << "*** Select an operation ***\n";
        cout << "1. Print queue\n";
        cout << "2. Enqueue (Insert an element)\n";
        cout << "3. Dequeue (Delete an element)\n";
        cout << "4. Get element at the front position\n";
        cout << "5. Get the size\n";
        cout << "6. Check if queue is empty\n";
        cout << "7. Exit\n";
        cout << "Enter your choice : ";
        cin >> ch;
        if (ch == 7)
            break;
        else {
            switch (ch) {
                case 1:
                    printQueue();
                    break;
                case 2:
                    int value;
                    cout << "Enter the value : ";
                    cin >> value;
                    enqueue(value);
                    break;
                case 3:
                    dequeue();
                    break;
                case 4:
                    if (getFront() == INT_MIN)
                        cout << "Queue is empty !\n";
                    else
                        cout << "Front element is : " << getFront() << '\n';
                    break;
                case 5:
                    cout << "Queue size is : " << getSize() << '\n';
                    break;
                case 6:
                    if (isEmpty())
                        cout << "Queue is empty !\n";
                    else
                        cout << "Queue is not empty !\n";
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

// Implementing - printQueue()

void printQueue() {
    if (front == -1 && rear == -1) {    // Check whether queue is empty
        cout << "Queue is empty !\n";
        return;
    }
    cout << "Queue : ";
    int index, totalElements = (rear - front + MAX_SIZE) % MAX_SIZE + 1; // Calculate the total number of elements
    for (int i = 0; i < totalElements; ++i) {   // Loop to print all the elements in the queue
        index = (front + i) % MAX_SIZE;     // Calculate the index of a particular element
        cout << Q[index] << " ";    // Print the element at that particular index
    }
    cout << '\n';
}

// Implementing - enqueue()

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {   // Check whether queue is full (Over-flow)
        cout << "Queue is full ! Insertion failed.\n";
        return;
    }
    else if (front == -1 && rear == -1)    // Check whether queue is empty
        front = rear = 0;   // Update both the front and rear index to 0
    else
        rear = (rear + 1) % MAX_SIZE;    // Calculate the rear index where element is to be inserted

    Q[rear] = value; // Insert the value at rear index
    cout << "Insertion successful !\n";
}

// Implementing - dequeue()

void dequeue() {
    if (front == -1 && rear == -1) {    // Check whether queue is empty (Under-flow)
        cout << "Queue is empty ! Deletion failed.\n";
        return;
    }
    else if (front == rear) {   // Queue contains a single element
        front = rear = -1;      // Update both front and rear to -1, makes queue empty
        cout << "Deletion successful !\n";
        return;
    }
    else {
        front = (front + 1) % MAX_SIZE;     // Update the front index by one
        cout << "Deletion successful !\n";
        return;
    }
}

// Implementing - getFront()

int getFront() {
    if (front == -1 && rear == -1)  // Check whether queue is empty
        return INT_MIN;
    else
        return Q[front]; // Returns the element at front index
}

// Implementing - getSize()

int getSize() {
    if (front == -1 && rear == -1) // Check whether queue is empty
        return 0;
    return (rear - front + MAX_SIZE) % MAX_SIZE + 1;    // Returns the number of elements in the queue
}

// Implementing - isEmpty()

bool isEmpty() {
    if (front == -1 && rear == -1) // Check whether queue is empty
        return true;  // If queue is empty, function returns true
    return false;  // If queue is not empty, function returns false
}

/*
 ~ Time Complexity -
    ~ enqueue()     : O(1)
    ~ dequeue()     : O(1)
    ~ getFront()    : O(1)
    ~ getSize()     : O(1)
    ~ isEmpty()     : O(1)
    ~ printQueue()  : O(n)

 ~ Space Complexity : O(n)

   where 'n' is the number of elements in the queue.
*/

