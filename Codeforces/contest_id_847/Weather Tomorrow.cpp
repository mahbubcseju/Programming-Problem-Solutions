#include<bits/stdc++.h>
using namespace std;

#define sc(a) scanf("%d",&a)
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)



int n;
int a[105];

int main()
{
	int t,i,j,k;
	
	sc(n);
	f(i,n)sc(a[i]);
	
	for(i=2;i<n;i++)
	{
		if( a[i-1]-a[i-2]!=a[i]-a[i-1] )
		{
			printf("%d\n",a[n-1]);
			return 0;
		}
	}
	
	printf("%d\n", a[n-1]+a[n-1]-a[n-2] );
	
	return 0;
}
