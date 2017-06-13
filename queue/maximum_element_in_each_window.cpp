#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int main()
{
	int a[]={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
	int n=sizeof(a)/sizeof(a[0]);
	int k=4;

	deque<int> q;
	for(int i=0;i<k;i++)
	{
		while(!q.empty() && a[q.back()] <= a[i])
			q.pop_back();
		q.push_back(i);
	}
	cout<<a[q.front()]<<endl;
	
	for(int i=k; i<n ;i++)
	{
		
		if(q.front() < i-k)
			q.pop_front();

		while(!q.empty() && a[q.back()] <= a[i])
			q.pop_back();
		if(!q.empty())
			cout<<a[q.front()]<<endl;
		else
			cout<<a[i]<<endl;

		q.push_back(i);
		
	}
}