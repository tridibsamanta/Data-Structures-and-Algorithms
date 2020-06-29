/**
 * Title     : Longest Substring Without Repeating Characters
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

#define ALL_CHARS 256

int findLength(string s) {

   vector<int> lastIndex(ALL_CHARS, -1);
   int maxLength = 0, start = 0;

   for (int j = 0; j < s.size(); ++j) {
        start = max(start, lastIndex[s[j]] + 1);
        maxLength = max(maxLength, j - start + 1);
        lastIndex[s[j]] = j;
   }
   return maxLength;
}

int main() {

    string s;
    cout << "Enter the string : ";
    cin >> s;

    int res = findLength(s);
    cout << "Length of the longest substr without repeating chars = " << res;

    return 0;
}

/*
 ~ Time Complexity  : O(n)
    where 'n' is length of the string
 ~ Auxiliary Space  : O(m)
    where 'm' is total number of permissible characters in the string
*/
