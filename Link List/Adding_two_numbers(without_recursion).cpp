#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int data;
	node *next;
	node(int data)
	{
		this->data=data;
		next=NULL;
	}
};
void reverse(node *&head)
{
	if(!head)
		return;
	if(!head->next)
		return;
	node *cur=head,*prev=NULL,*next;
	while(cur)
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
}
void push(node* &head,node *temp)
{
	if(!head)
		head=temp;
	else
	{
		temp->next=head;
		head=temp;
	}
}
void print(node* head)
{
	while(head)
	{
		printf("%d ", head->data);
		head=head->next;
	}
}
node* add(node *&head1,node *&head2)
{
	node *result=NULL;
	reverse(head1);
	reverse(head2);
	int carry=0;
	node *temp1=head1,*temp2=head2;
	while(temp1&&temp2)
	{
		int s=temp1->data+temp2->data+carry;
		carry=s/10;
		s%=10;
		push(result,new node(s));
		temp1=temp1->next;
		temp2=temp2->next;
	}
	temp1 = (temp1!=NULL)?temp1:temp2;
	while(temp1)
	{
		int s=temp1->data+carry;
		carry=s/10;
		s%=10;
		push(result,new node(s));
		temp1=temp1->next;
	}
	if(carry>0)
		push(result,new node(carry));
	reverse(head1);
	reverse(head2);

	return result;
}
/*1->2->3 represents number 123*/

int main()
{
	node *head1=new node(1);
	head1->next=new node(2);
	head1->next->next=new node(3);

	node *head2=new node(9);
	head2->next=new node(8);
	head2->next->next=new node(7);

	node *result = add(head1,head2);
	print(result);
}