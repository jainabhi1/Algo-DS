#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
struct node
{
	int data;
	node *next,*random;
	node(int data)
	{
		this->data=data;
		next=random=NULL;
	}
};
node *clone(node *head)
{
	node *cur=head;
	map<node*,node*> m;
	while(cur)
	{
		m[cur]=new node(cur->data);
		cur=cur->next;
	}
	cur=head;
	while(cur)
	{
		m[cur]->next=m[cur->next];
		m[cur]->random=m[cur->random];
		cur=cur->next;
	}
	return m[head];
}
int main()
{
	
}