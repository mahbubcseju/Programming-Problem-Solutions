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
#define  mx 500000
#define base 193ll

typedef pair<int,int >P;
//////////////////////////
////////////////////////
#define F(i,a,b) for(int i=a;i<b; i++)
#define LL long long
#define MX  2000007
///////////////////////////
///////////////////////////
////////define value/////

ll cum[mx+2];

void up(int i,ll val) {
    while(i<=mx) {
        cum[i]+=val;
        i+=i&-i;
    }
}
ll qu(int i) {
    ll res=0;
    while(i>0) {
        res+=cum[i];
        i-=i&-i;
    }
    return res;
}

int main() {
    ll n,m,k;
    L3(n,m,k);
    ll ar[n+2];
    fr(i,1,n)L(ar[i]);
    ll lo=0,hi=2e18;

    ll res=0;


   ll kop1=0;

   for(int i=1;i<=m;i++)
    kop1+=ar[i];


    while(lo<=hi) {
        ll mid=(lo+hi)>>1;
        SET(cum);
        fr(i,1,n)cum[i]=ar[i];
        bool  fl=0;
        ll ache=k;

        int st=1,en=m;
        ll sum=kop1;

        for(int i=1; i<=n; i++) {
            int in=min(n,i+m);
            int in1=max((ll)1,i-m);
             if(in1>st){sum-=cum[st];
             st++;
             }
             if(in>en)sum+=cum[++en];

            if(sum<mid) {
                ll kop=mid-sum;
                if(kop>ache) {
                    fl=1;
                    break;
                } else {
                    ache-=kop;
                    cum[in]+=kop;
                    sum+=kop;
                }
            }
        }
        if(!fl)
        {
            res=mid;
            lo=mid+1;

        }
         else hi=mid-1;
    }
    PL(res);
    return 0;
}
