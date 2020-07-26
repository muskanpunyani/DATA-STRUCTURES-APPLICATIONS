/***
Algorithm for Postfix to Prefix:

        Read the Postfix expression from left to right
        If the symbol is an operand, then push it onto the Stack
        If the symbol is an operator, then pop two operands from the Stack
        Create a string by concatenating the two operands and the operator before them.
        string = operator + operand2 + operand1
        And push the resultant string back to Stack
        Repeat the above steps until end of Prefix expression
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
void convertpostfix(string exp)
{
	stack<string> s;
	int l=exp.length();
	for(int i=0;i<l;i++)   //traverse prefix in reverse order
	{
		
		 if(isop(exp[i]))  //if operator pop two operands 
		{
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();
			string res=exp[i]+op2+op1;    //operator+operand2+operand1
			s.push(res);
		}
		else{
				s.push(string(1,exp[i]));    //else push everything
				//need to convert the char into string , string(1,char)  //conversion
		}
	}
	cout<<s.top()<<"\n";  //ans will be at the top
}
int main()
{
	string exp;
	cin>>exp;  //take  exp

	convertpostfix(exp);
}
