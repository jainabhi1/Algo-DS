#include <iostream>
#include <cstdio>
using namespace std;
int maxzero(int a[],int n)
{
	int cmax=0;
	int maxx=0;
	int zeroes=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
			zeroes++;
		int val=(a[i]==1)?1:-1;
		cmax=max(val,cmax+val);
		maxx=max(cmax,maxx);
	}
	maxx=max(0,maxx);
	return zeroes+maxx;
}
int main()
{
	int a[]={0, 1, 0, 0, 1, 1, 0};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<maxzero(a,n);
}