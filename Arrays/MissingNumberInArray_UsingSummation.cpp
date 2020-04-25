/**
 * Title     : Missing number in array (Using Summation)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    cout << "Enter the range : ";
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;

    vector<int> a(n-1);

    cout << "Enter " << n-1 << " elements : ";
    for (int i = 0; i < n-1; ++i) {
        cin >> a[i];
        sum -= a[i];
    }

    cout << "Missing Number is : " << sum << "\n";

    return 0;

}

/*
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
*/
