#include <iostream>
#include <algorithm>
#include <string>
#include  <queue>
#include <vector>
#include  <cstdio>
#include <cstring>
#include<map>
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
#define MX  1000007
#define md 998244353ll
///////////////////////////
///////////////////////////
///

int ar[MX + 2];
ll sum[MX + 2];
ll sum_func(ll x, ll y){
    ll res = PW(x, y + 1) -1;
    return res / (x - 1);
}

void seive(){
    for(int i=1;i<=MX;i++)sum[i] = 1;
    for(int i = 2; i<= MX; i++){
        if(ar[i] == 0){
            for(int j = i; j<=MX;j += i){
                if((j / i) % i ==0)ar[j] = ar[j / i] + 1;
                else ar[j] = 1;
                sum[j] *= sum_func(i, ar[j]);
                if(sum[j] > MX)sum[j] = 0;
            }
        }
    }
}
int ans[MX + 2];

int main() {
    seive();
    for(int i=1;i<=100;i++){
        if(ans[sum[i]] == 0){
            ans[sum[i]] = i;
        }
    }
    int tc;
    I(tc);
    while(tc--){
        int n;
        I(n);
        if(ans[n] == 0)cout<<(-1)<<endl;
        else printf("%d\n", ans[n]);
    }

    return 0;
}