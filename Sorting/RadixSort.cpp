#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <queue>
using namespace std;
void countsort(int a[],int n,int exp)
{
    vector<int> v(10,0);
    vector<int> output(n);
    for(int i=0;i<n;i++)
        v[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        v[i]+=v[i-1];

    for(int i=n-1;i>=0;i--)
    {
        output[v[(a[i]/exp)%10]-1]=a[i];
        v[(a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        a[i]=output[i];
}
void radixsort(int a[],int n)
{
    int maxx=*max_element(a,a+n);
    for(int i=1;maxx/i>0;i*=10)
        countsort(a,n,i);
}
int main()
{
   int arr[]={15,78,32,11,45,23,13,90};
   radixsort(arr,8);
   for(int i=0;i<8;i++)
    cout<<arr[i]<<" ";
    /*11 13 15 23 32 45 78 90*/
}