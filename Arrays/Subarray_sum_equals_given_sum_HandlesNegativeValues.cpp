/**
 * Title     : Subarray sum equals given sum (Handles negative values)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

void SubArraySum(int arr[], int size, int sum) {

    unordered_map<int, int> hm;

    int curr_sum = 0;

    for(int i = 0; i < size; ++i) {

        curr_sum += arr[i];

        // If current sum is equal to sum, subarray has starting index of 0 and end index is the current index
        if (curr_sum == sum) {
            cout << "Sum found between index 0 and " << i << "\n";
            return;
        }

        // If the difference of current sum and desired sum is present in the map,
        // Then our required sum subarray must start from the index next to the difference index, upto the current index
        if (hm.find(curr_sum - sum) != hm.end()) {
            cout << "Sum found between index " << hm[curr_sum - sum] + 1 << " and " << i << "\n";
            return;
        }

        // Else store the current index as the value for the current sum in the map
        hm[curr_sum] = i;
    }

    // If sum of any subarray does not match with our desired sum then subarray does not exists
    cout << "No subarray containing the desired sum exists !\n";
}

int main() {
	int n;
	cout << "Enter the size of the array = ";
	cin >> n;

	int arr[n];
	cout << "Enter the " << n << " array elements = ";
	for(int i = 0; i < n; ++i)
		cin >> arr[i];

	int sum;
	cout << "Enter the sum = ";
	cin >> sum;

	SubArraySum(arr, n, sum);

	return 0;
}

/*
 * Time Complexity  : O(n)
 * Space Complexity : O(n) (As a HashMap is needed, this takes a linear space)
*/
