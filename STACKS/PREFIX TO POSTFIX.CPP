/*** Algorithm for Prefix to Postfix:

    Read the Prefix expression in reverse order (from right to left)
    If the symbol is an operand, then push it onto the Stack
    If the symbol is an operator, then pop two operands from the Stack
    Create a string by concatenating the two operands and the operator after them.
    string = operand1 + operand2 + operator
    And push the resultant string back to Stack
    Repeat the above steps until end of Prefix expression.
***/

#include<bits/stdc++.h>
using namespace std;
bool isop(char x)   //check if operotor
{
	switch(x){
		case'*':
			return true;
		case'+':
			return true;
		case'/':
			return true;
		case'-':
		  return true;
	}
	return false;
		
}
void convertprefix(string exp)   //convert to postfix
{
	stack<string> s;
	int l=exp.length();
	for(int i=l-1;i>=0;i--)   //traverse prefix in reverse order
	{
		
		 if(isop(exp[i]))  //if operator pop two operands keep the operator bn them and push
		{
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();
			string res= op1+ op2 + exp[i] ;   //postfix: op1+op2+operator
			s.push(res);
		}
		else{
				s.push(string(1,exp[i]));    //else push everything
		}
	}
	cout<<s.top()<<"\n";  //ans will be at the top
}
int main()
{
	string exp;
	cin>>exp;  //take prefix exp

	convertprefix(exp);
}
