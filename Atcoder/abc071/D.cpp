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
#define MX  200007
#define md 998244353ll
///////////////////////////
///////////////////////////
///
int n;
ll DP[52][5][5][5][5];
    char ar[2][100+2];
ll dp(int pos, int fi, int se, int f1, int s1) {
    if(pos == n+1){
        if(f1==0 && s1 == 0){
            return 1;
        }
        return 0;
    }

    ll &ret = DP[pos][fi][se][f1][s1];
    if(ret !=-1 )return ret;
    ret =0;
    if(f1 ==0 && s1==0){
        if(ar[0][pos] == ar[1][pos]){
            for(int j=1;j<=3;j++){
                if(j!=fi && j!=se){
                    ret+= dp(pos + 1, j, j, 0, 0);
                }
            }
        }
        for(int j=1;j<=3;j++){
            for(int k =1; k<=3;k++){
                if(j != fi && k!=se){
                    ret += dp(pos + 1, j, k, j, k);
                }
            }
        }
    }else if(f1 == 0){
        for(int j=1;j<=3;j++){
            if(j!=fi){
                ret+= dp(pos + 1, j, s1, j, 0);
            }
        }
    }else if(se==0){
        for(int j=1;j<=3;j++){
            if(j!=se){
                ret+= dp(pos + 1, f1, j, 0, j);
            }
        }
    }else {
        ret +=dp(pos+1, f1, s1, 0, 0);
    }

    return ret;

}
int main(){

    I(n);

    for(int i=1;i<=2;i++){
        SC("%s", ar[i] + 1);
    }
    SETR(DP);
    cout<<(dp(1, 0, 0, 0, 0))<<endl;

    return 0;
}
