#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string a,b,c;
	int n=a.length();
	int m=b.length();
	if(n + m != c.length())
	{
		printf("Not True\n");
		return 0;
	}
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
		fill(dp[i],dp[i]+m+1,0);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 && j==0)
				dp[i][j] = true;
			else
			{
				if(a[i-1]==c[i+j-1])
					dp[i][j] = dp[i-1][j];

				if(b[j-1]==c[i+j-1])
					dp[i][j] = dp[i][j-1]||dp[i-1][j];
			}
		}
	}
	cout<<dp[n][m];
}