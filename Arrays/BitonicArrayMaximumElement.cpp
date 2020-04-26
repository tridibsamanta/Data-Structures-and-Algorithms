/**
 * Title     : Bitonic array maximum element
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findMaxBitonic(int arr[], int low, int high) {

    // If the array has 1 element
    if (low == high)
        return arr[low];

    // If the array has 2 elements
    if (high == low + 1) {
        if (arr[low] > arr[high])
            return arr[low];
        else
            return arr[high];
    }

    // If the array has more than 2 elements
    int mid = low + high / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return arr[mid];
    if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
        return findMaxBitonic(arr, low, mid - 1);
    else
        return findMaxBitonic(arr, mid + 1, high);
}

int main() {

    cout << "Enter the number of elements in the bitonic array - ";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements - ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int max_element = findMaxBitonic(arr, 0, n-1);
    cout << "Maximum element of the bitonic array is = " << max_element << "\n";

    return 0;
}

/*
 * Time Complexity  : O(log n)
 * Auxiliary Space  : O(1)
*/
