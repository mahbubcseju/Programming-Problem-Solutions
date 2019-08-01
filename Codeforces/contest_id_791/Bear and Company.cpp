/********************************
*MAHBUBCSEJU                    *
*CSE 22                         *
*JAHANGIRNAGAR UNIVERSITY       *
*TIMUS:164273FU                 *
*UVA>>LIGHTOJ>>HUST:mahbubcseju */
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <deque>
#include <climits>
#include <complex>
#include <bitset>
#include <limits>
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
#define mx 76
#define md 23377788ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int,int>P;
//////////////////////////
/////////////////////////

int dp[mx+2][mx+2][mx+2][2];
int n;
char a[mx+2];

int ar[mx+2];
int cnt;
int go(int v,int k,int x,bool fl) {

    if(v+k+x==n)return 0;

    int &ret=dp[v][k][x][fl];

    if(ret!=-1)return ret;

    ret=10000000;
    cnt++;

    int cnv=v,cnk=k,cnx=x;
    for(int i=1; i<=n; i++) {
        if(cnv&&a[i]=='V') {
            cnv--;
            ar[i]=cnt;
        }
        if(cnk&&a[i]=='K') {
            cnk--;
            ar[i]=cnt;
        }
        if(cnx&&a[i]=='X') {
            cnx--;
            ar[i]=cnt;
        }
    }

    int costv=0,costk=0,costx=0;
    bool flv=0,flk=0,flx=0;
    fr(i,1,n) {
        if(ar[i]==cnt)continue;
        if(a[i]=='V') {
            flv=1;
        }
        else if(flv==0)costv++;
        if(a[i]=='K') {
            flk=1;
        } else if(flk==0)costk++;
        if(a[i]=='X') {
            flx=1;
        } else if(flx==0)costx++;
    }
   // if(v==1&&k==0&&x==0)cout<<costv<<" "<<costk<<" "<<costx<<" "<<ret<<endl;
    if(flv)ret=min(ret,costv+go(v+1,k,x,1));
  // // cout<<v<<" "<<k<<" "<<x<<" "<<ret<<endl;
   // if(v==1&&k==0&&x==0)cout<<costv<<" "<<costk<<" "<<costx<<" v"<<ret<<endl;
    if(!fl&&flk)ret=min(ret,costk+go(v,k+1,x,0));
    // if(v==1&&k==0&&x==0)cout<<costv<<" "<<costk<<" "<<costx<<"k "<<ret<<endl;
    if(flx) ret=min(ret,costx+go(v,k,x+1,0));
    //if(v==1&&k==0&&x==0)cout<<costv<<" "<<costk<<" "<<costx<<" x"<<ret<<endl;
  //  cout<<ret<<endl;

    return ret;
}
int main() {
    I(n);
    SC("%s",a+1);

    fr(i,1,n)if(a[i]=='V'||a[i]=='K') {}
    else a[i]='X';
    SETR(dp);
    PI(go(0,0,0,0));
    NL;


    return 0;
}
