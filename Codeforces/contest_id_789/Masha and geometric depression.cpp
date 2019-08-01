
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
#define mx 100000ll
#define md 1000000007
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<ll,ll > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////

int main() {
    ll n,m,l,k;
    L2(n,m);
    L2(l,k);
    ll a[k+2];

    fr(i,1,k)L(a[i]);

    if(abs(n)>l){
        PI(0);
        return 0;
    }

    sort(a+1,a+k+1);
    a[k+1]=2e18;

    int x=lower_bound(a+1,a+k+1,n)-a;
    if(m==1&&a[x]==n)PI(0),NL;
    else if(m==1&&a[x]!=n)PC("inf\n");
    else if(m==-1)
    {
        int xo=lower_bound(a+1,a+k+1,n)-a;
        int yo=lower_bound(a+1,a+k+1,-n)-a;

        if(a[xo]==n&&a[yo]==-n)PI(0),NL;
        else PC("inf"),NL;
    }
    else {
        int cnt=0;
        bool fl=0;
        bool fl1=0;
        ll ko=n;
        if(ko<0)ko*=-1;
        while(ko<=l) {
            int f=lower_bound(a+1,a+k+1,n)-a;
            if(a[f]!=n)cnt++;
            if(n==0) {
                    fl1=1;
                if(a[f]==0)
                fl=1;
                break;
            }
            n*=m;
            ko=n;
            if(ko<0)ko*=-1;
        }
        if(fl1==1)
        {
            if(fl==1)PI(cnt),NL;
            else PC("inf\n");
        }
        else PI(cnt),NL;

    }





    return 0;
}
