#ifndef MIN_HEAP_H
#define MIN_HEAP_H


using namespace std;
class min_heap{
	int size;
	vector<int> v;
	int parent(int i)
	{
		return (i-1)/2;
	}
	void minheapify(int i)
	{
		int left = 2*i+1;
		int right = 2*i+2;
		int smallest = i;

		if(left < size && v[left] < v[i])
			smallest = left;
		if(right < size && v[right] < v[smallest])
			smallest = right;

		if(i != smallest)
		{
			swap(v[i],v[smallest]);
			minheapify(smallest);
		}
	}
public:
	min_heap()
	{
		size=0;
	}
	min_heap(vector<int> &v1)
	{
		size=v1.size();
		for(int i=0;i<size;i++)
			v.push_back(v1[i]);
	
		for(int i=(size-1)/2 ; i>=0 ; i--)
			minheapify(i);
	}
	void insert(int key)
	{
		int i=size;
		v.push_back(key);
		size++;

		while(i!=0 && v[parent(i)] > key)
		{
			swap(v[parent(i)],v[i]);
			i=parent(i);
		}
	}
	void extractmin()
	{
		if(size == 0)
		{
			throw runtime_error("Heap Size is 0");
		}
		if(size == 1)
		{
			v.pop_back();
			size--;
			return;
		}
		v[0]=v[size-1];
		v.pop_back();
		size--;
		minheapify(0);
	}
	int top()
	{
		if(size == 0)
		{
			throw runtime_error("Heap Size is 0");
		}
		return v[0];
	}
	int getsize()
	{
		return size;
	}
};

#endif