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
void inorder(node *root)
{
	if(!root)
		return;

	inorder(root->left);

	printf("%d ", root->data);

	inorder(root->right);
}
void print(node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head=head->right;
	}
}
void convertToDll(node *root,node *&head,node* &end)
{
	if(!root)
		return;
	convertToDll(root->left,head,end);

	if(!head)
		head=end=root;
	else
	{
		end->right=root;
		root->left=end;
		end=root;
	}

	convertToDll(root->right,head,end);
}
int getsize(node *head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->right;
	}
	return count;
}
node* convertToTree(node* &head,int l,int r)
{
	if(l>r)
		return NULL;
	int mid=(l+r)>>1;
	node *left = convertToTree(head,l,mid-1);

	node *root=head;
	root->left=left;
	head=head->right;

	root->right=convertToTree(head,mid+1,r);
	return root;
}
node* merge(node *root1,node *root2)
{
	if(!root1 || !root2)
	{
		return (root1)?root1:root2;
	}
	node *head1 = NULL,*end1=NULL,*head2=NULL,*end2=NULL;
	convertToDll(root1,head1,end1);
	convertToDll(root2,head2,end2);
	end1->right=head2;

	int len = getsize(head1);

	return convertToTree(head1,0,len-1);

}
int main()
{
	node *root1=new node(1);
	root1->left=new node(2);
	root1->right=new node(3);
	root1->left->left=new node(4);
	root1->left->right=new node(5);
	root1->right->left=new node(6);
	root1->right->right=new node(7);

	node *root2=new node(11);
	root2->left=new node(12);
	root2->right=new node(13);
	root2->left->left=new node(14);
	root2->left->right=new node(15);
	root2->right->left=new node(16);
	root2->right->right=new node(17);

	node *ans = merge(root1,root2);
	inorder(ans);
}