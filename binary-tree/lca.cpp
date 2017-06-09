#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int data;
	node *left,*right;
	node(int data){
		left=right=NULL;
		this->data=data;
	}
};
node* findlcautil(node *root,int l1,int l2,bool &v1,bool &v2)
{
	if(!root)
		return NULL;

	node *temp=NULL;

	if(root->data == l1)
	{
		v1=true;
		return root;
	}
	
	if(root->data == l2)
	{
		v2=true;
		return root;
	}

	node *left = findlcautil(root->left,l1,l2,v1,v2);
	node *right = findlcautil(root->right,l1,l2,v1,v2);

	if(left && right)
		return root;

	return (left)?left:right;

}
bool find(node *root,int data)
{
	if(!root)
		return false;

	if(root->data == data || find(root->left,data) || find(root->right,data))
		return true;
	else
		return false;
}
void findlca(node *root,int l1,int l2)
{
	bool v1=false;
	bool v2=false;
	node *ans = findlcautil(root,l1,l2,v1,v2);
	
	if(v1&&v2 || v1&&find(ans,l2) || v2&&find(ans,l1))
		cout<<ans->data;
	else
		cout<<"no lca";


}
int main()
{
	node * root =  new node(1);
    root->left =  new node(2);
    root->right =  new node(3);
    root->left->left =  new node(4);
    root->left->right =  new node(5);
    root->right->left =  new node(6);
    root->right->right =  new node(7);
    findlca(root,9,16);
}