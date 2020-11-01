/**
 * Title     : Search for a pattern in a text (Brute-force)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

int patternSearch(string text, string pattern) {

    int m = pattern.length();
    int n = text.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

int main() {

    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int index = patternSearch(text, pattern);

    if (index == -1)
        cout << "Pattern not found in text";
    else
        cout << "Pattern starts in text from index " << index << '\n';

    return 0;
}

/*
 ~ Time Complexity  : O(n*m)
    where 'n' is length of the text and 'm' is the length of the pattern
 ~ Space Complexity : O(1)
*/
