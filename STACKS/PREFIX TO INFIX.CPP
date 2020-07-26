/***Algorithm for Prefix to Infix:

    1)Read the Prefix expression in reverse order (from right to left)
    2)If the symbol is an operand, then push it onto the Stack
    3)If the symbol is an operator, then pop two operands from the Stack
    4)Create a string by concatenating the two operands and the operator between them.
    5)string = (operand1 + operator + operand2)
    6)And push the resultant string back to Stack
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
void convertprefix(string exp)
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
			string res="("+ op1+ exp[i] + op2 +")";  
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
	cin>>exp;  //take prefix exp

	convertprefix(exp);
}
