#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;
int main()
{
	int n=2,k=36;
	int dp[n+1][k+1];

	for(int i=1;i<=n;i++)
	{
		dp[i][1]=1;
		dp[i][0]=0;
	}

	for(int i=1;i<=k;i++)
	{
		dp[1][i]=i;
	}

	for(int i=2;i<=n;i++)
		for(int j=2;j<=k;j++)
		{
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;x++)
			{
				int res=1+max(dp[i-1][x-1],dp[i][j-x]);
				dp[i][j]=min(res,dp[i][j]);
			}
		}

	cout<<dp[n][k];

}