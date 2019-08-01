
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
#include<string.h>
#define ll long long int
#define ull unsigned long long int
#define I(a) scanf("%d",&a)
#define I2(a,b) scanf("%d%d",&a,&b)
#define I3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define L(a) scanf("%lld",&a)
#define L2(a,b) scanf("%lld%lld",&a,&b)
#define L3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define PI(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
#define PT(t) printf("Case %d: ",t)
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
template <class T>bool ISLEFT ( T a,T b,T c)
{
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 1000000
#define md 1000000007

#define maxp 1000004
typedef pair<int , int >P;
typedef vector<int >V;

////////define value/////

int main()
{
    ll n;
    L(n);
    if(n==0)
    {
        PC("0 0\n");
        return 0;
    }
    ll lo=0;
    ll hi=6000000000;
    ll sum=0,in=0;
    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        ll res=(mid*3*(2+(mid-1)));
        if(res<=n)
        {
            in=max(mid,in);
            sum=max(res,sum);
            lo=mid+1;
        }
        else hi=mid-1;
    }
    ll co=n-sum;
    if(co==0)
    {
        PC("%lld %lld\n",(in)*2,0ll);
   // lol;
    }
    else if(co==(in+1)*3)
    {
        PC("%lld %lld\n",-(in+1)*2,0ll);
        //lol;
    }

    else
    {
        in++;

        ll op=0;
        if(co<=(in*6)/4)op=1;
        else if(co<=(in*6*2)/4)op=2;
        else if(co<=(in*6*3)/4)op=3;
        else op=4;

        if(co>(in*3)){

            co=(in*6)-co;
        }
        if(op==2||op==3)
        {
            co=(in*3)-co;
        }
        //cout<<co<<endl;\

        ll x=in*2;
        ll y=0;
        ll xo=in;
        if(co<=xo)
        {
            x-=co;
            y+=co*2;
        }
        else

        {
            x-=xo;
            y+=xo*2;
            co-=xo;
            x-=co*2;
        }
        if(op==2)x*=-1;
        else if(op==3){
            x*=-1,y*=-1;
        }
        else if(op==4) {
            y*=-1;
        }

PC("%lld %lld\n",x,y);
    }

    return 0;
}
