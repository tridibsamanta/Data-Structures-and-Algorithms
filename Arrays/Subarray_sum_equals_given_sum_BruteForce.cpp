/**
 * Title	: Subarray sum equals given sum (Brute Force Approach)
 * Author   : Tridib Samanta
 **/

#include<iostream>
using namespace std;

int SubArraySum(int arr[], int size, int sum) {
	int curr_sum = 0;

	// Loop that denotes the starting index of traversal
	for (int i = 0; i < size; ++i) {
		curr_sum  = arr[i];
		// Loop that fetches all sub arrays from the current starting index
		for (int j = i+1; j <= size; ++j) {
			// If current sum is equal with desired sum, print the indices and return to main function
			if (curr_sum == sum) {
				cout << "Sum found between index " << i << " and " << j-1 << "\n"; //According to 0 indexing of array
				return 1;
			}
			// If current sum exceeds the desired sum, no need to add elements further to the current subarray
			// If no elements left to be added to the current subarray, break from the loop
			if (curr_sum > sum || j == size)
				break;
			// If current sum is less than desired sum, add an element to the existing current sum
			curr_sum += arr[j];
		}
	}
	// If sum of any subarray does not match with our desired sum then subarray does not exists
	cout << "No subarray containing the given sum exists !\n";
	return 0;
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
 * Time Complexity  : O(n^2)
 * Space Complexity : O(1)
*/
