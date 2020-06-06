/**
 * Title     : Longest Palindromic Substring
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

void findLongestPalindromicSubstring(string s) {

    int n = s.length();

    bool dp[n][n];

    memset(dp, 0, sizeof(dp));

    int maxLen = 1, startIdx = 0;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            startIdx = i;
            maxLen = 2;
        }
    }

    // Check for substring of length greater than 2
    for (int k = 3; k <= n; ++k) {

        for(int i = 0; i <= n - k; ++i) {

            int j = i + k - 1;

            if (s[i] == s[j] && dp[i + 1][j - 1]) {

                dp[i][j] = true;

                if (k > maxLen) {
                    maxLen = k;
                    startIdx = i;
                }
            }
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
 ~ Space Complexity  : O(n^2)
*/
