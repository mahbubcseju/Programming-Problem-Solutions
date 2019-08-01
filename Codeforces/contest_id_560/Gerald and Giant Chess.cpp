
/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
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
#define SZ(a) ((int)a.size())
//#define pi 2.0*acos(0.0)
#define R(a) freopen(a, "r", stdin);
#define W(a) freopen(a, "w", stdout);
#define CB(x) __builtin_popcount(x)
#define STN(a) stringtonumber<ll>(a)
#define lol printf("BUG\n")
#define mk make_pair
using namespace std;
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}
template <class T>string NTS ( T Number ) {
    stringstream ss;
    ss << Number;
    return ss.str();
}
template <class T>T stringtonumber ( const string &Text ) {
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
template <class T>bool ISLEFT ( T a,T b,T c) {
    if(((a.xx-b.xx)*(b.yy-c.yy)-(b.xx-c.xx)*(a.yy-b.yy))<0.0)return 1;//Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 300000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<ll ,ll > P;

////////define value/////
ll fac[mx+2];
ll qu(ll x,ll y)
{
   // cout<<x<<" "<<y<<endl;
    ll res=fac[x+y];
    //cout<<res<<endl;
    return (res*(mdINV((fac[x]*fac[y])%md,md))%md)%md;
}
int main()
{
    fac[0]=1;
    for(ll i=1;i<=mx;i++)
    {
        fac[i]=(i*fac[i-1])%md;
    }
    ll n,m,k;
    L3(n,m,k);
    P a[k+2];
    for(int _=1;_<=k;_++)
    {
        L2(a[_].x,a[_].y);
    }
   sort(a+1,a+k+1);
   k++;
   a[k]=mk(n,m);
   ll dp[(k+2)];
   SET(dp);
    for(ll i=1;i<=k;i++)
    {
        ll x=(a[i].x-1);
        ll y=(a[i].y-1);
       dp[i]=qu(x,y);
     //cout<<dp[i]<<endl;
       for(ll j=i-1;j>=1;j--)
       {
           if(a[i].x>=a[j].x&&a[i].y>=a[j].y)
           {
               ll op1=abs(a[i].x-a[j].x);
               ll op2=abs(a[i].y-a[j].y);
               ll res=(dp[j]*qu(op1,op2))%md;
               dp[i]-=res;
               dp[i]%=md;
               if(dp[i]<0)dp[i]+=md;

           }
       }
     //  cout<<dp[i]<<endl;
    }
    PL(dp[k]);



    return 0;
}
