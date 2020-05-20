/**
 * Title     : Implement a queue using two stacks
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

stack<long int> S1, S2;

void enqueue(int x) {
    S1.push(x);
}

int dequeue() {
    if (S2.empty() && S1.empty())
        return -1;
    if (S2.empty()) {
        while (!S1.empty()) {
            S2.push(S1.top());
            S1.pop();
        }
    }
    int element = S2.top();
    S2.pop();
    return element;
}

int printFront() {
    if (S2.empty() && S1.empty())
        return -1;
    if (S2.empty()) {
        while (!S1.empty()) {
            S2.push(S1.top());
            S1.pop();
        }
    }
    return S2.top();
}

int main() {
    int q;
    cin >> q;
    while (q--) {

        int type;
        cin >> type;

        switch(type) {
            case 1: {
                int element;
                cin >> element;
                enqueue(element);
                break;
            }
            case 2: {
                int element;
                element = dequeue();
                break;
            }
            case 3: {
                int element;
                element = printFront();
                cout << element << '\n';
            }
            default :
                // Do nothing
                break;
        }
    }
    return 0;
}
