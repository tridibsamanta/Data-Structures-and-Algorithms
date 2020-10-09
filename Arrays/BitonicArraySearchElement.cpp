/**
 * Title     : Search for an element in a bitonic array
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int getPeakElementUtil(vector<int> &nums, int low, int high) {

    if (low == high)
        return low;

    if (high == low + 1) {
        if (nums[high] > nums[low])
            return high;
        else
            return low;
    }

    int mid = low + (high - low) / 2;

    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        return mid;

    if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
        return getPeakElementUtil(nums, mid + 1, high);
    else
        return getPeakElementUtil(nums, low, mid - 1);
}

int ascendingBinarySearch(vector<int> &nums, int low, int high, int key) {

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == key)
            return mid;

        if (nums[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int descendingBinarySearch(vector<int> &nums, int low, int high, int key) {

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == key)
            return mid;

        if (nums[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int searchBitonic(vector<int> &nums, int key) {

    int n = nums.size();

    int maxElementIdx = getPeakElementUtil(nums, 0, n - 1);

    if (nums[maxElementIdx] == key)
        return maxElementIdx;
    else if (key > nums[maxElementIdx])
        return -1;
    else {
        int idx = ascendingBinarySearch(nums, 0, maxElementIdx - 1, key);
        if (idx != -1)
            return idx;

        return descendingBinarySearch(nums, maxElementIdx, n - 1, key);
    }
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

    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;

    int index = searchBitonic(nums, key);
    if (index == -1)
        cout << "Element not found !" << '\n';
    else
        cout << "Element found at index: " << index << '\n';

    return 0;
}

/*
 * Time Complexity  : O(log n)
 * Space Complexity : O(1)
*/
