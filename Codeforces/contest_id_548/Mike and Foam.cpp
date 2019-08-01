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

typedef pair<int ,int > P;

////////define value/////
int ar[mx*5];
int pr[1002];
bool vis[1002];
int sz;
int n;
void seive() {

    for(int i=2; i<=1000; i++) {

        if(vis[i]==0) {
            pr[++sz]=i;
            for(int j=i*2; j<=1000; j+=i) {
                vis[j]=1;
            }

        }
    }
    // for(int i=1;i<=25;i++)PI(pr[i]);
}
int a[mx+2];
vector<int>v[mx+2];
void fac() {

    for(int i=1; i<=n; i++) {
        int x=a[i];
        for(int j=1; j<=sz&&pr[j]*pr[j]<=x; j++) {
            if(x%pr[j]==0) {
                v[i].PB(pr[j]);
                while(x%pr[j]==0)x/=pr[j];
            }
        }
        if(x>1)v[i].PB(x);

    }

}
int main() {
    seive();

    int m;
    I2(n,m);

    for(int i=1; i<=n; i++) {
        I(a[i]);
    }
    fac();

    bool fl[n+2];
    SET(fl);

    ll res=0;
//    for(int i=1; i<=n; i++) {
//        int l=v[i].size();
//        int  ans=i-1;
//        for(int j=0; j<(1<<l); j++) {
//            int nu=1;
//            for(int k=0; k<l; k++) {
//                if((j&(1<<k)))nu*=v[i][k];
//            }
//            // cout<<i<<" "<<nu<<" "<<ar[nu]<<endl;
//            if(CB(j)%2==1)ans-=ar[nu];
//            else ans+=ar[nu];
//            if(nu!=1)
//                ar[nu]++;
//        }
//        res+=ans;
//    }
    int el=0;
    while(m--) {
        int in;
        I(in);
        int l=v[in].size();
        int  ans=el;
       // cout<<el<<" "<<in<<endl;

        for(int j=0; j<(1<<l); j++) {
            int nu=1;
            for(int k=0; k<l; k++) {
                if((j&(1<<k)))nu*=v[in][k];
            }
            // cout<<i<<" "<<nu<<" "<<ar[nu]<<endl;
            if(CB(j)%2==1)ans-=ar[nu];
            else ans+=ar[nu];
            if(nu!=1) {
                if(fl[in]==0) {
                    ar[nu]++;
                } else {
                    ar[nu]--;
                }
            }
        }
//        if(a[in]==1)ans=el;
//        cout<<ans<<endl;

        if(fl[in]==0) {
            fl[in]=1;

            if(a[in]==1)ans=el;
               el++;
            res+=ans;
        }
         else {
            el--;
            fl[in]=0;
            if(a[in]==1)ans=el;
            res-=ans;
        }
        PL(res);

    }








    return 0;
}
