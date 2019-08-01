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
#define mx 100000
#define md 1000000007
#define maxp 2050180000

typedef pair<ll,ll> P;

////////define value/////
int main() {
    int n,b;
    I2(n,b);
    P a[n+2];
    for(ll i=1; i<=n; i++) {
        L2(a[i].x,a[i].y);
    }

    a[0]=mk(0,0);
    ll st=0;
    ll en=0;
    ll in=0;
    ll ans[n+2];
    SETR(ans);
    queue<int>q;

    for(int i=1; i<=n; i++) {
        ll st1=a[i].x;
        if(st1<=en&&q.size()<b) {
            q.push(i);
        }

        else if(st1>en) {

           // ans[in]=en+1;
            q.push(i);
            int f=q.front();
            q.pop();
           // cout<<f<<endl;
            if(a[f].x>en) {
                st=a[f].x;
                en=a[f].x+a[f].y-1;

            } else {
                st=en+1;
                en=st+a[f].y-1;
            }

            in =f;
            ans[in]=en+1;


        }
    }
   // cout<<q.size()<<endl;

    while(!q.empty())
    {

        //ans[in]=en+1;
        int f=q.front();
        q.pop();
        if(a[f].x>en) {
                st=a[f].x;
                en=a[f].x+a[f].y-1;

            } else {
                st=en+1;
                en=st+a[f].y-1;
            }
            in =f;
            ans[in]=en+1;
            if(q.size()==0)ans[in]=en+1;

    }
    for(int i=1; i<=n; i++) {
        printf("%lld ",ans[i]);
    }


    return 0;
}
