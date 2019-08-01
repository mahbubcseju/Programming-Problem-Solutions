
/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
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
template <class T> inline T BM(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T mdINV(T a, T M) {
    return BM(a, M - 2, M);
}
template <class T> inline T PW(T p, T e) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p);
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
template <class T>bool ISLEFT ( T a, T b, T c) {
    if (((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1; //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}
#define mx 200004
#define MD 100000007ll
typedef vector<ll>V;
typedef pair<int,int>P;
///////////////
////////////////


#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007

vector<int>v[mx+2];

int dp[mx+2];

int a[mx+2];
vector<int>v1[mx+2];

int ans[mx+2];
void dfs(int u,int p,int cnt,int res) {
    dp[u]=res;
    int lp=v1[u].size();
    int  res1=1;
    for(int j=0; j<lp; j++) {
        int ko=v1[u][j];
        ans[ko]++;
        if(ans[ko]==cnt) {
            res1=max(res1,ko);
        }
        if(ans[ko]>=cnt-1)dp[u]=max(dp[u],ko);
    }
    for(int i=0; i<v[u].size(); i++) {
        int x=v[u][i];
        if(x==p)continue;
        dfs(x,u,cnt+1,res1);
    }

    for(int j=0; j<lp; j++) {
        int ko=v1[u][j];
        ans[ko]--;

    }
}
int main() {

    int n;
    I(n);

    fr(i,1,n) {
        I(a[i]);
        int l=sqrt(a[i]);
        for(int j=2; j<=l; j++) {
            if(a[i]%j==0) {
                v1[i].PB(j);
                int lo=a[i]/j;
                if(lo!=j)v1[i].PB(lo);
            }
        }
        v1[i].PB(a[i]);

    }

    fr(j,1,n-1) {
        int x,y;
        I2(x,y);
        v[x].PB(y);
        v[y].PB(x);
    }


    dfs(1,0,1,1);

    fr(i,1,n) {
        if(i>1)PC(" ");
        dp[i]=max(dp[i],1);
        PI(dp[i]);
    }
    NL;

    return 0;
}
