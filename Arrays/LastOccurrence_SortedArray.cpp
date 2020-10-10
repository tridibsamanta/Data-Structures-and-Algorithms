/**
 * Title     : Find the last occurrence of an element in a sorted (non-decreasing) array
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findLastOccurrenceIndex(vector<int> &nums, int target) {

    int n = nums.size();

    int low = 0, high = n - 1, idx = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            idx = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return idx;
}

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        nums.emplace_back(element);
    }

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    int lastOccIdx = findLastOccurrenceIndex(nums, target);
    if (lastOccIdx == -1)
        cout << "Element not found !" << '\n';
    else
        cout << "Last occurrence index: " << lastOccIdx << '\n';

    return 0;
}

/*
 * Time Complexity  : O(log n)
 * Space Complexity : O(1)
*/
