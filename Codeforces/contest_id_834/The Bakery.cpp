/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
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
template <class T> inline T BM(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M)
{
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a, T b, T c)
{
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define mx 35000ll
#define md (1ll<<32ll)
typedef pair<int , int >P;
typedef vector<ll>V;

///////////////////
////////////////////
int n,m;
int  a[mx+2], k;
int  vis[50+2][mx+2];

struct da{

    int in,l,r;
    da()
    {
        in=l=r=0;
    }

};
da tr[mx*44];
int sz;
void update(int pr,int nw,int s,int e,int in,int val)
{
  if(s==e)
  {
      tr[nw].in=tr[pr].in+val;
      return ;
  }

  int mid=(s+e)>>1;

  if(mid>=in)
  {
      tr[nw].r=tr[pr].r;
      tr[nw].l=++sz;
      update(tr[pr].l,tr[nw].l,s,mid,in,val);
  }
  else
  {
       tr[nw].l=tr[pr].l;
      tr[nw].r=++sz;
      update(tr[pr].r,tr[nw].r,mid+1,e,in,val);
  }
  tr[nw].in=tr[tr[nw].l].in+tr[tr[nw].r].in;
}

int qu(int nw,int s,int e,int st,int en)
{
    if(nw==0)return 0;
    if(s>=st&&e<=en)return tr[nw].in;
    if(tr[nw].in==0)return 0;

    int mid=(s+e)>>1;
    if(mid>=en)return qu(tr[nw].l,s,mid,st,en);
    else if(st>mid)return qu(tr[nw].r,mid+1,e,st,en);
    else
    {
        return qu(tr[nw].l,s,mid,st,mid)+qu(tr[nw].r,mid+1,e,mid+1,en);
    }
}
int ind[mx+2];
void hishab(int  s,int  e,int  x,int  y)
{
    if(s>e)
    {
        return;
    }
    int  mid=(s+e)/2;
    int  fl=0;
    int   ret=0;
    int in=min(mid-1,y);
    for(int i=x;i<=in;i++)
    {
        int  res=qu(ind[mid],1,n,i+1,mid)+vis[k][i];
        if(res>=ret)
        {
            ret=res;
            fl=i;
        }
    }
    vis[k+1][mid]=ret;
    if(s==e)return ;
    hishab(s,mid-1,x,fl);
    hishab(mid+1,e,fl,y);
}
int cn[mx+2];
int main()
{

    I2(n,m);

    fr(i,1,n){

        I(a[i]);
    }

    int root=0;

    fr(i,1,n)
    {
        if(cn[a[i]]==0){
            ind[i]=++sz;
           // cout<<i<<" "<<1<<endl;
            update(ind[i-1],ind[i],1,n,i,1);
            cn[a[i]]=i;
        }
        else
        {
           // cout<<cn[a[i]]<<" "<<-1<<endl;
            int lo=++sz;
            update(ind[i-1],lo,1,n,cn[a[i]],-1);
            ind[i]=++sz;
            update(lo,ind[i],1,n,i,1);
            cn[a[i]]=i;

        }
        vis[1][i]=tr[ind[i]].in;
       
    }


    fr(j,2,m)
    {
        k=j-1;
        hishab(1,n,1,n);
    }
    PI(vis[m][n]),NL;

    return 0;
}
