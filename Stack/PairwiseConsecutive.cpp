/**
 * Title     : Check if stack elements are pairwise consecutive
 * Author    : Tridib Samanta
**/

#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

bool checkConsecutivePair(stack<int> S){

    bool res = true;

    stack<int> aux;
    while (!S.empty()) {
        aux.push(S.top());
        S.pop();
    }

    while (aux.size() > 1) {

        int temp1 = aux.top();
        aux.pop();
        int temp2 = aux.top();
        aux.pop();

        if (abs(temp1 - temp2) != 1)
            res = false;

        S.push(temp1);
        S.push(temp2);
    }

    if (aux.size() == 1)
        S.push(aux.top());

    return res;

}


int main() {

    int n;
    cin >> n;

    stack<int> S;

    int element;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        S.push(element);
    }

    if (checkConsecutivePair(S))
        cout << "Successive pairs are consecutive\n";
    else
        cout << "Successive pairs are not consecutive\n";

    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
