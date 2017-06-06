#include <cstdio>
#include <iostream>
#include <climits>
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
class largestbst{
	int max_size=0;
	int isbst=0;
	int minn=INT_MAX;
	int maxx=INT_MIN;
	int solveutil(node *root)
	{
		if(!root)
		{
			isbst=true;
			return 0;
		}
		bool left=false;
		bool right=false;
		maxx = INT_MIN;
		int l = solveutil(root->left);
		if(root->data > maxx && isbst)
			left=true;
		
		int minnn = minn;

		minn = INT_MAX;
		int r = solveutil(root->right);
		if(root->data < minn && isbst)
			right=true;

		minn=min(minnn,minn);
		maxx=max(root->data,maxx);
		minn=min(root->data,minn);
		
		if(left && right)
		{
			isbst = true;
			max_size=max(max_size,l+r+1);
			return l+r+1;
		}
		else
		{
			isbst=false;
			return 0;
		}
		
	}
public:
	int solve(node *root)
	{
		solveutil(root);
		return max_size;
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