#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)
#define xx first
#define yy second
#define pb push_back

#define mid ((s+e)>>1)
#define lft ((i<<1)+1)
#define rgt (lft+1)

#define M 262154
#define MD 1000000007LL


int n,m;
int a[M];
pair<int,int> b[M];
int sz;

int tr[M];

void add(int i)
{
	assert(i>=1&&i<=n);
	if(i)
	for(;i<M;i+=(i&-i))tr[i]++;
}

int qry(int i)
{
	assert(i>=0&&i<=n);
	int q=0;
	for(;i>0;i-=(i&-i))q+=tr[i];
	return q;
}

int clc2()
{
	sort(b,b+sz);
	int i;
	int rs=0;
	f(i,sz)
	{
		add( b[i].yy );
		int r=min(m-1,n);
		if( b[i].xx>0 )r=min( r, m-b[i].xx-1 );
		
		//cerr<<i<<" "<<b[i].xx<<" : "<<b[i].yy<<endl;
		if(r>0)rs=max( rs, qry(r) );
	}
	return rs;
}

int main()
{
	int t,i,j,k;
	
	sc2(n,m);
	sz=0;
	fl(1,i,n+1)
	{
		sc(a[i]);
		b[sz++]=make_pair(a[i]-i,i);
	}
	int rs=clc2();
	printf("%d\n",rs);
	
	return 0;
}
