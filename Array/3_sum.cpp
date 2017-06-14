#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int a[]={1, 4, 45, 6, 10, 8};
	int n=sizeof(a)/sizeof(a[0]);
	int sum = 22;
	sort(a,a+n);

	for(int i=0;i<n-2;i++)
	{
		int l=i+1;
		int r=n-1;
		while(l<r)
		{
			if(a[l]+a[i]+a[r] == sum)
			{
				cout<<i<<" " << l <<" " << r <<endl;
				break;
			}
			else if(a[l]+a[i]+a[r] > sum)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
	}

}