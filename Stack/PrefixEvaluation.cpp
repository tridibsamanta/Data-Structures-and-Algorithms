/**
 * Title     : Prefix Evaluation
 * Author    : Tridib Samanta
 **/

#include<iostream>
#include<stack>
using namespace std;

int evaluatePrefix(string exp) {
    stack<int> S;
    for(int i = exp.length() - 1; i >= 0 ; --i) {
        if (exp[i] == ' ')
            continue;
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int result = 0;
            int operand1 = S.top(); S.pop();
            int operand2 = S.top(); S.pop();
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
            int rev_operand = 0, operand = 0;
            while(i >= 0 && (exp[i] >= '0' && exp[i] <= '9')) {
                rev_operand = (rev_operand * 10) + (exp[i] - '0');
                --i;
            }
            ++i;
            while (rev_operand != 0) {
                int rem = rev_operand % 10;
                operand = (operand * 10) + rem;
                rev_operand /= 10;
            }
            S.push(operand);
        }
    }
    return S.top();
}

int main() {
    string exp;
    cout << "Enter the prefix expression : ";
    getline(cin, exp);
    int res = evaluatePrefix(exp);
    cout << "Result = " << res << '\n';
    return 0;
}

// N.B. : The input expression values must be separated by blank spaces. This code takes care of multi-digit numbers too.

/*
 ~ Time Complexity   : O(n), since we are scanning the input only once.
 ~ Space Complexity  : O(n), for the stack.
*/
