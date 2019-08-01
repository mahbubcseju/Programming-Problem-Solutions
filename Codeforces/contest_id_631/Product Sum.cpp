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
#define mx 200000
#define md 1000000007
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
ll a[mx+2];
int n;
ll sum=0;
ll cum[mx+2];
ll check(ll in,ll mid) {
    ll res= sum;
    res=res-a[in]*in;
    res+=a[in]*mid;


    if(mid<in) {
        ll cu=cum[in-1]-cum[mid-1];
        res+=cu;
    } else if(mid>in) {
        ll cu=cum[mid]-cum[in];
        res-=cu;
    }

    return res;

}

int main() {

    I(n);
    cum[0]=0;

    for(ll i=1; i<=n; i++) {
        L(a[i]);
        sum+=a[i]*i;
        cum[i]=cum[i-1];
        cum[i]+=a[i];
    }
ll ans=-1e18;
    for(ll i=1; i<=n; i++) {
        ll lo=1;
        ll hi=n;
        for(ll j=1;j<=100;j++) {
            ll mid1=(lo+(hi-lo)/3);
            ll mid2=(hi-(hi-lo)/3);
            ll res1=check(i,mid1);
            ll res2=check(i,mid2);
            if(res1>res2)
            {
                hi=mid2;
            }
            else lo=mid1;

        }
        lo=max(lo-20,1ll);
        hi=min(hi+20,(ll)n);
        for(ll j=lo;j<=hi;j++)ans=max(ans,check(i,j));
    }

PL(ans);


    return 0;
}
