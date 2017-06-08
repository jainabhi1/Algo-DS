#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int data;
	node *left,*right;
	node(int data)
	{
		left=right=NULL;
		this->data=data;
	}
};
int diameter(node *root,int &maxx)
{
	if(!root)
		return 0;

	int l = diameter(root->left,maxx);
	int r = diameter(root->right,maxx);

	maxx = max(l+r+1,maxx);

	return max(l,r)+1;
}
int diameter(node *root)
{
	if(!root)
		return 0;
	int maxx=1;

	int d = diameter(root,maxx);

	return max(d,maxx);
}
int main()
{
	node *root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);

	cout<<diameter(root);
}