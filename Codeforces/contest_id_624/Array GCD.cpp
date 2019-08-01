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
#define maxp 2e18

typedef pair<ll,ll> P;

////////define value/////
int pr[mx+2],sz;
bool fl[mx+2];

void seive() {

    for(int i=2; i<=mx; i++) {
        if(fl[i]==0) {
            pr[++sz]=i;
            for(int j=i*2; j<=mx; j+=i) {
                fl[j]=1;
            }
        }
    }
}
set<int>st;
void kor(int n) {
    for(int i=1; pr[i]*pr[i]<=n&&i<=sz; i++) {
        if(n%pr[i]==0) {
            st.insert(pr[i]);
            while(n%pr[i]==0)n/=pr[i];

        }
    }
    if(n>1)st.insert(n);
}
 ll dp[3][60+2][2];
int main() {
    int n,a,b;
    I3(n,a,b);
    int ar[n+2];
    for(int i=1; i<=n; i++)I(ar[i]);

    seive();
    kor(ar[1]);
    kor(ar[1]+1);
    kor(ar[1]-1);
    kor(ar[n]);
    kor(ar[n]+1);
    kor(ar[n]-1);
    int a1[st.size()+2];
    set<int>::iterator it;
    sz=0;
    for(it=st.begin(); it!=st.end(); it++) {
        a1[++sz]=(*it);

    }



    //


      ll dp1[n+2][sz+2];
    SET(dp1);
    for(ll i=1; i<=n; i++) {
        for(ll j=1; j<=sz; j++)dp1[i][j]=maxp;
    }
    //PL(dp1[n][1]);
     ll res=maxp;
    for(ll i=n; i>=1; i--) {
        for(ll j=1; j<=sz; j++) {
            if(ar[i]%a1[j]==0) {
                dp1[i][j]=min(dp1[i][j],dp1[i+1][j]);

            }
            if((ar[i]+1)%a1[j]==0||(ar[i]-1)%a1[j]==0) {
                dp1[i][j]=min(dp1[i][j],dp1[i+1][j]+b);
            }

            res=min(res,dp1[i][j]+(i-1)*a);
        }
    }

    //
//
//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<=sz; j++ ) {
//            dp[i][j][0]=dp[i][j][1]=maxp;
//        }
//    }

    SET(dp);




    int op=0;

    for(int i=1; i<=n; i++) {
            op^=1;
        for(int j=1;j<=sz;j++)dp[op][j][0]=dp[op][j][1]=maxp;
        for(int j=1; j<=sz; j++) {
            if(ar[i]%a1[j]==0) {
                dp[op][j][0]=min(dp[op][j][0],dp[op^1][j][0]);

            }
            if((ar[i]+1)%a1[j]==0||(ar[i]-1)%a1[j]==0) {
                dp[op][j][0]=min(dp[op][j][0],dp[op^1][j][0]+(ll)b);
            }
            dp[op][j][1]=min(dp[op][j][1],dp[op^1][j][0]+a);
            dp[op][j][1]=min(dp[op][j][1],dp[op^1][j][1]+a);
            if(dp[op][j][0]<maxp) res=min(res,dp[op][j][0]+(ll)(n-i)*(ll)a);
        res=min(res,dp1[i][j]+dp[op^1][j][1]);


        }
    }

//      for(ll i=1;i<=sz;i++)dp[n+1][i][0]=0;
//    for(ll i=n; i>=1; i--) {
//            for(ll j=1;j<=sz;j++)dp[i][j][0]=maxp;
//        for(ll j=1; j<=sz; j++) {
//            if(ar[i]%a1[j]==0) {
//                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]);
//
//            }
//            if((ar[i]+1)%a1[j]==0||(ar[i]-1)%a1[j]==0) {
//                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+b);
//            }
//
//            res=min(res,dp[i][j][0]+dp[i-1][j][1]);
//        }
//    }
    PL(res);



    return 0;
}
