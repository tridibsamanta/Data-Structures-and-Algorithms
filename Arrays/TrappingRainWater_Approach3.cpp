/**
 * Title     : Trapping Rain Water (Using two pointers)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findTrappedWater(int arr[], int n) {
    if (n == 0 || n == 1)
        return 0;
    int leftPtr = 0, rightPtr = n - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;
    while (leftPtr < rightPtr) {
        if (arr[leftPtr] < arr[rightPtr]) {
            if (arr[leftPtr] > leftMax)
                leftMax = arr[leftPtr];
            else
                res += leftMax - arr[leftPtr];
            ++leftPtr;
        }
        else {
            if (arr[rightPtr] > rightMax)
                rightMax = arr[rightPtr];
            else
                res += rightMax - arr[rightPtr];
            --rightPtr;
        }
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
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(1)
*/
