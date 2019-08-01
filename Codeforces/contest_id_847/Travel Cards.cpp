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

#define M 200005
#define MD 1000000007LL


int n,a,b,m,x;

int cs[305],sz;
string q1,q2;
char s[22],ss[22];
map< pair<string,string>,int >mp;
map< pair<string,string>,int >::iterator id;

int p[305][305];

int dp(int i,int r)
{
	if(i==sz)return 0;
	
	int &pr=p[i][r];
	if(pr!=-1)return pr;
	pr=dp(i+1,r)+cs[i];
	if(r)pr=min(pr, dp(i+1,r-1)+x );
	return pr;
}

int main()
{
	int t,i,j,k;
	memset(p,-1,sizeof(p));
	sc2(n,a);
	sc2(b,m);
	sc(x);
	
	string ls="";
	f(i,n)
	{
		scanf(" %s %s",s,ss);
		q1=string(s);
		q2=string(ss);
		int nw;
		if(q1==ls)nw=b;
		else nw=a;
		
		ls=q2;
		if(q1>q2)swap(q1,q2);
		
		id=mp.find( make_pair(q1,q2) );
		
		if(id==mp.end())
		{
			mp[ make_pair(q1,q2) ]=k=sz++;
		}
		else
			k=id->yy;
			
		cs[k]+=nw;
	}
	
	printf("%d\n",dp(0,m));
	
	return 0;
}
