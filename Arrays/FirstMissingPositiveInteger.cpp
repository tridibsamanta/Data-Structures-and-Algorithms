/**
 * Title     : Find the first missing positive integer in an unsorted array
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while ((nums[i] >= 1 && nums[i] <= n) && (nums[i] != nums[nums[i] - 1]))
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

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

    Solution ob;

    int res = ob.firstMissingPositive(nums);
    cout << "First missing positive integer is: " << res << ' ';

    return 0;
}

/*
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
*/
