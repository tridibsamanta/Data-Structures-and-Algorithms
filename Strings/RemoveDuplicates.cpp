/**
 * Title     : Remove duplicates from a string
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

/* Approach 1 : (Brute-force) */
/*
void removeDuplicates(string s) {
   int pos = 0;
   for (int i = 0; i < s.length(); ++i) {
        int j;
        for (j = 0; j < i; ++j) {
            if (s[i] == s[j])
                break;
        }
        if (j == i)
            s[pos++] = s[i];
   }
   s[pos] = '\0';
   for (int i = 0; s[i]; ++i)
        cout << s[i];
}
*/
/*
 ~ Time Complexity  : O(n*n)
 ~ Space Complexity : O(1)
*/

/* Approach 2 : (Using set of C++ STL) */
/*
void removeDuplicates(string s) {
    set<char> str(begin(s), end(s));
    set<char> :: iterator itr;
    for (itr = str.begin(); itr != str.end(); ++itr)
        cout << *itr;
}
*/
/*
 ~ Time Complexity  : O(nlogn)
 ~ Space Complexity : O(n)
*/

/* Approach 3 : (Using unordered_map of C++ STL) */

void removeDuplicates(string s) {
    unordered_map<char, bool> check;
    int pos = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (check[s[i]] == false) {
            s[pos++] = s[i];
            check[s[i]] = true;
        }
    }
    s[pos] = '\0';
    for (int i = 0; s[i]; ++i)
        cout << s[i];
}

/*
 ~ Time Complexity  : O(n)
 ~ Space Complexity : O(n)
*/

int main() {

    string s;
    cout << "Enter a string : ";
    cin >> s;

    cout << "After removing duplicates string is : ";
    removeDuplicates(s);
    cout << '\n';

    return 0;
}
