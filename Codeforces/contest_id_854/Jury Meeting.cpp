/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
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

#define md 1000000007ll
#define  mx 3000000
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

int main()
{
    int n,m,k;
    I3(n,m,k);
    int a[5];
    pair<int,P> ar[m+2],br[m+2];
    int l=0,l1=0;
    fr(i,1,m)
    {
        fr(j,1,4)I(a[j]);
        if(a[2]==0)br[++l1]=mk(a[1],mk(a[4],a[3]));
        else ar[++l]=mk(a[1],mk(a[4],a[2]));
    }

    sort(br+1,br+l1+1);
    int co[n+2];
    SET(co);
    pair<ll,ll>  cost[m+2];
    int sz=0;

    ll res=0;
    int koyta=0;
    frr(j,l1,1)
    {
        if(co[br[j].yy]==0)
        {
            koyta++;
            co[br[j].yy]=br[j].yx;
            res+=br[j].yx;
        }
        if(co[br[j].yy]>br[j].yx)
        {
            res-=(co[br[j].yy]-br[j].yx);
            co[br[j].yy]=br[j].yx;
        }
        if(koyta==n)cost[++sz]=mk(br[j].x,res);

    }
    sort(cost+1,cost+sz+1);
    sort(ar+1,ar+l+1);

    SET(co);
    res=0;
    koyta=0;
    ll ans=2e18;
    fr(j,1,l)
    {
        if(co[ar[j].yy]==0)
        {
            koyta++;
            co[ar[j].yy]=ar[j].yx;
            res+=ar[j].yx;
        }
        if(co[ar[j].yy]>ar[j].yx)
        {
            res-=(co[ar[j].yy]-ar[j].yx);
            co[ar[j].yy]=ar[j].yx;
        }
        if(koyta==n)
        {
            int in=lower_bound(cost+1,cost+sz+1,mk((ll)ar[j].x+k+1,(ll)-1))-cost;
            if(in<=sz)
            {
                ans=min(ans,res+cost[in].y);
            }

        }

    }
    if(ans>=2e18)PI(-1),NL;
    else PL(ans),NL;



    return 0;

}
