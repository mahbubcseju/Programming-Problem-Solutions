#include <iostream>
#include <algorithm>
#include <string>
#include  <queue>
#include <vector>
#include  <cstdio>
#include <cstring>
#include<map>
#include<cmath>
#include<set>
//#include<bits/stdc++.h>
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
 

#define  mx 200004
#define base 193ll
 
typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007
#define md 998244353ll
///////////////////////////
///////////////////////////
///


int ar[10004];
int koy(int n){
    int ans = 0;
    while(n){
        if(n % 2)ans++;
        n /= 2;
    }
    return ans;
}
int main(){

   int n;
   I(n);
   char ar[n+2];
   SC("%s", ar + 1);
   int l = strlen(ar + 1);

   int koto = 0;
   for(int i = 1;i <= n;i++){
       if(ar[i] == '1')koto ++;
   }
   int ans[koto + 2];
   SET(ans);

   for(int i = koto - 1; i <= koto + 1; i++){
       if( i == 0) continue;
       int cur = 0;
       for(int j = 1; j<=n;j++){
           cur = (cur * 2 + ar[j] -'0');
           cur %= i;
       }
       ans[i] = cur;
   }

   for(int i = 1; i <= n;i++){
       int koyta = koto + 1;
       if(ar[i] == '1'){
          ar[i] = '0';
          koyta = koto -1;
       }
       else ar[i] = '1';
       
       if(koyta == 0)PI(0), NL;
       else {
           int kot = BM(2, i - 1, koyta);
           int res = ans[koyta];
           if(ar[i] == '1'){
               res = (res + kot) % koyta;
           }else {
               res = (res -kot) % koyta;
               res = (res + koyta) % koyta;
           }
           int re = 1;
           while(res > 0){
               res %= koy(res);
               re++;
           }
           PI(re),NL;
       }

        if(ar[i] == '1'){
          ar[i] = '0';
       }
       else ar[i] = '1';
   }
    return 0;
}
