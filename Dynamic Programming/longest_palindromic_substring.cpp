#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	string s="hbhbdusuccudscd";
	int n=s.length();
	int maxx=1;
	int dp[n][n];

	for(int i=0;i<n;i++)
		fill(dp[i],dp[i]+n,0);

	for(int i=0;i<n;i++)
		dp[i][i]=1;

	for(int l=2;l<=n;l++)
	{
		for(int i=0;i+l<=n;i++)
		{
			int j=i+l-1;

			if(s[i]==s[j])
			{
				if(l==2)
					dp[i][j] = 2;
				else 
				{
					if(dp[i+1][j-1])
						dp[i][j] = dp[i+1][j-1]+2;
					else
						dp[i][j]=0;
				}
			}
			else
				dp[i][j] = 0;

			maxx=max(dp[i][j],maxx);
		}
	}

	cout<<maxx;/*uccu*/
}