#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct node{
	int data;
	node *left,*right;
	node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
};
void preorder(node *root)
{
	if(!root)
		return;
	stack<node *> s;
	s.push(root);
	while(!s.empty())
	{
		node *temp=s.top();
		s.pop();
		cout<<temp->data << " ";
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}
int main()
{
  node *root = new node(10);
  root->left        = new node(8);
  root->right       = new node(2);
  root->left->left  = new node(3);
  root->left->right = new node(5);
  root->right->left = new node(2);
  preorder(root);
}