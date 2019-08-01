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
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define F(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
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
using namespace std;
template <class T> inline T BM(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T MDINV(T a,T M)
{
    return BM(a,M-2,M);
}
template <class T> inline T PW(T p,T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret*p);
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
typedef pair<ll ,ll  >P;
////////define value//////////
#define MX 1000000000
#define MD 100000007
int main()
{
    ll n,m;
    S2(n,m);
    P a[m+2];
    for(ll i=1; i<=m; i++)
    {
        S2(a[i].xx,a[i].yy);
    }
    sort(a+1,a+m+1);
    ll res=0;
    for(ll i=1; i<=m; i++)
    {
        if(i==1)
        {
            res=max(res,a[i].xx-1+a[i].yy);
        }
        else
        {
            ll ko=a[i-1].xx;
            ll ko1=a[i].xx;
            if(ko1-ko<abs(a[i-1].yy-a[i].yy))
            {
                PC("IMPOSSIBLE\n");
                return 0;
            }
            ll ops=abs(a[i-1].yy-a[i].yy);
            if(a[i-1].yy>a[i].yy)
            {
                ko-=ops;
            }
            else if(a[i-1].yy<a[i].yy)ko1+=ops;
            ops=min(a[i-1].yy,a[i].yy);
            ll ok=(ko+ko1)/2;
            ok=ok-ko;
            res=max(res,ok+ops);
        }
    }
    res=max(res,n-a[m].xx+a[m].yy);
    PC("%lld\n",res);
    return 0;
}