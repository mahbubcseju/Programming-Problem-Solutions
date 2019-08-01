#include<bits/stdc++.h>
using namespace std;

#define sc(a) scanf("%d",&a)
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)



int n;
//int ls[1005],sz;
char s[9];
int fr[8];

int main()
{
	int t,i,j,k;
	
	
	sc(n);
	f(i,n)
	{
		scanf(" %s",s);
		//k=0;
		f(j,7)if(s[j]=='1')fr[j]++;//k|=(1<<j);
	}
	
	int rs=0;
	f(i,7)rs=max(fr[i],rs);
	
	printf("%d\n",rs);
	
	return 0;
}




