/**
 * Title     : Missing number in array (Using XOR)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    cout << "Enter the range : ";
    int n;
    cin >> n;

    cout << "Enter " << n-1 << " elements : ";
    vector<int> a(n-1);
    for (int i = 0; i < n-1; ++i)
        cin >> a[i];

    int x1 = a[0], x2 = 1;

    for (int i = 1; i < n-1; ++i)
        x1 = x1 ^ a[i];

    for (int i = 2; i <= n; ++i)
        x2 = x2 ^ i;

    cout << "Missing Number is : " << (x1 ^ x2) << "\n";

    return 0;

}

/*
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
*/
