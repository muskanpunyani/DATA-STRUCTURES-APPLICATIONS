/* INFIX TO POSTFIX */
#include<bits/stdc++.h>  
using namespace std;
int prec(char c)    //checking precedence
{
	if(c=='^')
	{
		return 3;
	}
	else if( c== '*' || c=='/')
          return 2;
	else if((c== '+')|| (c== '-'))
	{
		return 1;
	}
	
		return -1;
	
}
void infixtopostfix(string exp)
{
	stack<char> s;
	string final="";
	s.push('N');      //adding a char to determine empty stack,if expression contains N dont take it
	int l=exp.length();
	for(int i=0;i<l;i++)   //traverse the string
	{
		//if operand push it
		if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9'))
		{
			final+=exp[i];
		}
		else if(exp[i]=='(')
		{
			s.push('(');
		}
		// if ) then pop everything bn ()
		else if(exp[i]==')')
		{
			while(s.top()!='N' && s.top()!='(')
			{
				char c=s.top();
				s.pop();
				final+=c;
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else{
			while(s.top()!='N' && prec(exp[i])<=prec(s.top()))  //if precedence of operator is less or equal; pop everything
			{
				char c=s.top();
				s.pop();
				final+=c;
			}
			s.push(exp[i]);   //else push that
		}
	}
	while(s.top()!='N')   //output the stack
	{
		char c=s.top();
		s.pop();
		final+=c;
	}
	cout<<final<<endl;
}
int main()
{
	string exp;
	cin>>exp;
	infixtopostfix(exp);
	return 0;
	
}
