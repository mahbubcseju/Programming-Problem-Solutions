
/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju *
********************************/
#include<cfloat>
#include<climits>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define I int
#define ll long long int
#define ull unsigned long long int
#define D double
#define SL(a) scanf("%d",&a)
#define SL2(a,b) scanf("%d%d",&a,&b)
#define SL3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define S(a) scanf("%lld",&a)
#define S2(a,b) scanf("%lld%lld",&a,&b)
#define S3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PL(a) printf("%d\n",a)
#define P(a) printf("%lld\n",a)
#define PT(t) printf("Case %lld: ",t)
#define FL(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FLR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define F(J,a,b) for(long long J=a;J<=b;J++)
#define FR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB(a) push_back(a)
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
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
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T MDINV(T a, T M)
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
#define md 1000000007ll
#define mx 10000000000000ll
typedef pair<ll , ll >P;

////////define value/////
int main()
{
    ll n;
    S(n);
    ll a[n+4];

    for(ll i=2; i<=n+1; i++)
    {
        S(a[i]);
    }

    ll b[n+4];
    SETR(b);
    ll val[n+4];
    SET(val);
    ll res=1;
    for(ll i=2; i<=n+1; i++)
    {
        val[i]=1;
        ll x=a[i];
        if(b[x]==-1&&x!=1)
        {
            b[x]=i;
        }
        else if(x!=1)
        {
            ll ptr=i;
            while(a[ptr]!=1)
            {
                ll x=a[ptr];
                ll y=b[x];
                if(y==ptr)
                {
                    if(val[x]==val[ptr])break;
                    val[x]=max(val[x],val[ptr]);
                    res=max(res,val[x]);
                }
                else
                {
                    if(val[ptr]+1<=val[x])
                    {
                        break;
                    }
                    else
                    {
                        ll x1=val[y]+1;
                        ll x2=val[ptr]+1;
                        if(x1<x2)
                        {
                            b[x]=ptr;
                            ll lo=val[x];
                            lo=max(lo,val[y]+1);
                            lo=max(lo,val[ptr]);
                            if(lo==val[x])
                            {
                                break;
                            }
                            val[x]=lo;
                            res=max(res,val[x]);
                        }
                        else
                        {
                            b[x]=y;
                            ll lo=val[x];
                            lo=max(lo,val[ptr]+1);
                            lo=max(lo,val[y]);
                            if(lo==val[x])
                            {
                                break;
                            }
                            val[x]=lo;
                            res=max(res,val[x]);
                        }
                    }

                }
                ptr=x;
            }
        }
        PC("%lld ",res);
    }


    return 0;
}
