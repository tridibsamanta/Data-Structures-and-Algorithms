/**
 * Title     : Infix Evaluation
 * Author    : Tridib Samanta
 **/

#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '*'||op == '/')
        return 2;
    if(op == '+'||op == '-')
        return 1;
    return -1;
}

int operation(int a, int b, char op) {
    switch(op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

int evaluateInfix(string exp){
    stack <int> opnd;
    stack <char> optr;
    for(int i = 0; i < exp.length(); ++i) {
        if(exp[i] == ' ')
            continue;
        else if(exp[i] == '(')
            optr.push(exp[i]);
        else if(isdigit(exp[i])) {
            int operand = 0;
            while(i < exp.length() && isdigit(exp[i])) {
                operand = (operand * 10) + (exp[i] - '0');
                ++i;
            }
            opnd.push(operand);
        }
        else if(exp[i] == ')') {
            while(!optr.empty() && optr.top() != '(') {
                int operand2 = opnd.top(); opnd.pop();
                int operand1 = opnd.top(); opnd.pop();
                char op = optr.top(); optr.pop();
                opnd.push(operation(operand1, operand2, op));
            }
            if(!optr.empty())
               optr.pop();
        }
        else {
            while(!optr.empty() && precedence(optr.top()) >= precedence(exp[i])){
                int operand2 = opnd.top(); opnd.pop();
                int operand1 = opnd.top(); opnd.pop();
                char op = optr.top(); optr.pop();
                opnd.push(operation(operand1, operand2, op));
            }
            optr.push(exp[i]);
        }
    }
    while(!optr.empty()){
        int operand2 = opnd.top(); opnd.pop();
        int operand1 = opnd.top(); opnd.pop();
        char op = optr.top(); optr.pop();
        opnd.push(operation(operand1, operand2, op));
    }
    return opnd.top();
}

int main() {
    string exp;
    cout << "Enter the infix expression : ";
    getline(cin, exp);
    int res = evaluateInfix(exp);
    cout << "Result = " << res << '\n';
    return 0;
}

// N.B. : The input expression values must be separated by blank spaces. This code takes care of multi-digit numbers too.

/*
 ~ Time Complexity   : O(n), since we are scanning the input only once.
 ~ Space Complexity  : O(n), for the operand stack and the operator stack.
*/
