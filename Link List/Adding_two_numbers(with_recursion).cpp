#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	int data;
	node *next=NULL;
	node(int data)
	{
		next=NULL;
		this->data=data;
	}
};
int len(node *head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}
void push(node* &result,node *temp)
{
	if(!result)
		result=temp;
	else
		temp->next=result,result=temp;
}
void addrecur2(node *head1,node *head2,node* &result,int &carry)
{
	if(!head1&&!head2)
		return;
	addrecur2(head1->next,head2->next,result,carry);
	int s=head1->data+head2->data+carry;
	carry=s/10;
	s%=10;
	push(result,new node(s));

}
void addrecur1(node *head1,node* &result,int &carry,int diff)
{
	if(diff==0)
		return;
	addrecur1(head1->next,result,carry,diff-1);
	int s=head1->data+carry;
	carry=s/10;
	s%=10;
	push(result,new node(s));
}
node* add(node* &head1,node*&head2)
{
	int len1=len(head1);
	int len2=len(head2);

	node *temp1=head1;
	node *temp2=head2;
	if(len2>len1)
		swap(temp1,temp2);
	int count=0;

	while(temp1&&count<abs(len1-len2))
	{
		count++;
		temp1=temp1->next;
	}
	node *result=NULL;
	int carry=0;
	int diff=abs(len1-len2);
	addrecur2(temp1,temp2,result,carry);
	addrecur1(temp1,result,carry,diff);
	if(carry)
		push(result,new node(carry));
	return result;
}
void print(node *head)
{
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}
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