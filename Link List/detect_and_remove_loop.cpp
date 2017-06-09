#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int data;
	node *next;
	node(int data){
		this->data=data;
		next=NULL;
	}
};
void detectandremove(node *head)
{
	node *slow=head;
	node *fast=head;
	while(fast&&fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow == fast)
			break;
	}
	
	if(slow == fast)
	{
		slow=head;
		while(slow->next != fast->next)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	fast->next=NULL;
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
	node *head =  new node(50);
    head->next =  new node(20);
    head->next->next =  new node(15);
    head->next->next->next =  new node(4);
    head->next->next->next->next =  new node(10);
 
    
    head->next->next->next->next->next = head->next->next;
 
    detectandremove(head);
 
    printf("Linked List after removing loop \n");
    print(head);
}