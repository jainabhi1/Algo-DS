#include <iostream>
#include <cstdio>
using namespace std;
int powerr(int a,int n)
{
	if(n==0)
		return 1;
	
	int res = powerr(a,n/2);

	if(n&1)
		return a*res*res;
	else
		return res*res;
}

int poweri(int a,int n)
{
	int res=1;
	int b=1;
	while(b<=n)
	{
		if(b&1)
			res=res*res*a;
		else
			res=res*res;
		
		b=b*2;
	}

	return res;
}

int main()
{
	cout<<poweri(2,16)<<endl;

	cout<<powerr(2,16)<<endl;
}