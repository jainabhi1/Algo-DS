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
struct node
{
	int data;
	node *left,*right;
	node(int data)
	{
		left=right=NULL;
		this->data=data;
	}
};
int res=0;
int findmax(node *root)
{
	if(root==NULL)
		return 0;
	int l=findmax(root->left);
	int r=findmax(root->right);

	int maxs=max(max(l,r)+root->data,root->data);
	int maxt=max(maxs,l+r+root->data);
	res=max(res,maxt);
	return maxs;
}
void inorder(node *root)
{
	if(!root)
		return;

	inorder(root->left);

	printf("%d ", root->data);

	inorder(root->right);
}
int main()
{
	node *root = new node(10);
    root->left        = new node(2);
    root->right       = new node(10);
    root->left->left  = new node(20);
    root->left->right = new node(1);
    root->right->right = new node(-25);
    root->right->right->left   = new node(3);
    root->right->right->right  = new node(4);
    findmax(root);
    cout<<res;
}