#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	/* no of bst with numbers range 1 to n
	formula = catalan numbers*/
	vector<int>v(11);
	v[0]=1;
	v[1]=1;

	for(int i=2;i<=10;i++)
	{
		int ans=0;
		for(int j=1;j<=i;j++)
		{
			ans+=v[j-1]*v[i-j];
		}
		v[i]=ans;
	}

	for(int i=0;i<=10;i++)
		cout<<v[i]<<" ";

}