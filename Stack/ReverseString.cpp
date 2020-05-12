/**
 * Title     : Reverse a string using stack
 * Author    : Tridib Samanta
 **/

#include<bits/stdc++.h>
using namespace std;

string reverseString(string str) {

    stack<char> S;
    string rev = "";

    for (int i = 0; i < str.length(); ++i)
        S.push(str[i]);

    while (!S.empty()) {
        rev += S.top();
        S.pop();
    }

    return rev;
}

int main() {
    string str;
    cout << "Enter the string   : ";
    cin >> str;
    int len = str.length();
    string res = reverseString(str);
    cout << "Reversed string    : " << res << '\n';
    return 0;
}

/*
 ~ Time Complexity   : O(n), since we are scanning the input string only once.
 ~ Space Complexity  : O(n), for the stack.
*/
