#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;
const int R=4;
const int C=4;
pair<int,int> search(int mat[R][C],int key)
{
	pair<int,int> ans={-1,-1};
	int j=C-1;
	int i=0;
	while(i>=0 && j>=0 && i<R && j<C)
	{
		if(mat[i][j]==key)
		{
			ans.first=i;
			ans.second=j;
			break;
		}
		if(mat[i][j] > key)
			j--;
		else if(mat[i][j] < key)
			i++;
	}
	return ans;
}
int main()
{
	int mat[R][C] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
    auto it = search(mat,29);
    cout<<it.first << " " << it.second;
}