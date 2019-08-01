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

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n,m;
int p,q;

char gr[255][255];
vector< int >v[26];

ll c[255][255];
int vs[255][255],qk=1;
int ls[251*251*3];

void bfs(int x,int y,int cs)
{
	int l,r;
	qk++;
	l=r=0;
	ls[r++]=x;
	ls[r++]=y;
	ls[r++]=cs;
	vs[x][y]=qk;
	int i;
	while(l<r)
	{
		x=ls[l++];
		y=ls[l++];
		cs=ls[l++];
		if(c[x][y]<=p)c[x][y]+=cs;
		cs/=2;
		if(cs)
		f(i,4)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=n||ny<0||ny>=m||
			gr[nx][ny]!='.'||vs[nx][ny]==qk)continue;
			vs[nx][ny]=qk;
			ls[r++]=nx;
			ls[r++]=ny;
			ls[r++]=cs;
		}
	}
}


int main()
{
	int t,i,j,k;
	
	sc2(n,m);
	sc2(q,p);
	f(i,n)
	{
		scanf(" %s",gr[i]);
		f(j,m)
		{
			if( gr[i][j]>='A'&&gr[i][j]<='Z' )
			{
				v[ gr[i][j]-'A' ].pb(i);
				v[ gr[i][j]-'A' ].pb(j);
				gr[i][j]='.';
			}
		}
	}
	
	
	f(k,26)
	{
		for(j=0;j<v[k].size();j+=2)
		{
			bfs(v[k][j],v[k][j+1], q*(k+1) );
		}
	}
	
	int rs=0;
	f(i,n)
	{
		f(j,m)
		{
			//cerr<<c[i][j]<<" ";
			if( c[i][j]>p )rs++;
		}
		//printf("\n");
	}
	printf("%d\n",rs);
	
	return 0;
}
