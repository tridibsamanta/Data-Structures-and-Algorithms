/**
 * Title     : Find the number of times a sorted array is rotated
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int> &nums) {

    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {

        if (nums[low] <= nums[high])
            return low;

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n, prev = (mid - 1 + n) % n;

        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            return mid;
        else if (nums[low] <= nums[mid])
            low = mid + 1;
        else if (nums[mid] <= nums[high])
            high = mid - 1;
    }
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

    int count = findRotationCount(nums);
    cout << "Sorted array is rotated " << count << " times";

    return 0;
}

/*
 * Time Complexity  : O(log n)
 * Space Complexity : O(1)
*/
