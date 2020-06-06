/**
 * Title     : Longest Palindromic Substring (Method 2)
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

void findLongestPalindromicSubstring(string s) {

    int n = s.length();

    int startIdx = 0, maxLen = 1, low, high;

    for (int i = 1; i < n; ++i) {

        low = i - 1;
        high = i;
        while ((low >= 0 && high < n) && (s[low] == s[high])) {

            if (high - low + 1 > maxLen) {
                maxLen = high - low + 1;
                startIdx = low;
            }
            --low;
            ++high;
        }

        low = i - 1;
        high = i + 1;
        while ((low >= 0 && high < n) && (s[low] == s[high])) {

            if (high - low + 1 > maxLen) {
                maxLen = high - low + 1;
                startIdx = low;
            }
            --low;
            ++high;
        }
    }

    cout << "Longest Palindromic Substring is : ";
    for (int i = startIdx; i < startIdx + maxLen; ++i)
        cout << s[i];
    cout << '\n';
    cout << "Length of the Longest Palindromic Substring is : ";
    cout << maxLen << '\n';
}

int main() {

    string s;
    cout << "Enter the string : ";
    cin >> s;

    findLongestPalindromicSubstring(s);

    return 0;
}

/*
 ~ Time Complexity   : O(n^2)
 ~ Space Complexity  : O(1)
*/
