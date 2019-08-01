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
#define mx 200
#define md 1000000007ll
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
int dp[202][202][1002];
int n,k;
int a[mx+2];
int go(int po,int op,int ko) {

    if(po==n+1) {
        if(op==0&&ko>=0)return 1;
        else return 0;
    }
    if(ko<0)return 0;
    int &ret=dp[po][op][ko];
    if(ret!=-1)return ret;
    ret=0;
    int ho=ko-op*(a[po]-a[po-1]);
    // cout<<ho<<endl;
    ret+=go(po+1,op+1,ho);
    if(ret>=md)ret-=md;

    if(op>0)
        {ll ko1=go(po+1,op-1,ho);
        // ll ko1=(ll)go(po+1,op,ho);
    ko1=(ko1*(ll)op)%md;
    ret+=ko1;
    if(ret>=md)ret-=md;
        }
    if(ret>=md)ret-=md;

    ret+=go(po+1,op,ho);
    if(ret>=md)ret-=md;

    ll ko1=(ll)go(po+1,op,ho);
    ko1=(ko1*(ll)op)%md;
    ret=(ret+(int)ko1)%md;;

    return ret;
}
int main() {
    I2(n,k);

    for(int i=1; i<=n; i++)I(a[i]);
    sort(a+1,a+n+1);
    a[0]=a[1];
    SETR(dp);
    int  ans=go(1,0,k);
    PI(ans);


    return 0;
}
