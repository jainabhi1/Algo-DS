#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
template<typename T>
struct node{
	T data;
	node *left,*right;
	node(T data)
	{
		this->data=data;
		left=right=NULL;
	}
};
template<typename T>
class bst{
	node<T> *root;
	node<T> * insertutil(node<T> *root,T data)
	{
		if(!root)
			return new node<T>(data);
		if(root->data < data)
			root->right = insertutil(root->right,data);
		else if(root->data > data)
			root->left = insertutil(root->left,data);

		return root;
	}
	T minvalue(node<T> *root)
	{
		while(root->left)
		{
			root=root->left;
		}
		return root->data;
	} 
	node<T> * removeutil(node<T> *root,T data)
	{
		if(!root)
			return NULL;
		if(root->data < data)
			root->right = removeutil(root->right,data);
		else if(root->data > data)
			root->left = removeutil(root->left,data);
		else
		{
			if(root->left == NULL && root->right == NULL)
			{
				delete root;
				return NULL;
			}
			if(root->left == NULL)
			{
				node<T> *temp=root->right;
				delete(root);
				return temp;
			}
			if(root->right == NULL)
			{
				node<T> *temp=root->left;
				delete(root);
				return temp;
			}
			T minv = minvalue(root->right);
			root->data = minv;
			root->right = removeutil(root->right,minv);
		}

		return root;
	}
public:
	bst()
	{
		root=NULL;
	}
	void insert(T data)
	{
		root = insertutil(root,data);
	}
	void remove(T data)
	{
		root = removeutil(root,data);
	}
	node<T>*begin()
	{
		return root;
	}
};
int main()
{
	bst<int> b;
	for(int i=0;i<=7;i++)
		b.insert(i);
}
