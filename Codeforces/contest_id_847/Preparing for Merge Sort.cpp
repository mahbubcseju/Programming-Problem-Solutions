#include<bits/stdc++.h>
using namespace std;

#define sc(a) scanf("%d",&a)
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)
#define xx first
#define yy second

#define mid ((s+e)>>1)
#define lft ((i<<1)+1)
#define rgt (lft+1)

#define M 200005
#define MD 1000000007LL

int n;
int a[M];
int tr[M*4];
bool vs[M];

void bld(int i,int s,int e)
{
	if(s==e)
	{
		sc(a[s]);
		tr[i]=s;
		return ;
	}
	bld(lft,s,mid);
	bld(rgt,mid+1,e);
	
	if(a[tr[lft]]>=a[tr[rgt]])
		tr[i]=tr[lft];
	else
		tr[i]=tr[rgt];
}

void updt(int i,int s,int e,int ps)
{
	if(s==e)
	{
		a[s]=0;
		tr[i]=s;
		return ;
	}
	if(ps<=mid)updt(lft,s,mid,ps);
	else 	   updt(rgt,mid+1,e,ps);
	if(a[tr[lft]]>=a[tr[rgt]])
		tr[i]=tr[lft];
	else
		tr[i]=tr[rgt];
}

int qry(int i,int s,int e,int st,int ed)
{
	if(st<=s&&e<=ed)return tr[i];
	if(ed<=mid)return qry(lft,s,mid,st,ed);
	if(mid<st)return qry(rgt,mid+1,e,st,ed);
	int q1=qry(lft,s,mid,st,ed);
	int q2=qry(rgt,mid+1,e,st,ed);
	if( a[q1]>=a[q2] )return q1;
	return q2;
}

int main()
{
	int t,i,j,k;
	
	sc(n);
	bld(0,1,n);
	
	for(i=1;i<=n;i++)
	{
		if(vs[i])continue;
		printf("%d",a[i]);
		k=i;
		int ls=a[k];
		while(k<n)
		{
			int lo,hi,md,id=-1;
			lo=k+1;
			hi=n;
			
			while(lo<=hi)
			{
				md=(lo+hi)>>1;
				int c=qry(0,1,n,k+1,md);
				
				if( a[c]>ls )
				{
					id=c;
					hi=min(c,md)-1;
				}
				else
					lo=md+1;
			}
			if(id==-1)break;
			
			printf(" %d",a[id]);
			vs[id]=1;
			ls=a[id];
			updt(0,1,n,id);
			k=id;
		}
		printf("\n");
	}
	
	
	return 0;
}
