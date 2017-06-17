#include <iostream>
#include <cstdio>
using namespace std;
struct stock
{
	int buy;
	int sell;
};
void sol(int a[],int n)
{
	if(n == 1)
		return;
	stock arr[n/2+1];
	int count=0;
	int i=0;
	while(i<n)
	{
		while(i<n-1 && a[i+1] <= a[i])
			i++;
		if(i == n-1)
			break;

		arr[count].buy=i++;

		while(i<n && a[i] >= a[i-1])
			i++;

		arr[count].sell=i-1;
		count++;
	}
	for(int i=0;i<count;i++)
		cout << arr[i].buy << " " << arr[i].sell << endl;
}
int main()
{
	int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);

    sol(price, n);
}