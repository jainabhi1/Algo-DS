#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
struct node{
	int data;
	node *next,*prev;
	node(int data)
	{
		this->data=data;
		next=prev=NULL;
	}
};
class lrulist{
	node *head,*end;
	int pages;
	int size;
	unordered_map<int,node *>m;
	void pop(node *temp)
	{
		if(temp == head && temp == end)
		{
			head = end = NULL;
		}
		else if(temp == head)
		{
			head = head->next;
			head->prev=NULL;
		}
		else if(temp == end)
		{
			end =  end->prev;
			end->next=NULL;
		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev = temp->prev;
		}
		
		temp->next = temp->prev = NULL;
	}
	void push_back(int data)
	{
		node *temp = new node(data);
		if(!head)
			head=end=temp;
		else
		{
			end->next=temp;
			temp->prev=end;
			end=temp;
		}
	}
	void push_back(node *temp)
	{
		if(!head)
			head=end=temp;
		else
		{
			end->next=temp;
			temp->prev=end;
			end=temp;
		}
	}
public:
	lrulist(int size)
	{
		this->size=size;
		head=end=NULL;
		pages=0;
	}
	void push(int data)
	{
		
		if(m[data] == NULL)
		{
			node *temp = new node(data);
			m[data] = temp;
			if(pages < size)
			{
				push_back(temp);
				pages++;
			}
			else
			{
				node *t = head;
				pop(t);
				push_back(temp);
				m[t->data] = NULL;
				delete t;
			}
		}
		else
		{
			node *temp = m[data];
			pop(temp);
			push_back(temp);
		}
	}
	void print()
	{
		node *temp=head;

		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main()
{
	lrulist l(3);
	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);
	l.push(3);
	l.print(); /*2 4 3*/
	l.push(2);
	l.push(5);
	l.print();/* 3 2 5 */

}	
