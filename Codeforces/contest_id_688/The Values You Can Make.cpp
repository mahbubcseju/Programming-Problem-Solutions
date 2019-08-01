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
#define mx 10000
#define md 1000000007
#define maxp 2050180000

typedef pair<int ,int > P;

////////define value/////
int dp[505][505];
int a[505];
int n,m;
int go(int i,int j) {
    // cout<<j<<endl;
    if(i==n+1){
        if(j==m)return dp[i][j]=1;
        else return dp[i][j]=0;
    }
    if(j>m)return 0;
    if(j==m)return dp[i][j]=1;
    int &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    ret=max(ret,go(i+1,j+a[i]));
    ret=max(ret,go(i+1,j));
    return ret;

}
int ans[505];
bool dp1[505][505][505];
bool  go1(int i,int j,int res) {
    ans[res]=1;
    if(j==m) {
        return 1;
    }
    bool &ret=dp1[i][j][res];
    if(ret!=0)return ret;
    ret=1;
    if(j+a[i]<=m&&dp[i+1][j+a[i]]>=1) {

        ret+=go1(i+1,j+a[i],res+a[i]);
        ret+= go1(i+1,j+a[i],res);
    }
    if(dp[i+1][j]>=1)ret+=go1(i+1,j,res);
    ret=1;

    return ret;


}

int main() {

    I2(n,m);
    for(int i=1; i<=n; i++)I(a[i]);
    sort(a+1,a+n+1);
    SETR(dp);
   int x=go(1,0);
  // if(x==0)lol;

    //SETR(dp1);
    go1(1,0,0);
    int res=0;
    for(int i=0; i<=500; i++)if(ans[i])res++;
    cout<<res<<endl;
    bool fl=0;
    for(int i=0; i<=500; i++) {
        if(ans[i]) {
            if(!fl)PC("%d",i);
            else PC(" %d",i);
            fl=1;
        }
    }
    NL;
    return 0;
}
