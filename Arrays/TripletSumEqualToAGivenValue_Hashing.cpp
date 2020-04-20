/**
 * Title     : Triplet sum that is equal to a given value (Hashing based)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

bool FindTriplet(int arr[], int size, int sum) {

    for(int i = 0; i < size - 2; ++i) {

        unordered_set<int> hs;
        int curr_sum = sum - arr[i]; // Current sum has the value of the other two elements if triplet exists

        for(int j = i + 1; j < size; ++j) {
                // Basically we again subtract another element from current sum and hence search for the third element in the set
                if (hs.find(curr_sum - arr[j]) != hs.end()) {
                    cout << "Triplet elements with sum " << sum << " are " << arr[i] << ", " << arr[j] << " and " << curr_sum - arr[j] << "\n";
                    return true;
                }

            hs.insert(arr[j]);
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
 * Space Complexity : O(n) // Space for the storing the set
*/
