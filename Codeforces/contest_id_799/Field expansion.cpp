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


typedef pair<ll , ll > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////

#define mx 100000

ll h,w,a,b,n;

ll ar[mx+2];
ll mul[mx+2];
ll dp[42][200000][2];
ll go(ll i,ll m,bool fl)
{
    ll x= m;
    ll co=mul[i+1]/m;

    if(fl)swap(x,co);

    if(x*h>=a&&co*w>=b)return (n-i);
    if(i==0)
    {
        return mx*100;
    }

    ll &ret=dp[i][m][fl];
    if(ret!=-1)return ret;

    ret=mx*100;

    if(fl==1)
    {

        if(m*ar[i]*w>=b)return (n-i+1);
        else ret=min(ret,go(i-1,m*ar[i],1));

    }
    else if(co*w>=b)
    {
        if(x*ar[i]*h>=a)return (n-i+1);
        else ret= min(ret,go(i-1,m*ar[i],0));
    }
    else
    {
        //
        ll xo=m*ar[i];
        if(xo*h>=a)ret=min(ret,go(i-1,co,1));
        else ret=min(ret,go(i-1,xo,0));
        ret=min(ret,go(i-1,m,0));
    }

    return ret;
}
int main()
{
    L2(a,b);
    L2(h,w);

    L(n);

    for(ll i=1; i<=n; i++)
        L(ar[i]);


    if(h>=a&&w>=b)
    {

        PI(0),NL;
        return 0;
    }




    sort(ar+1,ar+n+1);

    int x=max(1,(int)n-40);
    int l=0;
    fr(i,x,n)
    {
        ar[i-x+1]=ar[i];
        ++l;
    }

    n=l;
    mul[n+1]=1;
    frr(i,n,1)mul[i]=mul[i+1]*ar[i];

    SETR(dp);

    int ans=0;


    int fl=0;

    if(h>=a)fl=1;
    ans=go(l,1,fl);

    swap(a,b);

    SETR(dp);
    fl=0;
    if(h>=a)fl=1;
    ans=min(ans,(int)go(l,1,fl));

    if(ans>n)ans=-1;
    PI(ans),NL;


    return 0;
}
