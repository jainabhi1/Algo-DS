#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[]={8, 15, 3, 7};
	int n=sizeof(a)/sizeof(a[0]);
	int dp[n][n];

	for(int l=0;l<n;l++)
	{
		for(int i=0;i+l<n;i++)
		{
			int j=i+l;
			int x = (i+2 <= j)?dp[i+2][j]:0;
			int y = (i+1 <= j-1)?dp[i+1][j-1]:0;
			int z = (j-2 >= i)?dp[i][j-2]:0;

			dp[i][j] = max(a[i] + min(x,y),a[j] + min(y,z));
		}
	}

	cout<<dp[0][n-1];
}