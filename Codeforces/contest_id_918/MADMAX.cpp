#include<bits/stdc++.h>
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
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T mul(T p, T e, T M) {
    ll ret = 0;
    for(; e > 0; e >>= 1) {
        if(e & 1) ret = (ret + p) ;
        p = (p + p) ;
        if(ret>=M)ret-=M;
        if(p>=M)p-=M;
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


template <class T>bool ISLEFT(T a, T b, T c) {
    if(((a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy)) < 0.0)return 1;  //Uporer dike //A,b,c, x okkher ordera sorted
    else return 0;
}

#define md 1000000007ll
#define  mx 2000004
#define base 193ll

typedef pair<ll,ll >P;
//////////////////////////
////////////////////////
int dp[102][102][200][2];
vector< pair<int,char > >v[102];


int DP(int i,int j,int k,bool fl)
{
    int &ret=dp[i][j][k][fl];
    if(ret!=-1)return ret;
    ret=0;
    int u=i;
    if(fl)u=j;

    for(int j1=0;j1<v[u].size();j1++)
    {
        int x=v[u][j1].x;
        int ch=v[u][j1].y;
        if(ch>=k)
        {
            if(fl==0)
            ret=max(ret,1^DP(x,j,ch,fl^1));
            else ret=max(ret,1^DP(i,x,ch,fl^1));
        }
    }
    //cerr<<i<<" "<<j<<" "<<k<<" "<<fl<<" "<<ret<<Endl;
    return ret;
}
int main()
{
    int n,m;
    I2(n,m);
    fr(i,1,m)
    {
        int x,y;
        char c[2];
        I2(x,y);
        SC("%s",c);
        v[x].PB(mk(y,c[0]));
       // v[y].PB(mk(x,c[0]));
    }
    SETR(dp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int f=DP(i,j,0,0);
            if(f)PC("A");
            else PC("B");
        }
        NL;
    }

    return 0;
}
