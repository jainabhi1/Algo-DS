#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>
using namespace std;
struct node
{
	int data;
	node *left,*right,*next;
	node(int data)
	{
		left=right=NULL;
		this->data=data;
		next=NULL;
	}
};
void connect(node *root)
{
	if(!root)
		return;
	queue<pair<node*,int> > q;
	q.push({root,0});
	while(!q.empty())
	{
		node *temp=q.front().first;
		int l=q.front().second;
		q.pop();
		if(!q.empty())
		{
			if(l == q.front().second)
				temp->next=q.front().first;
		}

		if(temp->left)
			q.push({temp->left,l+1});
		if(temp->right)
			q.push({temp->right,l+1});
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
	/*4 5 6 7*/
}