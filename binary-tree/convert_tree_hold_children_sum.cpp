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
int getdata(node *root)
{
	if(!root)
		return 0;
	return root->data;
}
void convert(node *root)
{
	if(!root)
		return;
	if(!root->left && !root->right)
		return;
	int d=root->data -getdata(root->left) - getdata(root->right);

	if(d > 0)
	{
		if(root->left)
			root->left->data+=d;
		else if(root->right)
			root->right->data+=d;
	}
	convert(root->left);
	convert(root->right);
	root->data = getdata(root->left)+getdata(root->right);
}
void inorder(node *root)
{
	if(!root)
		return;
	inorder(root->left);

	printf("%d ",root->data );

	inorder(root->right);
}
int main()
{
  node *root =  new node(50);
  root->left        =  new node(7);
  root->right       =  new node(2);
  root->left->left  =  new node(3);
  root->left->right =  new node(5);
  root->right->left  =  new node(1);
  root->right->right =  new node(30);
  inorder(root);
  cout<<endl;
  convert(root);
  inorder(root);
}