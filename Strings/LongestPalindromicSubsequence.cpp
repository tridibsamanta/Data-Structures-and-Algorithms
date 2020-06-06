/**
 * Title     : Length of Longest Palindromic Subsequence (Recursive Approach)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

int findLPS(string s, int startIdx, int endIdx) {

    // A single character is always a palindrome
    if (startIdx == endIdx)
        return 1;

    // A sequence of two equal characters are always palindrome
    if (s[startIdx] == s[endIdx] && endIdx == startIdx + 1)
        return 2;

    // For sequences greater than 2, we check first and last character
    // and also check if the string in between first and last character is palindrome or not
    if (s[startIdx] == s[endIdx])
        return findLPS(s, startIdx + 1, endIdx - 1) + 2;

    return max(findLPS(s, startIdx, endIdx - 1), findLPS(s, startIdx + 1, endIdx));
}

int main() {

    string s;
    cout << "Enter the string : ";
    cin >> s;

    int len = s.length();

    int res = findLPS(s, 0, len - 1);
    cout << "Length of the Longest Palindromic Subsequence is : " << res << '\n';

    return 0;
}

/*
 ~ Time Complexity   : O(n^2)
 ~ Space Complexity  : O(n^2)
*/
