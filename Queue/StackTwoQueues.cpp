/**
 * Title     : Implement a stack using two queues
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

queue<long int> q1, q2;

void push(long int x) {
    q1.push(x);
}

long int pop() {
    if (q1.empty())
        return -1;
    while (q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
    }

    long int topElement = q1.front();
    q1.pop();

    queue<long int> q = q1;
    q1 = q2;
    q2 = q;

    return topElement;
}

long int top() {
    if (q1.empty())
        return -1;
    while (q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
    }
    long int topElement = q1.front();
    q2.push(q1.front());
    q1.pop();

    queue<long int> q = q1;
    q1 = q2;
    q2 = q;

    return topElement;
}

int main() {
    int q;
    cin >> q;
    while (q--) {

        int type;
        cin >> type; // 1 -> push(), 2 -> pop(), 3 -> top()

        switch(type) {
            case 1: {
                long int element;
                cin >> element;
                push(element);
                break;
            }
            case 2: {
                long int element = pop();
                cout << element << '\n';
                break;
            }
            case 3: {
                long int element = top();
                cout << element << '\n';
            }
            default :
                // Do nothing
                break;
        }
    }
    return 0;
}
