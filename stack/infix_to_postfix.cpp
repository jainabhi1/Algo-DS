#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
int pre(char c)
{
	if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
int main()
{
	string in="a+b*(c^d-e)^(f+g*h)-i";
	string post=""; ///abcd^e-fgh*+^*+i-
	stack<char> s;
	for(int i=0;i<in.length();i++)
	{
		if(in[i]>='a' && in[i] <='z' || in[i]>='A' && in[i] <= 'Z')
			post+=in[i];
		else
		{
			if(in[i] == '(')
				s.push(in[i]);
			else if(in[i] == ')')
			{
				while(s.top()!='(')
				{
					post+=s.top();
					s.pop();
				}
				s.pop();
			}
			else
			{
				while(!s.empty() && pre(s.top()) >= pre(in[i]) && s.top() != '(')
				{
					post+=s.top();
					s.pop();
				}

				s.push(in[i]);
			}
		}
	}
	while(!s.empty())
	{
		post+=s.top();
		s.pop();
	}
	cout<< post << endl;
}
