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
void countsort(int a[],int n)
{
    int maxx=-99999999;
    for(int i=0;i<n;i++)
        maxx=max(a[i],maxx);
    
    vector<int> v(maxx+1,0);
    vector<int> output(n);
    for(int i=0;i<n;i++)
        v[a[i]]++;

    for(int i=1;i<=maxx;i++)
        v[i]+=v[i-1];

    for(int i=0;i<n;i++)
    {
        output[v[a[i]]-1]=a[i];
        v[a[i]]--;
    }

    for(int i=0;i<n;i++)
        a[i]=output[i];
}
int main()
{
  
   int arr[]={15,78,32,11,45,23,13,90};
   countsort(arr,8);
   for(int i=0;i<8;i++)
    cout<<arr[i]<<" ";
/*11 13 15 23 32 45 78 90*/
   
}