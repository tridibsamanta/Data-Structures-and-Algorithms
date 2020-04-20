/**
 * Title     : Triplet sum that is equal to a given value (Brute-Force)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

bool FindTriplet(int arr[], int size, int sum) {

    for(int i = 0; i < size - 2; ++i) {
        for(int j = i + 1; j < size - 1; ++j) {
            for(int k = j + 1; k < size; ++k) {
                int curr_sum = arr[i] + arr[j] + arr[k];
                if(curr_sum == sum) {
                    cout << "Triplet elements with sum " << sum << " are " << arr[i] << ", " << arr[j] << " and " << arr[k] << "\n";
                    return true;
                }
            }
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
 * Time Complexity  : O(n^3)
 * Space Complexity : O(1)
*/
