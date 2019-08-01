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
//#define pi 2.0*acos(0.0)
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
#define mx 300000ll
#define md 23377788ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int,int >P;
//////////////////////////
/////////////////////////

int main() {
    int n,m;
    I2(n,m);
    int ar[4][n+2];

    int a[4];
    SET(a);
    for(int i=1; i<=n; i++) {
        int x,y;
        I2(x,y);
        ar[x][++a[x]]=y;
    }

    for(int i=1; i<=3; i++) {
        sort(ar[i]+1,ar[i]+a[i]+1);
        reverse(ar[i]+1,ar[i]+a[i]+1);
    }
    ll cum[4][n+3];

    SET(cum);
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            cum[i][j]=cum[i][j-1]+ar[i][j];
        }
    }

    ll res=0;


    for(int i=0;i<=m;i++)
    {
        ll co=m-i;
        int  kop=co/3;
        ll ans=cum[3][min(kop,a[3])];
        ll ansnxt=0;

        int lo=0,hi=min(a[1],i);
        int kol=hi;

        for(int j=1;j<=50;j++)
        {
            int mid1=lo+(hi-lo)/3;
            int mid2=hi-(hi-lo)/3;

            ll anm1=cum[1][mid1]+cum[2][min(a[2],(i-mid1)/2)];
            ll anm2=cum[1][mid2]+cum[2][min(a[2],(i-mid2)/2)];
            if(anm1>anm2)
            {
                hi=mid2;
            }
            else lo=mid1;
        }
        for(int j=max(0,lo-20);j<=min(hi+20,kol);j++)
        {
            ansnxt=max(ansnxt,cum[1][j]+cum[2][min(a[2],(i-j)/2)]);
        }
        res=max(res,ans+ansnxt);
    }

    PL(res),NL;








    return 0;
}
