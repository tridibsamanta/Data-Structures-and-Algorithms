/*
Evaluation of Prefix Expression in C++.
Input Prefix Expression must be in a desired format.
Operands must be integers. Delimiters allowed in expression are ' ' (space) and ','.
Only '+'  ,  '-'  , '*' and '/'  operators are expected.
*/

/*
Check the expression from RIGHT to LEFT.
<operand> <operand> <operator>
*/

#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int EvaluatePrefix(string expression);

bool IsNumericDigit(char C);

bool IsOperator(char C);

int PerformOperation(char operation, int operand1, int operand2);

int main()
{
	string expression;
	cout<<"Enter the expression : \n";
	getline(cin,expression);
	int result = EvaluatePrefix(expression);
	cout<<"Result = "<<result<<"\n";
}

int EvaluatePrefix(string expression)
{
	stack<int> S;
	for(int i=expression.length()-1;i>=0;i--)
	{
		if(expression[i] == ' ' || expression[i] == ',')
			continue;
		else if(IsOperator(expression[i]))
			{
				int operand1 = S.top(); S.pop();
				int operand2 = S.top(); S.pop();
				int result = PerformOperation(expression[i],operand1,operand2);
				S.push(result);
			}
		else if(IsNumericDigit(expression[i]))
			{
				int rev_operand = 0, operand = 0;
				while(i>=0 && IsNumericDigit(expression[i]))
				{
					rev_operand = (rev_operand*10) + (expression[i]-'0');
					i--;
				}
				i++;
				while(rev_operand != 0)
                {
                    int rem = rev_operand % 10;
                    operand = (operand * 10) + rem;
                    rev_operand /= 10;
                }
				S.push(operand);
			}
	}
	return S.top();
}

bool IsNumericDigit(char C)
{
	if(C >= '0' && C <= '9')
		return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+')
		return (operand1 + operand2);
	else if(operation == '-')
		return (operand1 - operand2);
	else if(operation == '*')
		return (operand1 * operand2);
	else if(operation == '/')
		return (operand1 / operand2);
	else
		cout<<"Unexpected Error ! \n";
	return -1;
}
