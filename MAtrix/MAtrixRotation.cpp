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
const int N=4;
void rotate(int mat[][N])
{
    for(int x=0;x<N/2;x++)
    {
        for(int y=x;y<N-1;y++)
        {
            int temp=mat[x][y];

            mat[x][y] = mat[y][N-1-x];

            mat[y][N-1-x]=mat[N-1-x][N-1-y];

            mat[N-1-x][N-1-y]=mat[N-1-y][x];

            mat[N-1-y][x]=temp;
        }
    }
}
int main()
{
   int mat[][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotate(mat);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}