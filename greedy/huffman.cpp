#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	char s;
	int freq;
	node *left,*right;
	node(char data,int freq)
	{
		s=data;
		this->freq=freq;
		left=right=NULL;
	}
};
struct comp{
	bool operator()(const node *x,const node *y)
	{
		return x->freq > y->freq;
	}
};
void print(node *root,string s)
{
	if(!root)
		return;
	if(root->s != '$')
	{
		cout<< root->s << " " << s <<endl; 
	}
	
	print(root->left,s+"0");
	print(root->right,s+"1");
}
void encode(char arr[],int freq[],int n)
{
	priority_queue<node*, vector<node *> ,comp> pq;
	for(int i=0;i<n;i++)
	{
		pq.push(new node(arr[i],freq[i]));
	}
	while(pq.size() > 1)
	{
		node *left = pq.top();
		pq.pop();
		node *right = pq.top();
		pq.pop();

		node *top = new node('$',left->freq + right->freq);
		pq.push(top);
		top->left = left;
		top->right = right;
	}
	print(pq.top(),"");
}
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);
    encode(arr,freq,size);
}