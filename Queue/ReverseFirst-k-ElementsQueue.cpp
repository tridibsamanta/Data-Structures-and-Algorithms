/**
 * Title     : Reverse the first K elements of a Queue
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

void reverse_k_elements(queue<int> &q, int k) {

    // Preliminary check to avoid abnormal behavior of code
    if (k > q.size() || k <= 0 || q.empty())
        return;

    // Initialize a auxiliary stack
    stack<int> aux;

    // Dequeue the first 'k' elements from the queue and push them into the stack
    for (int i = 0; i < k; ++i) {
        aux.push(q.front());
        q.pop();
    }

    // Pop all the elements from the stack and enqueue them to the queue
    while (!aux.empty()) {
        q.push(aux.top());
        aux.pop();
    }

    // Dequeue the first (Queue size - k) elements from the queue and enqueue them to the same queue
    for (int i = 0; i < (q.size() - k); ++i) {
        q.push(q.front());
        q.pop();
    }

}

int main() {

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    queue<int> q;

    int element;
    cout << "Enter the elements of the queue : ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        q.push(element);
    }

    int k;
    cout << "Enter the number of elements to reverse : ";
    cin >> k;

    reverse_k_elements(q, k);

    cout << "Modified Queue is : ";
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
