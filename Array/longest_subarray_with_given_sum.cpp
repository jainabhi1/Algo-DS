#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
int main()
{
	int a[]={15, -2, 2, -8, 1, 7, 10, 23};
	int n=sizeof(a)/sizeof(a[0]);

	unordered_map<int,int> m;
	m[0]=-1;

	int k=0;

	int curr_sum=0;
	int maxx=-99999;

	for(int i=0;i<n;i++)
	{
		curr_sum+=a[i];
		
		int diff = curr_sum - k;

		if(m.find(diff) != m.end())
		{
			maxx=max(maxx,i-m[diff]);
		}

		if(m.find(curr_sum) == m.end())
			m[curr_sum]=i;
	}

	cout<<maxx;
}