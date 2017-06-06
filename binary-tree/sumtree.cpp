#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int data;
	node *left,*right;
	node(int data)
	{
		this->data=data;
		left=right;
	}
};
bool sumtree(node *root)
{
	if(!root)
		return true;
	bool l=sumtree(root->left);
	bool r=sumtree(root->right);
	int leftsum,rightsum;
	if(!root->left)
		leftsum=0;
	else if(!root->left->left && !root->left->right)
		leftsum=root->left->data;
	else 
		leftsum=root->left->data*2;

	if(!root->right)
		rightsum=0;
	else if(!root->right->left && !root->right->right)
		rightsum=root->right->data;
	else 
		rightsum=root->right->data*2;
	if(leftsum + rightsum == 0)
		return true;
	return (root->data == leftsum+rightsum && l && r);
}
int main()
{
    node *root  = new node(26);
    root->left         = new node(10);
    root->right        = new node(3);
    root->left->left   = new node(4);
    root->left->right  = new node(6);
    root->right->right = new node(3);
  if(sumtree(root))
  	cout<<"sumtree";
  else
  	cout<<"not sumtree";
}