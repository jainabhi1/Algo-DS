#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	int a[]={6, 1, 5, 4, 5, 2, 6};
	int n=7;
	int maxx=0;
	stack<int> s;
	for(int i=0;i<n;)
	{
		if(s.empty() || a[s.top()] <= a[i])
			s.push(i++);
		else
		{
			int t=s.top();
			s.pop();
			
			int area = a[t]*((s.empty())?i:i-s.top()-1);
			maxx=max(area,maxx);
		}
	}

	while(!s.empty())
	{
		int t=s.top();
		s.pop();
		int area=a[t]*((s.empty())?n:n-s.top()-1);
		maxx=max(area,maxx);
	}

	cout<<maxx;
}