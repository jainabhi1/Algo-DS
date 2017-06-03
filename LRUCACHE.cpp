#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <queue>
using namespace std;
struct node
{
    node *next,*prev;
    int data;
    node(int data)
    {
        this->data=data;
        prev=next=NULL;
    }
};
struct list
{
    node *head,*end;
    int size;
    int pages;
    list(int size)
    {
        head=end=NULL;
        this->size=size;
        pages=0;
    }
    void append(node *temp)
    {
        if(!head)
            head=end=temp;
        else
        {
            end->next=temp;
            temp->prev=end;
            end=temp;
        }
        pages++;
    }
    void remove()
    {
        node *temp=head;
        if(pages==1)
            head=end=NULL;
        else
        {
            head=head->next;
            head->prev=NULL;
        }
        delete(temp);
        pages--;
    }
    bool isfull()
    {
        if(pages==size)
            return true;
        else
            return false;
    }
    void move(node *temp)
    {
        if(temp==end||pages==1)
        {
            return;
        }
        else
        {
            if(temp==head)
            {
                head=head->next;
                head->prev=NULL;
            }
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            end->next=temp;
            temp->prev=end;
            end=temp;
            end->next=NULL;
        }
    }
    void print()
    {
        node *temp=head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void printr()
    {
        node *temp=end;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
};
int main()
{
   list l(3);
   node *hash[10];
   for(int i=0;i<10;i++){
    hash[i]=NULL;
   } 
   int a[]={1,2,3,1,5,4};
   for(int i=0;i<6;i++)
   {
    if(hash[a[i]]==NULL)
    {
        node *temp=new node(a[i]);
        hash[a[i]]=temp;
        if(l.isfull()==false)
        {    
            l.append(temp);
        }
        else
        {
            l.remove();
            l.append(temp);
        }
    }
    else
    {
        l.move(hash[a[i]]);
    }
   }
   l.print();
}
