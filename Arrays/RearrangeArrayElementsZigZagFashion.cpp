/**
 * Title     : Rearrange array elements in a Zig-Zag fashion
                (A[0] < A[1] > A[2] < A[3] > A[4] < A[5])
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void arrangeZigZag(vector<int>& nums) {

        bool relation = true; // true = '<', false = '>'

        for (int i = 0; i < nums.size() - 1; ++i) {

            if (relation) {
                // If nums[i] < nums[i+1] is not satisfied
                if (nums[i] > nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
            else {
                // If nums[i] > nums[i+1] is not satisfied
                if (nums[i] < nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }
            // Change flag for next iteration
            relation = !relation;
        }
    }
};

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    Solution ob;

    ob.arrangeZigZag(nums);
    cout << "Zig-Zag array: ";
    for (auto i : nums)
        cout << i << ' ';

    return 0;
}

/*
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
*/
