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
///

int tr[mx*3+2];
int ar[mx+2];
void seg(int no,int s,int e)
{
    if(s==e){
        tr[no]=s;
        return ;
    }
    int mid=(s+e)/2;
    seg(no*2,s,mid);
    seg(no*2+1,mid+1,e);
    tr[no]=(ar[tr[no*2]]>ar[tr[no*2+1]])?tr[no*2]:tr[no*2+1];
}
int qu(int no,int s,int e,int st,int en)
{
    if(s>=st&&e<=en)return tr[no];

    int mid=(s+e)/2;
    if(en<=mid)return qu(no*2,s,mid,st,en);
    else if(st>mid)return qu(no*2+1,mid+1,e,st,en);
    else {
            int l=qu(no*2,s,mid,st,mid);int r=qu(no*2+1,mid+1,e,mid+1,en);
            if(ar[l]>ar[r])return l;else return r;
    }
}
int kothay[mx+2];

int n;
ll dp(int s,int e)
{
    if(s==e)return 0;
//    cout<<s<<e<<Endl;

    int k=qu(1,1,n,s,e);
  //  cout<<s<<" "<<e<<" "<<k<<Endl;
    if(k==s)return dp(s+1,e);
    else if(k==e)return dp(s,e-1);

    int f[5];
    if((k-s)<(e-k))
    {
        f[1]=s;
        f[2]=k-1;
        f[3]=k+1;
        f[4]=e;
    }
    else
    {
        f[1]=k+1;
        f[2]=e;
        f[3]=s;
        f[4]=k-1;
    }
    ll res=0;
    for(int j=f[1];j<=f[2];j++)
    {
        int lop=ar[k]-ar[j];
        if(kothay[lop]>=f[3]&&kothay[lop]<=f[4])res++;
    }
    return res+dp(s,k-1)+dp(k+1,e);
}
int main()
{

    I(n);
    fr(i,1,n)
    {
        I(ar[i]);

        kothay[ar[i]]=i;

    }
    seg(1,1,n);
    PL(dp(1,n));


    return 0;
}
