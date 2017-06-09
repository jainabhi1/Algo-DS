#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
const int N=123456;
int tree[N];
void build(int node,int start,int end,int a[])
{
	if(start==end)
	{
		tree[node]=start;
		return;
	}
	int mid = (start+end)>>1;
	build(node*2+1,start,mid,a);
	build(node*2+2,mid+1,end,a);
	tree[node] = (a[tree[node*2+1]] < a[tree[node*2+2]])?tree[node*2+1]:tree[node*2+2];
}
int query(int node,int start,int end,int l,int r,int a[])
{
	if(l>r || start > r || end < l)
		return INT_MAX;

	if(start >= l && end <= r)
		return tree[node];

	int mid=(start+end)>>1;
	int p1 = query(node*2+1,start,mid,l,r,a);
	int p2 = query(node*2+2,mid+1,end,l,r,a);
	
	if(p1 == INT_MAX)
		return p2;
	else if(p2 == INT_MAX)
		return p1;

	return (a[p1] < a[p2])?p1:p2;
}
int maxarea(int n,int l,int r,int a[])
{
	if(l>r)
		return 0;
	if(l==r)
		return a[l];

	int mid = query(0,0,n-1,l,r,a);
	//cout<<mid;
	return max(max(maxarea(n,l,mid-1,a),maxarea(n,mid+1,r,a)),a[mid]*(r-l+1));
}
int main()
{
	int a[]={6, 1, 5, 4, 5, 2, 6};
	int n=7;
	build(0,0,n-1,a);
	cout<<maxarea(n,0,n-1,a);
}