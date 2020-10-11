/**
 * Title     : Search for an element in a rotated sorted array
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int> &nums, int target) {

    int low = 0, high = nums.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // If element at index 'mid' is equal to target
        if (nums[mid] == target)
            return mid;

        // If right segment is sorted
        if (nums[mid] <= nums[high]) {

            // If target is probably in the right sorted segment
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            // Else target is probably in the left unsorted segment
            else
                high = mid - 1;
        }
        // Else left segment is sorted
        else if (nums[low] <= nums[mid]) {

            // If target is probably in the left sorted segment
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            // Else target is probably in the right unsorted segment
            else
                low = mid + 1;
        }
    }
    // target is not present in the array
    return -1;
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
    cout << "Enter the element to be searched: ";
    cin >> target;

    int targetIndex = findElement(nums, target);

    if (targetIndex == -1)
        cout << target << " is not present in the array" << '\n';
    else
        cout << target << " is present at index " << targetIndex << '\n';

    return 0;
}

/*
 * Time Complexity  : O(log n)
 * Space Complexity : O(1)
*/
