#include <iostream>
#include <cstdio>
using namespace std;
struct node{
	int coeff;
	int pow;
	node *next;
	node(int coeff,int pow)
	{
		this->coeff=coeff;
		this->pow=pow;
	} 
};
node append(node *&result,node *&end,node *temp)
{
	if(!result)
		result=end=temp;
	else
	{
		end->next=temp;
		end=temp;
	}
}
node *add(node *first,node *second)
{
	node *result=NULL,*end=NULL;
	while(first&&second)
	{
		node *temp;
		if(first->pow > second->pow)
		{
			temp=new node(first->coeff,first->pow)
			first=first->next;
		}
		else if(second->coeff > first->coeff)
		{
			temp=new node(second->coeff,second->pow)
			second=second->next;
		}
		else 
		{
			temp=new node(second->coeff+first->coeff,second->pow)
			second=second->next;
			first=first->next;	
		}
		append(result,end,temp);
	}
	node *temp1=(first)?first:second;
	while(temp1)
	{
		append(result,end,new node(temp1->coeff,temp1->pow));
		temp1=temp1->next;
	}
	return result;
}
int main()
{

}