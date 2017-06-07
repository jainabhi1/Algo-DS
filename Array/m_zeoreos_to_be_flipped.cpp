#include <iostream>
#include <cstdio>
using namespace std;
int maxones(int a[],int n,int m)
{
	int wr=0;
	int wl=0;
	int zerocount=0;
	int maxx=0;
	while(wr<n&&wl<n)
	{
		if(a[wr]==0)
			zerocount++;

		if(zerocount<=m)
		{
			wr++;
		}
		
		if(zerocount>m)
		{
			if(a[wl]==0)
				zerocount--;
			wl++;
		}
		maxx=max(maxx,wr-wl);
	}
	return maxx;
}
int main()
{
	int a[]={1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
	int n=sizeof(a)/sizeof(a[0]);
	int m=2;
	cout<<maxones(a,n,2);
}