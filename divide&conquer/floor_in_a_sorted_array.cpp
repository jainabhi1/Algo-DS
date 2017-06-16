#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[]={1, 2, 8, 10, 10, 12, 19};
	int n=sizeof(a)/sizeof(a[0]);
	int l=0,r=n-1;
	int key=15;
	while(l<r)
	{
		int mid = (l+r) >> 1;

		if(a[mid] > key)
			r=mid;
		else
			l=mid+1;
	}
	int ans;
	if(a[l] <= key)
		ans = a[l];
	else
		l--;
	if(l >= 0)
		ans = a[l];
	else
		ans = -1;

	cout << ans;
}