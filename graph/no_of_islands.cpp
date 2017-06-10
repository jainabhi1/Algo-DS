#include <iostream>
#include <cstdio>
using namespace std;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,1,0,-1,1,1,-1,0};
const int N=5;
int check(int x,int y)
{
	if(x < 0 || y < 0 || x >= N || y >= N)
		return 0;
	return 1;
}
void dfs(int x,int y,int m[N][N],bool visited[N][N])
{
	visited[x][y]=true;
	
	for(int i=0;i<8;i++)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(visited[xx][yy]==false && check(xx,yy) == 1 && m[xx][yy] == 1)
			dfs(xx,yy,m,visited);
	}
}
int main()
{
	 int m[N][N]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
    bool visited[N][N];
    for(int i=0;i<N;i++)
    	fill(visited[i],visited[i]+N,false);

    int count=0;
    for(int i=0;i<N;i++)
    {
    	for(int j=0;j<N;j++)
    	{
    		if(!visited[i][j] && m[i][j] == 1)
    		{
    			dfs(i,j,m,visited);
    			count++;
    		}
    	}
    }

    cout<<count;
}