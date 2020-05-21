/**
 * Title     : Interleave the first half of a queue with the second half
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int> &q) {

    // If there are odd number of elements in the queue
    if (q.size() % 2 != 0) {
        cout << "Enter even number of elements\n";
        return;
    }

    // Initialize an auxiliary stack
    stack<int> s;

    int halfSize = q.size() / 2;

    // Push first half of elements from the queue to the stack
    for(int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue all the stack elements to the queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Enqueue and dequeue the first half of the queue to the same queue
    for (int i = 0; i < halfSize; ++i) {
        q.push(q.front());
        q.pop();
    }

    // Push the first half of the queue into the stack
    for (int i = 0; i < halfSize; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue the top element from the stack and pop it, enqueue the front element of the queue and dequeue it
    // Continue to do this unless the stack is void
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

}

int main() {

    int n;
    cout << "Enter the size of the queue = ";
    cin >> n;

    queue<int> q;

    cout << "Enter the queue elements : ";
    int element = 0;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        q.push(element);
    }

    interleaveQueue(q);

    cout << "Interleaved Queue is : ";
    for(int i = 0; i < n; ++i) {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
