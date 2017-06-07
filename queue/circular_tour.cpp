#include <iostream>
#include <cstdio>
using namespace std;
struct pump
{
	int petrol;
	int dis_next;
};
int startpoint(pump arr[],int n)
{
	int start=0;
	int end=1;
	int cur_petrol = arr[start].petrol - arr[start].dis_next;
	while(start!=end || cur_petrol < 0)
	{
		while(start!=end && cur_petrol < 0)
		{
			cur_petrol -= arr[start].petrol - arr[start].dis_next;
			start = (start+1)%n;

			if(start == 0)
				return -1;
		}
		cur_petrol += arr[end].petrol - arr[end].dis_next;
		end = (end+1)%n;
	}

	return start;
}
int main()
{
	pump arr[] = {{6, 4}, {3, 6}, {7, 3}};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<startpoint(arr,n);
}