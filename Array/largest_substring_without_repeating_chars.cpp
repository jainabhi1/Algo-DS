#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s="ABDEFGABEF";
	int n=s.length();
	int h[256];
	fill(h,h+256,-1);
	int wr=0,wl=0;
	int maxx=0;
	while(wr<n && wl<n)
	{
		if(h[s[wr]] >= wl)
			wl++;
		else
		{
			h[s[wr]]=wr;
			wr++;
		}
		maxx=max(maxx,wr-wl);
	}

	cout<<maxx;
}