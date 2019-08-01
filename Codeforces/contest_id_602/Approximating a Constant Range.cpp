/*********************************
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
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define D double
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
#define F(I1,a,b) for(int I1=a;I1<=b;I1++)
#define FR(I2,a,b) for(int I2=a;I2>=b;I2--)
#define FL(J,a,b) for(long long J=a;J<=b;J++)
#define FLR(J1,a,b) for(long long J1=a;J1>=b;J1--)
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
#define PB push_back
#define xx first
#define yy second
#define SC scanf
#define PC printf
#define NL printf("\n")
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
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
template <class T> inline T MDINV(T a, T M)
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

template<typename T> T in()
{
    char ch;
    T n = 0;
    bool ng = false;
    while (1)
    {
        ch = getchar();
        if (ch == '-')
        {
            ng = true;
            ch = getchar();
            break;
        }
        if (ch >= '0' && ch <= '9') break;
    }
    while (1)
    {
        n = n * 10 + (ch - '0');
        ch = getchar();
        if (ch < '0' || ch > '9')   break;
    }
    return (ng ? -n : n);
}
typedef pair<ll, ll >P;
typedef vector<int>V;
#define mx 100000
#define md 1000000000000007ll
#define mx1 (1<<25)
#define mx2 (1<<15)

/////////////////////////////
////////////////////////////
ll a[mx+3];
ll ma[mx*5][3];
void build(ll in,ll s,ll e)
{
    if(s==e)
    {
        ma[in][0]=a[s];
        ma[in][1]=a[s];
        return;
    }
    ll mid=(s+e)/2;
    build(in*2,s,mid);
    build(in*2+1,mid+1,e);
    ma[in][0]=min(ma[in*2][0],ma[in*2+1][0]);
    ma[in][1]=max(ma[in*2][1],ma[in*2+1][1]);
}
ll query(ll in,ll s,ll e,ll st,ll en,ll op)
{
    if(s>=st&&e<=en)
    {
        return ma[in][op];
    }
    ll mid=(s+e)/2;
    if(mid>=en){
        return query(in*2,s,mid,st,en,op);
    }
    else if(st>mid)
    {
        return query(in*2+1,mid+1,e,st,en,op);
    }
    else
    {
        if(op==0)return min(query(in*2,s,mid,st,mid,op),query(in*2+1,mid+1,e,mid+1,en,op));
     else   return max(query(in*2,s,mid,st,mid,op),query(in*2+1,mid+1,e,mid+1,en,op));
    }
}


int main()
{

    ll n;
    L(n);
    for(ll i=1; i<=n; i++)
    {
        L(a[i]);
    }
    build(1,1,n);
    ll res=0;
    for(ll i=1;i<=n;i++)
    {

        ll lo=i;
        ll hi=n;
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            ll mo=query(1,1,n,i,mid,1)-query(1,1,n,i,mid,0);
            if(mo<=1)
            {
                lo=mid+1;
                res=max(res,mid-i+1);

            }
            else hi=mid-1;
        }
       // if(res==10)PI(i);
    }
    PL(res);


    return 0;
}
