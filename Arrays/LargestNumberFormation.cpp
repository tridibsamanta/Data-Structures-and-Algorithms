/**
 * Title     : Arrange array elements to form the largest number
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

bool compareLargest(string s1, string s2) {
    return (s1 + s2) > (s2 + s1);
}

string findLargestNumber(vector<int> nums) {

    vector<string> arr;
    for (auto n : nums)
        arr.push_back(to_string(n));

    sort(arr.begin(), arr.end(), compareLargest);

    string largestNumber;
    for (auto s : arr)
        largestNumber += s;

    return (largestNumber[0] == '0') ? "0" : largestNumber;
}

int main() {

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> nums;

    cout << "Enter " << n << " elements : ";
    int element;
    for (int i = 0; i < n; ++i) {
        cin >> element;
        nums.push_back(element);
    }

    string res = findLargestNumber(nums);
    cout << "Largest number : " << res << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(nlogn)
 ~ Space Complexity  : O(n)
*/
