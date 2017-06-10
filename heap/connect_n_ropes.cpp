#include <iostream>
#include <cstdio>
#include <vector>
#include "min_heap.h"
using namespace std;
int main()
{
	vector<int> v={4, 3, 2, 6};
	min_heap h(v);
	int cost=0;
	while(h.getsize() > 1)
	{
		int first = h.top();
		h.extractmin();
		int second = h.top();
		h.extractmin();
		cost+=(first+second);
		h.insert(first+second);
	}
	cout<<cost;
}