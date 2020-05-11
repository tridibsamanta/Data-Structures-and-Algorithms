/**
 * Title     : Postfix Evaluation
 * Author    : Tridib Samanta
 **/

#include<iostream>
#include<stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> S;
    for(int i = 0; i < exp.length(); ++i) {
        if (exp[i] == ' ')
            continue;
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int result = 0;
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            if (exp[i] == '+')
                result = operand1 + operand2;
            else if (exp[i] == '-')
                result = operand1 - operand2;
            else if (exp[i] == '*')
                result = operand1 * operand2;
            else
                result = operand1 / operand2;
            S.push(result);
        }
        else if (exp[i] >= '0' && exp[i] <= '9') {
            int operand = 0;
            while(i < exp.length() && (exp[i] >= '0' && exp[i] <= '9')) {
                operand = (operand * 10) + (exp[i] - '0');
                ++i;
            }
            S.push(operand);
            --i;
        }
    }
    return S.top();
}

int main() {
    string exp;
    cout << "Enter the postfix expression : ";
    getline(cin, exp);
    int res = evaluatePostfix(exp);
    cout << "Result = " << res << '\n';
    return 0;
}

// N.B. : The input expression values must be separated by blank spaces. This code takes care of multi-digit numbers too.

/*
 ~ Time Complexity   : O(n), since we are scanning the input only once.
 ~ Space Complexity  : O(n), for the stack.
*/
