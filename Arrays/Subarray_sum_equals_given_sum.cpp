/**
 * Title     : Subarray sum equals given sum
 * Author    : Tridib Samanta
 **/

#include<iostream>
using namespace std;

int SubArraySum(int arr[], int size, int sum) {
	
	int curr_sum = arr[0], start = 0;
	
	//Loop that traverses the array 
	for (int i = 1; i <= size; ++i) {
		// If current sum exceeds the desired sum we need to substract the elements from the start of the current subarray
		// Also increment the start index by 1 on every substraction 
		while (curr_sum > sum && start < i-1) {
			curr_sum -= arr[start];
			++start;
		}
		// If current sum is equal with desired sum, print the indices and return to main function
		if (curr_sum == sum) {
			cout << "Sum found between index " << start << " and " << i-1 << "\n";
			return 1;
		}
		// If index is less than size of the array, add an element to the existing current sum
		if (i < size)
			curr_sum += arr[i];
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
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
*/
