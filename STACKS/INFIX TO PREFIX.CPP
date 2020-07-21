/* INFIX TO PREFIX */
/* only diff bn infix to postfix and infix to pefix is we need to reverse the input string and output string
first closing bracket will come therefore we will push it
n for opening we will pop bn ()
and if precedence is less then pop else for greater and equal push
*/
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
infixtoprefix(string exp)
{
	int l=exp.length();
	stack<char> s;
	string res="";
	for(int i=0;i<l;i++)
	{
		//if operand
		if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z' || exp[i]>='0' && exp[i]<='9')
		{
			res+=exp[i];
		}
		else if(exp[i]==')')  //as closing will come first in reverse string therefore it will be pushed
		{
			s.push(')');
		}
		else if(exp[i]=='(')  //when opening come pop everything bn()
		{
			while(s.empty()==false && s.top()!=')')
			{
				char c=s.top();
				s.pop();
				res+=c;
			}
			if(s.top()==')')
			{
				s.pop();
			}
		}
		else {
	  while(s.empty()==false && prec(exp[i])<prec(s.top()))  //here if prec is less than pop
		{
			char c=s.top();
			s.pop();
			res+=c;
			
		}
		s.push(exp[i]);  //else push into stack
	}
		
	}
	while(s.empty()==false)
	{
		char c=s.top();
		s.pop();
		res+=c;
	}
	reverse(res.begin(),res.end());  //reverse ans
	cout<<res<<"\n";
}
int main()
{
	string exp;
	cin>>exp;
	reverse(exp.begin(),exp.end());  //reverse infix
	infixtoprefix(exp);
	return 0;
}
