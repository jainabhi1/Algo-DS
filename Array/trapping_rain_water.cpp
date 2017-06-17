#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(a)/sizeof(a[0]);

	int rightmax[n];
	rightmax[n-1]=a[n-1];

	for(int i=n-2;i>=0;i--)
	{
		rightmax[i]=max(a[i],rightmax[i+1]);
	}

	int leftmax=-1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		leftmax=max(a[i],leftmax);
		sum+=min(leftmax,rightmax[i])-a[i];
	}

	cout<<sum;
}