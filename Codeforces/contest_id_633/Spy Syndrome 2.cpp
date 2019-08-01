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
#define mx 10000
#define md 1000000007ll
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
#define mx 10000

char a[mx+3];
char b[mx+3];
struct   data
{
    int x[27];
    int info;
    data()
    {
        memset(x,-1,sizeof x);
        info=0;
    }


};

data ar[mx*100+2];
int sz=0;
void insert1(int cs)
{
    int cur=0;
    int l=strlen(b+1);
    for(int i=1; i<=l; i++)
    {
        char ch=tolower(b[i]);
        if(ar[cur].x[ch-96]==-1)
        {
            ar[cur].x[ch-96]=++sz;
        }
        cur=ar[cur].x[ch-96];

    }
    ar[cur].info=cs;
}


int main()
{
    int n;
    I(n);
    scanf("%s",a+1);
    int m;
    I(m);
    int cs=0;
    vector< string > v;
    v.push_back("000");
    while(m--)
    {
        scanf("%s",b+1);
        v.push_back(b+1);
        insert1(++cs);

    }
    int dp[n+2];
    memset(dp,0,sizeof dp);
    dp[0]=1;
    int l=strlen(a+1);
    for(int i=1; i<=l; i++)
    {
        int x=i-(1000+6);
        int cur=0;
        for(int j=i; j>=max(1,x); j--)
        {
            int x1=a[j]-96;
            if(ar[cur].x[x1]==-1)break;
            cur=ar[cur].x[x1];
            if(ar[cur].info>0&&dp[j-1]>0)
            {
                dp[i]=ar[cur].info;
                break;
            }
        }
    }
    vector<string >v1;

    for(int i=l; i>=1;)
    {
        int x=dp[i];
        int le=v[x].size();
        i-=le;
        v1.push_back(v[x]);

    }
    int sz=v1.size();
    for(int i=sz-1; i>=0; i--)
    {
        if(i>0)
            cout<<v1[i]<<" ";
        else cout<<v1[i];
    }




    return 0;
}
