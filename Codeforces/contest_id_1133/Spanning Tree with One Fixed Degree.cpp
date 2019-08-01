#include <iostream>
#include <algorithm>
#include <string>
#include  <queue>
#include <vector>
#include  <cstdio>
#include <cstring>
#include <bits/stdc++.h>

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
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define Endl "\n"
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T mul(T p, T e, T M)
{
    ll ret = 0;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M)ret-=M;
        if(p>=M)p-=M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}


template <class T>bool ISLEFT(T a, T b, T c)
{
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 200004
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  200007
///////////////////////////
///////////////////////////
////////define value/////



int par[mx+2];

int find(int u)
{
    if(par[u]==u)return u;

    return par[u]=find(par[u]);
}
vector<int >ad[mx+2];
int vis[mx+2];
//int ar[mx+2];
vector<int>v;

int main()
{

    int n,m,k;
    I3(n,m,k);


    for(int i=1; i<=n; i++)par[i]=i;
    for(int i=1; i<=m; i++)
    {

        int x,y;
        I2(x,y);

        if(min(x,y)>1)
        {
            int u=find(x);
            int v=find(y);
            if(u!=v)
            {
                par[x]=y;
                ad[x].PB(y);
                ad[y].PB(x);
            }
        }
        else v.push_back(max(x,y));


    }

    if(v.size()<k)
    {
        PC("NO\n");

        return 0;
    }
    memset(par,0,sizeof par);
    int cnt=0;
    queue<int>q;
    for(int i=0; i<v.size(); i++)
    {


        int x=v[i];
        par[x]=1;
        if(vis[x]==0)
        {

            cnt++;

            q.push(x);
            vis[x]=1;
            while(!q.empty())
            {
                int f=q.front();
                q.pop();

                for(int j=0; j<ad[f].size(); j++)
                {
                    int f1=ad[f][j];
                    if(vis[f1]==0)
                    {
                        vis[f1]=1;
                        q.push(f1);
                    }
                }
            }
        }

    }

    if(cnt>k)
    {
        PC("NO\n");

        return 0;
    }
    cnt=k-cnt;
    memset(vis,0,sizeof vis);
    PC("YES\n");

   // queue<int>q;
    for(int i=0; i<v.size(); i++)
    {


        int x=v[i];

        if(vis[x]==0)
        {
            PC("1 %d\n",x);


            q.push(x);
            vis[x]=1;
            while(!q.empty())
            {
                int f=q.front();

                // cout<<x<<" "<<f<<endl;
                q.pop();

                for(int j=0; j<ad[f].size(); j++)
                {
                    int f1=ad[f][j];
                    if(vis[f1]==0)
                    {
                        if(par[f1]==0)PC("%d %d\n",f,f1);
                        else if(cnt)
                        {
                            PC("1 %d\n",f1);
                            cnt--;
                        }
                        else PC("%d %d\n",f,f1);
                        vis[f1]=1;
                        q.push(f1);
                    }
                }
            }
        }

    }




    return 0;
}
