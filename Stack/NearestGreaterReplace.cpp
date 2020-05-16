/**
 * Title     : Replace element with nearest greater element
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

void replaceNearestGreater(int arr[], int n) {
    stack<int> S;
    int res[n];
    for (int i = n - 1; i >= 0; --i) {
        while (!S.empty() && arr[i] >= S.top())
            S.pop();

        if (S.empty())
            res[i] = -1;
        else
            res[i] = S.top();

        S.push(arr[i]);
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    replaceNearestGreater(arr, n);
    cout << '\n';
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
