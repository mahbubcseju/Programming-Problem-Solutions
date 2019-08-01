
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
#define mx 100000
#define md 1000000007
#define maxp 2050180000

typedef pair<int,int> P;

////////define value/////
int main()
{
    ll n,a,b,t;
    L2(n,a);
    L2(b,t);
    char ch[2*n+2];
    SC("%s",ch+1);
//    strcat(ch+1,ch+1);
   // cout<<(ch+1)<<endl;
   int sz=n;
   for(int i=1;i<=n;i++)ch[++sz]=ch[i];
   ch[++sz]='\0';
    ll dp[n*2+2];
    SET(dp);

    for(int j=n+1;j<=2*n;j++)
    {
        if(j!=n+1)
        {
        dp[j]=a;
        dp[j]+=dp[j-1];
        }
        if(ch[j]=='w')dp[j]+=b;
        dp[j]++;

    }
    ll dp1[n*2+2];
    SET(dp1);
    for(int j=n+1;j>=1;j--)
    {
          if(j!=n+1)
        {
        dp1[j]=a;
        dp1[j]+=dp1[j+1];
        }
        if(ch[j]=='w')dp1[j]+=b;
        dp1[j]++;
        //cout<<dp1[j]<<endl;
    }


    ll res=0;
    for(ll i=n+1;i<=2*n;i++)
    {
        if(dp[i]<=t)
        {
            ll sum=i-(n+1)+1;
            ll ans=t-dp[i];
            ans-=(i-n-1)*a;
            if(ans>0)
            {
                ll lo=1,hi=n;
                ll x=n+1;
                while(lo<=hi)
                {
                    ll mid=(lo+hi)/2;
                    if(dp1[mid]-dp1[n+1]<=ans){
                        hi=mid-1;
                        x=mid;
                    }
                    else  lo=mid+1;
                }
                sum+=(n+1-x);
            }
            res=max(res,sum);
            if(res>n)res=n;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(dp1[i]<=t)
        {
            ll sum=(n+1)-i+1;
            ll ans=t-dp1[i];
            //cout<<i<<" "<<dp1[i]<<endl;
            ans-=(n+1-i)*a;
            //cout<<ans<<endl;
            if(ans>0)
            {
                ll lo=n+2,hi=2*n;
                ll x=n+1;
                while(lo<=hi)
                {
                    ll mid=(lo+hi)/2;
                    if(dp[mid]-dp[n+1]<=ans){
                        lo=mid+1;
                        x=mid;
                    }
                    else  hi=mid-1;
                }
                sum+=x-n-1;
            }
            res=max(res,sum);
            if(res>n)res=n;
        }

    }
    PL(res);


    return 0;
}
