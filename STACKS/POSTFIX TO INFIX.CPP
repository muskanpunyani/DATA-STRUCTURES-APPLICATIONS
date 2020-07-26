/***Algorithm for POSTFIX to Infix:

    1)Read the Postfix expression 
    2)If the symbol is an operand, then push it onto the Stack
    3)If the symbol is an operator, then pop two operands from the Stack
    4)Create a string by concatenating the two operands and the operator between them.
    5)string = (operand2 + operator + operand1)
    6)And push the resultant string back to Stack
    Repeat the above steps until end of Prefix expression. 
    
    
    same as prefix o infix just dont reverse the input string and the exp should be op2+op1
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
		
		 if(isop(exp[i]))  //if operator pop two operands keep the operator bn them and push
		{
			string op1=s.top();
			s.pop();
			string op2=s.top();
			s.pop();
			string res="("+ op2+ exp[i] + op1 +")";  
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
