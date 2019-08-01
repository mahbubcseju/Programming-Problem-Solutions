#include<bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d",a)
#define PL(a) printf("%lld",a)
#define PT(t) printf("Case %d: ",t)
#define PB push_back
#define x first
#define y second
#define xx first.first
#define xy first.second
#define yx second.first
#define yy second.second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())-1
#define f(i,a,b) for(int i=a;i<=b; i++)
#define fr(i,a,b) for(int i=a;i<=b; i++)
#define frr(i,a,b) for(int i=a;i>=b; i--)
#define frv(i,a)  for(int i=0;i<a.size();i++)
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;

#define md 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29
#define mx 300003

typedef pair<int ,int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////
vector<int>all[mx+2];
vector<int >co[mx+2];
int ans[mx+2];

int ara[mx+2];
int cn;
void go(int cur,int prev)
{
    cn++;
    for(int i=0;i<co[cur].size();i++)
    {
        int c=ans[co[cur][i]];
        if(c!=0)
        {
            ara[c]=cn;
        }
    }
    int cc=1;

    for(int i=0;i<co[cur].size();i++)
    {
        if(ans[co[cur][i]]==0)
        {
            for(;ara[cc]==cn;cc++);

                ans[co[cur][i]]=cc++;

        }
    }
    for(int i=0;i<all[cur].size();i++)
    {
        int nxt=all[cur][i];
        if(nxt!=prev)
        {
            go(nxt,cur);
        }
    }

}
int main()
{
    int n,m;
    I2(n,m);
    for(int i=0;i<n;i++)
    {
        int x;
        I(x);
        for(int j=0;j<x;j++)
        {
            int y;
            I(y);
            y--;
            co[i].PB(y);
        }
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        I2(x,y);
        x--,y--;
        all[x].PB(y);
        all[y].PB(x);
    }
    go(0,-1);
    int an=0;
    for(int i=0;i<m;i++)
    {
        an=max(an,ans[i]);
    }
    
    if(an==0)PI(1),NL;
    else PI(an),NL;
    for(int i=0;i<m;i++)
    {
        if(i>0)PC(" ");

        if(ans[i]==0)PI(1);
        else
        PI(ans[i]);
    }
    NL;

    return 0;
}
