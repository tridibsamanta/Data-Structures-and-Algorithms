/**
 * Title     : Trapping Rain Water (Brute force)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findTrappedWater(int arr[], int n) {
    if (n == 0 || n == 1)
        return 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int leftMax = arr[i];
        for (int j = 0; j < i; ++j)
            leftMax = max(leftMax, arr[j]);
        int rightMax = arr[i];
        for (int j = i + 1; j < n; ++j)
            rightMax = max(rightMax, arr[j]);
        res += min(leftMax, rightMax) - arr[i];
    }
    return res;
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    int arr[n];
    if (n != 0) {
        cout << "Enter " << n << " elements : ";
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
    }
    cout << "Result : "<< findTrappedWater(arr, n) << '\n';
    return 0;
}

/*
 ~ Time Complexity  : O(n^2)
 ~ Space Complexity : O(1)
*/
