#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
class queue{
	stack<int> en,de;
public:
	void enqueue(int key)
	{
		en.push(key);
	}
	void deque()
	{
		if(en.empty() && de.empty())
			throw runtime_error("empty");
		if(de.empty())
		{
			while(!en.empty())
			{
				de.push(en.top());
				en.pop();
			}
		}
		de.pop();
	}
	int front()
	{
		if(en.empty() && de.empty())
			throw runtime_error("empty");
		if(de.empty())
		{
			while(!en.empty())
			{
				de.push(en.top());
				en.pop();
			}
		}

		return de.top();
	}
	bool empty()
	{
		return en.empty() && de.empty();
	}
};
int main()
{
	queue q;

	for(int i=0;i<10;i++)
		q.enqueue(i);

	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.deque();
	}
	/*0 1 2 3 4 5 6 7 8 9*/
}