#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[]={5,6,7,8,9,10,1,2,3,4};
	int n=10;
	int l=0,r=n-1;
	int ans=-1;
	int key=1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(a[mid] == key)
		{
			ans=mid;
			break;
		}
		bool t1 = (a[l] < a[mid]) && key <= a[mid] && key >= a[l];
		bool t2 = (a[l] > a[mid]) && key >= a[mid] && key >= a[l];
		bool t3 = (a[l] > a[mid]) && key <= a[mid] && key <= a[l];

		if(t1 || t2 || t3)
			r=mid;
		else
			l=mid+1;
	}

	if(ans == -1)
		if(a[l] == key)
			ans=l;
	cout<<ans;
}