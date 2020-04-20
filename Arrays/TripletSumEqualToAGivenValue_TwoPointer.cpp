/**
 * Title     : Triplet sum that is equal to a given value (Two-pointer technique)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

bool FindTriplet(int arr[], int size, int sum) {

    // Sort the array elements
    sort(arr, arr + size);

    int l, r; // Declare the left and the right pointer

    for(int i = 0; i < size - 2; ++i) {

        l = i + 1; // Setting left pointer
        r = size - 1; // Setting the right pointer

        // Continue loop as long as left pointer lies behind right pointer
        while (l < r) {
            // Triplet has value equal to sum
            if (arr[i] + arr[l] + arr[r] == sum) {
                cout << "Triplet elements with sum " << sum << " are " << arr[i] << ", " << arr[l] << " and " << arr[r] << "\n";
                return true;
            }
            // Triplet has value less than sum
            else if (arr[i] + arr[l] + arr[r] < sum)
                ++l;
            // Triplet has value greater than sum
            else
                --r;
        }
    }
    // Indicates no triplet with the given sum exists
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

    int sum;
    cout << "Enter the sum of the triplet = ";
    cin >> sum;

    if (!FindTriplet(arr, n, sum))
        cout << "No triplet having sum " << sum << " exists !\n";

    return 0;
}

/*
 * Time Complexity  : O(n^2)
 * Space Complexity : O(1)
*/
