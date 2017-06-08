#include <iostream>
#include <cstdio>
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
void convert(node *root,node* &head,node* &end)
{
	if(!root)
		return;
	convert(root->left,head,end);

	if(!head)
		head=end=root;
	else
	{
		end->right=root;
		root->left=end;
		end=root;
	}

	convert(root->right,head,end);
}
node* convert(node *root)
{
	if(!root)
		return root;
	node *head=NULL,*end=NULL;
	convert(root,head,end);
	return head;
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
	node *root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);

	node *result = convert(root);

	while(result)
	{
		printf("%d ",result->data);
		result=result->right;
	}
}