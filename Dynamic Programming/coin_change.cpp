#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(a[0]);
	int sum=4;
	int dp[sum+1];
	
	fill(dp,dp+sum+1,0);
	dp[0]=1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=a[i];j<=sum;j++)
			dp[j]+=dp[j-a[i]];
	}

	cout<<dp[sum];
}