/**
 * Title     : Search for a pattern in a text (Knuth-Morris-Pratt Algorithm)
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern) {

    int n = pattern.length();

    vector<int> lps(n, 0); // lps[0] is always 0

    int j = 0, i = 1;

    while(i < n) {

        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            ++j;
            ++i;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                lps[i] = 0;
                ++i;
            }
        }
    }

    return lps;
}

vector<int> patternSearch(string text, string pattern) {

    vector<int> lps = computeLPS(pattern);

    int textLen = text.length(), patternLen = pattern.length();
    int i = 0, j = 0;

    vector<int> index;

    while (i < textLen && j < patternLen) {

        if (text[i] == pattern[j]) {
            ++i;
            ++j;
        }

        if (j == patternLen) {
            index.emplace_back(i - j);
            j = lps[j - 1];
        }

        else if (i < textLen && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }

    return index;
}

int main() {

    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    vector<int> index;

    index = patternSearch(text, pattern);

    if (!index.size()) {
        cout << "Pattern not found in text";
    }
    else {
        cout << "Pattern found at index: ";
        for (auto i : index)
            cout << i << ' ';
    }

    return 0;
}

/*
 ~ Time Complexity  : O(n + m)
 ~ Space Complexity : O(m)
   where 'n' is the text length and 'm' is the pattern length
*/
