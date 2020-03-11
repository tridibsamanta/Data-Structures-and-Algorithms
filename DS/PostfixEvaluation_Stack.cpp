/*
Evaluation of Postfix Expression in C++.
Input Postfix Expression must be in a desired format.
Operands must be integers. Delimiters allowed in expression are space and ','.
Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/

/*
Check the expression from LEFT to RIGHT.
<operand> <operand> <operator>
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

//Function to evaluate Postfix exp and return result
int EvaluatePostfix(string expression);

//Function to perform an operation and return output
int PerformOperation(char operation, int operand1, int operand2);

//Function to verify whether a character is an operator or not
bool IsOperator(char C);

//Function to verify whether a character is a digit or not
bool IsNumericDigit(char C);

int main() {
    string expression;
    cout<<"Enter the expression : \n";
    getline(cin,expression);
    int result = EvaluatePostfix(expression);
    cout<<"Result = "<<result<<"\n";
}

int EvaluatePostfix(string expression) {
    stack<int> S;
    //Checking from left to right of the expression
    for(int i=0;i<expression.length();i++) {
        //If current character is a delimiter, move on to the next one !
        if(expression[i] == ' ' || expression[i] == ',')
            continue;
        //If current character is an operator
        else if(IsOperator(expression[i])) {
            //Pop two elements from the stack
            //Perform operation
            //Push back result into the stack
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            int result = PerformOperation(expression[i],operand1,operand2);
            S.push(result);
        }
        //If current character is a digit
        else if(IsNumericDigit(expression[i])) {
                //Keep incrementing 'i' as long as you get numeric digit (Multi-digit numbers)
                int operand = 0;
                while(i<expression.length() && IsNumericDigit(expression[i])) {
                    //Form the multi-digit number
                    //In C++ char stores ASCII value. For '0' it is 48
                    //Assume expression[i] = '2' (ASCII - 50), Hence 50-48=2
                    operand = (operand*10) + (expression[i] - '0');
                    i++;
                }
                //Push the operand into the stack
                S.push(operand);
                //Decrement 'i' so that we dont miss the non-numeric character
                i--;
        }
    }
    //Return result, which is the last element remaining in the stack
    return S.top();
}

bool IsNumericDigit(char C) {
    //Check for digits 0 to 9
    if(C >= '0' && C <='9')
        return true;
    return false;
}

bool IsOperator(char C) {
    //Check for the operators +,-,*,/
    if(C == '+' || C == '-' || C == '*' || C == '/')
        return true;
    return false;
}

int PerformOperation(char operation, int operand1, int operand2) {
    //Perform operator check and return the result accordingly
    if(operation == '+')
        return (operand1 + operand2);
    else if(operation == '-')
        return (operand1 - operand2);
    else if(operation == '*')
        return (operand1 * operand2);
    else if(operation == '/')
        return (operand1 / operand2);
    else
        cout<<"Unexpected Error !\n";
    return -1;
}
