/**
 * Title     : Stock Span
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

void findSpans(int arr[], int n, int span[]) {
    stack<int> S;
    for (int i = 0; i < n; ++i) {
        while (!S.empty() && arr[i] >= arr[S.top()])
            S.pop();
        if (S.empty())
            span[i] = i + 1;
        else
            span[i] = i - S.top();
        S.push(i);
    }
}

int main() {
    int n;
    cout << "Enter the number of days : ";
    cin >> n;
    int arr[n];
    cout << "Enter stock price for " << n << " days : ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int S[n];
    findSpans(arr, n, S);
    cout << "Span of stock's price : ";
    for (int i = 0; i < n; ++i)
        cout << S[i] << ' ';
    cout << '\n';
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
