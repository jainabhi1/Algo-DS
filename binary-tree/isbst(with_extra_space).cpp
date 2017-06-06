#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
struct node
{
	int data;
	node *left,*right;
	int minn,maxx,isbst,size;
	node(int data)
	{
		this->data=data;
		minn=maxx=data;
		isbst=size=1;
		left=right=NULL;
	}
};
class largestbst{
	int max_size=1;
	void solveutil(node *root)
	{
		if(!root)
			return;

		solveutil(root->left);
		solveutil(root->right);
		int leftmin=(root->left)?root->left->minn:INT_MAX;
		int leftmax=(root->left)?root->left->maxx:INT_MIN;
		int rightmin=(root->right)?root->right->minn:INT_MAX;
		int rightmax=(root->right)?root->right->maxx:INT_MIN;
		int left=(root->left)?root->left->isbst:1;
		int right=(root->right)?root->right->isbst:1;
		int lsize=(root->left)?root->left->size:0;
		int rsize=(root->right)?root->right->size:0;

		if(!left || !right || root->data < leftmax || root->data > rightmin)
			root->isbst=0;

		root->maxx=max(max(leftmax,rightmax),root->data);
		root->minn=min(min(leftmin,rightmin),root->data);
		root->size=1+lsize+rsize;

		if(root->isbst)
			max_size=max(root->size,max_size);

	}
public:
	int solve(node *root)
	{
		if(!root)
			return 0;
		solveutil(root);
		return max_size;
	}
	void inorder(node *root)
	{
		if(!root)
			return;

		inorder(root->left);
		printf("%d ",root->data );
		inorder(root->right);
	}
};

int main()
{
  node *root = new node(50);
  root->left        = new node(10);
  root->right       = new node(60);
  root->left->left  = new node(5);
  root->left->right = new node(20);
  root->right->left  = new node(55);
  root->right->left->left  = new node(45);
  root->right->right = new node(70);
  root->right->right->left = new node(65);
  root->right->right->right = new node(80);
  cout <<(new largestbst())->solve(root);

}