#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
struct node{
	int data;
	node *left,*right,*next;
	node(int data)
	{
		this->data=data;
		left=right=next=NULL;
	}
};
node *getnext(node *root)
{
	
	while(root)
	{
		
		if(root->left)
			return root->left;
		else if(root->right)
			return root->right;

		root=root->next;
	}
	return NULL;
}
void connect(node *root)
{
	if(!root)
		return;
	root->next=NULL;
	int count=0;
	while(root)
	{
		count++;
		node *temp=root;
		while(temp!=NULL)
		{
			count++;
			if(temp->left)
			{
				if(temp->right)
					temp->left->next=temp->right;
				else
					temp->left->next=getnext(temp->next);
			}

			if(temp->right)
			{
				temp->right->next=getnext(temp->next);
			}
			temp=temp->next;
		}
		if(root->left)
			root=root->left;
		else if(root->right)
			root=root->right;
		else
			root=getnext(root->next);
	}
}
void print(node *root)
{
	while(root)
	{
		printf("%d ", root->data);
		root=root->next;
	}
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
	connect(root);
	print(root->left->left);
}