#include <iostream>
#include <cstdio>
#include <vector>
#include "min_heap.h"
using namespace std;
int main()
{
	vector<int> v={12, 3, 5, 7, 19};
	minheap h;
	int k=3;
	for(int i=0;i<v.size();i++)
	{
		if(h.getsize() < k)
		{
			h.insert(v[i]);
		}
		else 
		{
			if(h.top() < v[i])
			{
				h.extractmin();
				h.insert(v[i]);
			}
		}
	}
	while(h.getsize())
	{
		cout<<h.top() << " ";
		h.extractmin();
	}
}