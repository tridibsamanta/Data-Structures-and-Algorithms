/**
 * Title     : Trapping Rain Water (Using two auxiliary arrays)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findTrappedWater(int arr[], int n) {
    if (n == 0 || n == 1)
        return 0;
    int leftMax[n], rightMax[n], res = 0;
    leftMax[0] = arr[0];
    for (int i = 1; i < n; ++i)
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i)
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    for (int i = 0; i < n; ++i)
        res += min(leftMax[i], rightMax[i]) - arr[i];
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
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n), for the two auxiliary arrays
*/
