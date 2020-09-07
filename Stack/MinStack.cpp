/**
 * Title     : Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<int> s;
    int minElement;

    MinStack() {
        while (!s.empty())
            s.pop();

        minElement = -1;
    }

    void push(int x) {

        if (s.empty()) {
            s.push(x);
            minElement = x;
        }
        else {
            if (x < minElement) {
                s.push(2 * x - minElement);
                minElement = x;
            }
            else
                s.push(x);
        }
    }

    void pop() {

        if (s.empty())
            return;

        if (s.top() < minElement)
            minElement = 2 * minElement - s.top();

        s.pop();
    }

    int top() {

        if (s.empty())
            return -1;

        if (s.top() > minElement)
            return s.top();

        return minElement;
    }

    int getMin() {
        return minElement;
    }
};

int main() {

    MinStack s;

    s.push(3);
    s.push(5);
    cout << "Minimum Element : " << s.getMin() << '\n';
    s.push(2);
    s.push(1);
    cout << "Minimum Element : " << s.getMin() << '\n';
    s.pop();
    cout << "Minimum Element : " << s.getMin() << '\n';
    s.pop();
    cout << "Top Element : " << s.top() << '\n';

    return 0;
}

/*
 ~ Time Complexity
    ~ push()        : O(1)
    ~ pop()         : O(1)
    ~ top()         : O(1)
    ~ getMin()      : O(1)

 ~ Auxiliary Space  : O(1)
*/
