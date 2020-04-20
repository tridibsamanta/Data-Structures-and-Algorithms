/**
 * Title     : Triplet where sum of two elements equals third element (Using Two-pointer technique)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

bool FindTriplet(int arr[], int size) {

    sort(arr, arr + size);

    int l, r;

    for (int i = size - 1; i > 1; --i) {
        l = 0;
        r = i - 1;
        while (l < r) {
            if (arr[l] + arr[r] == arr[i]) {
                cout << "Triplet is = {" << arr[l] << ", " << arr[r] << ", " << arr[i] << "} \n";
                return true;
            }
            else if (arr[l] + arr[r] < arr[i])
                ++l;
            else
                --r;
        }
    }
    return false;
}

int main() {

    int n;
    cout << "Enter the number of array elements = ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements = ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    if (!FindTriplet(arr, n))
        cout << "No such triplet exists !\n";

    return 0;
}

/*
 * Time Complexity  : O(n^2)
 * Space Complexity : O(1)
*/
