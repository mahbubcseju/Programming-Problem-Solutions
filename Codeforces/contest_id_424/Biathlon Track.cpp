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
#define IT(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define ITP(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;
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
#define mx 500000
#define md 1000000007
#define maxp 2050180000

typedef pair<int,int> P;

////////define value/////
int main() {

    int n,m,k1,tp,tu,td;
    I3(n,m,k1);
    I3(tp,tu,td);
    int ar[n+2][m+2];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            I(ar[i][j]);
        }
    }
    int dp[m+2][n+2][n+2];
    int dp1[m+2][n+2][n+2];
    SET(dp1);

    SET(dp);
    for(int k=1; k<=m; k++) {
        for(int i=1; i<=n; i++) {
            dp[k][i][i]=dp1[k][i][i]=0;

            for(int j=i+1; j<=n; j++) {
                dp[k][i][j]=dp[k][i][j-1];
                dp1[k][i][j]=dp1[k][i][j-1];

                if(ar[j-1][k]>ar[j][k]) {
                    dp[k][i][j]+=td;
                    dp1[k][i][j]+=tu;
                } else if(ar[j-1][k]<ar[j][k]) {
                    dp[k][i][j]+=tu;
                    dp1[k][i][j]+=td;
                } else {
                    dp[k][i][j]+=tp;
                    dp1[k][i][j]+=tp;
                }

            }
        }
    }
    set< pair<int,int> >ss;
    int  arr[302];
    set< pair<int,int> >::iterator it;
    pair<P,P>xxx;
    int an=maxp;
    for(int i=1; i<=n; i++) {
        for(int j=i+2; j<=n; j++) {
            SET(arr);
            ss.clear();
            for(int k=2; k<=m; k++) {
                arr[k]=arr[k-1];
                if(ar[i][k]>ar[i][k-1])arr[k]+=tu;
                else if(ar[i][k]<ar[i][k-1])arr[k]+=td;
                else arr[k]+=(tp);
                if(ar[j][k]<ar[j][k-1])arr[k]+=tu;
                else if(ar[j][k]>ar[j][k-1])arr[k]+=td;
                else arr[k]+=(tp);
            }
            ss.insert(mk(arr[m]+dp[m][i][j],m));
            for(int k=m-2; k>=1; k--) {
                int ans=k1-dp1[k][i][j]+arr[k];
                it=ss.lower_bound(mk(ans,0));
                if(it!=ss.end()) {
                    pair<int,int>px;
                    px=(*it);
                    int af=px.x-arr[k]+dp1[k][i][j];
                    if(abs(af-k1)<an) {
                        an=abs(af-k1);
                        xxx=mk(mk(i,k),mk(j,px.y));
                    }

                }
                if(it!=ss.begin()) {
                    it--;
                    pair<int,int>px;
                    px=(*it);
                    int af=px.x-arr[k]+dp1[k][i][j];
                    if(abs(af-k1)<an) {
                        an=abs(af-k1);
                        xxx=mk(mk(i,k),mk(j,px.y));
                    }
                }
                ss.insert(mk(arr[k+1]+dp[k+1][i][j],k+1));
            }

        }
    }
    //cout<<an<<endl;
    cout<<xxx.xx<<" "<<xxx.xy<<" "<<xxx.yx<<" "<<xxx.yy<<endl;

    return 0;
}
