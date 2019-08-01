#include<bits/stdc++.h>
using namespace std;

#define sc(a) scanf("%d",&a)
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)



int n;
int lt[105],rt[105];

int ls[105],sz;

int main()
{
	int t,i,j,k;
	
	sc(n);
	fl(1,i,n+1)
	{
		sc(lt[i]);
		sc(rt[i]);
		if(lt[i]==0)ls[sz++]=i;
	}
	
	int e=ls[0];
	while( rt[e] )e=rt[e];
	
	for(i=1;i<sz;i++)
	{
		rt[e]=ls[i];
		lt[ ls[i] ]=e;
		
		e=ls[i];
		while( rt[e] )e=rt[e];
	}
	
	fl(1,i,n+1)printf("%d %d\n",lt[i],rt[i]);
	
	return 0;
}




