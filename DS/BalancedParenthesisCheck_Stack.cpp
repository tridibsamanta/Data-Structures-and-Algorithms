/*
  C++ Program to check for balanced parentheses in an expression using stack.
  Given an expression as string comprising of opening and closing characters
  of parentheses - (), curly braces - {} and square brackets - [], we need to
  check whether symbols are balanced or not.
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool CheckPair(char opening, char closing) {
    if(opening == '(' && closing == ')')
        return true;
    else if(opening == '{' && closing == '}')
        return true;
    else if(opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool CheckBalancedParenthesis(string exp) {
    stack<char> S;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            S.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(S.empty() || !CheckPair(S.top(),exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return (S.empty()?true:false);
}

int main() {
    string exp;
    cout<<"Enter the expression : ";
    cin>>exp;
    if(CheckBalancedParenthesis(exp))
        cout<<"Parenthesis are balanced !"<<endl;
    else
        cout<<"Parenthesis are not balanced !"<<endl;
    return 0;
}
