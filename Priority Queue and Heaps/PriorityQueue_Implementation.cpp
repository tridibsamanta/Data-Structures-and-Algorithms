/**
 * Title     : Priority Queue Implementation (Using Binary Max-Heap property)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

vector<int> pq;

int getParentIdx(int pos) {
    return (pos - 1) / 2;
}
// Time Complexity : O(1)

int getLeftChildIdx(int pos) {
    return (2 * pos) + 1;
}
// Time Complexity : O(1)

int getRightChildIdx(int pos) {
    return (2 * pos) + 2;
}
// Time Complexity : O(1)

int getTop() {
    if (pq.size() == 0)
        return INT_MIN;
    return pq[0];
}
// Time Complexity : O(1)

void heapifyDown(int pos) {

    int leftChildIdx = getLeftChildIdx(pos);
    int rightChildIdx = getRightChildIdx(pos);

    int maxIdx = pos;

    if ((leftChildIdx < pq.size()) && (pq[leftChildIdx] > pq[pos]))
        maxIdx = leftChildIdx;
    if ((rightChildIdx < pq.size()) && (pq[rightChildIdx] > pq[pos]))
        maxIdx = rightChildIdx;

    if (maxIdx != pos) {
        swap(pq[pos], pq[maxIdx]);
        heapifyDown(maxIdx);
    }
}
// Time Complexity : O(log n)

void heapifyUp(int pos) {

    int parentIdx = getParentIdx(pos);

    if ((parentIdx >= 0) && (pq[parentIdx] < pq[pos])) {
        swap(pq[pos], pq[parentIdx]);
        heapifyUp(parentIdx);
    }
}
// Time Complexity : O(log n)

void insertElement(int element) {
    pq.emplace_back(element);
    int idx = pq.size() - 1;
    heapifyUp(idx);
}
// Time Complexity : O(log n)

int deleteElement() {
    if (pq.size() == 0)
        return INT_MIN;
    int element = pq[0];
    pq[0] = pq.back();
    pq.pop_back();
    heapifyDown(0);
    return element;
}
// Time Complexity : O(log n)

void printPQ() {
    if (pq.size() == 0) {
        cout << "Priority Queue is empty !" << '\n';
        return;
    }
    printf("Priority Queue is : ");
    for (int i = 0; i < pq.size(); ++i)
        cout << pq[i] << ' ';
    cout << '\n';
}
// Time Complexity : O(n)

int main() {

    printPQ();

    insertElement(7); insertElement(9); insertElement(4);
    insertElement(3); insertElement(5);
    printPQ();

    int deleted = deleteElement();
    if (deleted == INT_MIN)
        cout << "Priority Queue is already empty !" << '\n';
    else
        cout << "Deleted Element = " << deleted << '\n';
    printPQ();

    int topElement = getTop();
    if (topElement == INT_MIN)
        cout << "Priority Queue is empty !" << '\n';
    else
        cout << "Element with max priority is = " << topElement << '\n';

    return 0;
}
