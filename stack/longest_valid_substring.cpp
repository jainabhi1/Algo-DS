#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
int main()
{
	string s="()(()))))";
	stack<int> st;
	st.push(-1);
	int result = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == '(')
			st.push(i);
		else
		{
			st.pop();

			if(!st.empty())
				result = max(result,i-st.top());
			else
				st.push(i);
		}
	}

	cout<<result;
}