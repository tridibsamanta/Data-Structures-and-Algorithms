/**
 * Title     : Check for balanced parentheses
 * Author    : Tridib Samanta
 **/

#include<iostream>
#include<stack>
using namespace std;

bool checkPair(char open, char close) {
    if (open == '(' && close == ')')
        return true;
    else if (open == '{' && close == '}')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else
        return false;
}

bool checkBalancedParenthesis(string exp) {
    stack<char> S;
    for (int i = 0; i < exp.length(); ++i) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (S.empty() || !checkPair(S.top(), exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return (S.empty() ? true : false);
}

int main() {

    string exp;
    cout << "Enter the expression : ";
    cin >> exp;

    if (checkBalancedParenthesis(exp))
        cout << "Balanced";
    else
        cout << "Not balanced";

    return 0;
}

/*
 ~ Time Complexity   : O(n), since we are scanning the input only once.
 ~ Space Complexity  : O(n), for the stack.
*/
