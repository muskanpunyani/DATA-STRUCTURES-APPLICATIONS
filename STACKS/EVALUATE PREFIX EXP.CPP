#include<bits/stdc++.h>
using namespace std;
void EvaluatePostfix(string exp)
{
	int l=exp.length();
	stack<int>s;   //make int stack as there will be only numbers
	for(int i=0;i<l;i++)
	{
		if(isdigit(exp[i]))    //isdigit is a function to check digit
		//if digit push it into stack
		{
			s.push(exp[i]-'0');
		}
		else{
			//if operator then push two val from stack and perform operation on it.
			int op1=s.top();
			s.pop();
			int op2=s.top();
			s.pop();
			switch(exp[i])
			{
				case'+':
					s.push(op1+op2);
					break;
				case'-':
					s.push(op1-op2);
					break;
				case'*':
					s.push(op1*op2);
					break;
				case'/':
					s.push(op1/op2);
					break;
			}
			
		}
		
	}
	cout<<s.top()<<endl;  // the top element is the result
}
int main()
{
	string exp;  //expression will be only of numbers as we need to evaluate it
	cin>>exp;
	reverse(exp.begin(),exp.end());   //REVERSE
	EvaluatePostfix(exp);
}
