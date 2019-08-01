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

typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007

ll fac[mx+2];
ll sufa[mx+2];
int main()
{
    fac[0]=1;
    sufa[0]=1;
    fr(i,1,mx){fac[i]=(fac[i-1]*i)%md;
    sufa[i]=(sufa[i-1]+fac[i])%md;
    }
    int n;
    I(n);

    int ar[n+2];

    for(int i=1;i<=n;i++)
    {
        I(ar[i]);
    }
    sort(ar+1,ar+n+1);


    P ara[n+2];
    int l=0;

    for(int i=1;i<=n;i++)
    {
        if(ar[i]!=ara[l].x)ara[++l]=mk(ar[i],1);
        else
        {
            ara[l].y++;
        }
    }
    ll res=0;


    ll koyta=ara[l].y;
  ll sum=0;
    for(int j=l-1;j>=1;j--)
    {
//        ll kop=koyta+ara[j].y-2;
//
//        ll ans=((sufa[kop]*(ll)ara[j].y)%md)*(ll)ara[j].x;
//        ans%=md;

       ll ans=((fac[koyta+ara[j].y-1]*(ll)(ara[j].y))%md*(ll)ara[j].x)%md;
   //    ans=(ans*koyta)%md;
//       ll xo=koyta+ara[j].y-1;
//       ll re=fac[xo]*mdINV(fac[koyta],md);
//       re%=md;
//       re=(re*mdINV(fac[ara[j].y-1],md))%md;
//
//       ans=(ans*re)%md;

       // cerr<<ans<<ara[j].y<<" "<<ara[j].x<<Endl;

        koyta+=ara[j].y;
        ll kobe=(fac[n]*mdINV(fac[koyta],md))%md;
        kobe=(kobe*mdINV(fac[n-koyta],md))%md;
        ans=(ans*kobe)%md;
        ans=(ans*fac[n-koyta])%md;
        res=(res+ans)%md;
    }
    PL(res),NL;
//main();

    return 0;
}
