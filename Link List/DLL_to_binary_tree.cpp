#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int data;
	node *next,*prev;
	node(int data)
	{
		this->data=data;
		prev=next=NULL;
	}
};
void push(node* &head,node *temp)
{
	if(!head)
		head=temp;
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void print(node *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head=head->next;
	}
}
node* convert(node* &head,int l,int r)
{
	if(l>r)
		return NULL;
	int mid=(l+r)>>1;
	node *left=convert(head,l,mid-1);

	node *root=head;
	root->prev=left;
	head=head->next;

	root->next=convert(head,mid+1,r);
	return root;
}
node* convert(node *&head)
{
	if(!head)
		return NULL;
	node *temp=head;
	int count=0;
	while(temp)
	{
		count++;
		temp=temp->next;
	}
	node *ans = convert(head,0,count-1);
	return ans;
}
void inorder(node *root)
{
	if(!root)
		return;
	inorder(root->prev);

	printf("%d ", root->data);

	inorder(root->next);
}
int main()
{
	node *head=NULL;
	for(int i=1;i<=7;i++)
		push(head,new node(i));
	node *ans=convert(head);
	inorder(ans);
}