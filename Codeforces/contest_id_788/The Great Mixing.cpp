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
#define mx 200000ll
#define md 1000000007
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<int , int > P;
typedef vector<int> V;
//////////////////////////
/////////////////////////

int fr[200002];
int ba[200004];
int main()
{

    int n,m;
    I2(n,m);

    int a[m+2];

    int b[1002],c[1002];

    int l1=0,l2=0;
set<int>st;
    for(int i=1;i<=m;i++)
    {
        int x;
        I(x);
        x-=n;
        st.insert(x);

    }

    for(auto i:st)
    {
       if(i<0)
       {
           b[++l1]=-i;
       }
       else c[++l2]=i;
    }
    sort(b+1,b+l1+1);
    sort(c+1,c+l2+1);
    if(b[1]==0&&l1>=1){
        PI(1),NL;
        return 0;
    }
     if(c[1]==0&&l2>=1){
        PI(1),NL;
        return 0;
    }


    for(int i=1;i<=mx;i++)fr[i]=1e9,ba[i]=1e9;
    for(int i=1;i<=mx ;i++)
    {
        for(int j=1;j<=l1;j++)
        {
           // cout<<b[j]<<" "<<endl;
          // if(i==50)cout<<fr[i-25]<<" "<<b[j]<<endl;
            if(b[j]<=i)fr[i]=min(fr[i],fr[i-b[j]]+1);
           // if(i==50)cout<<
        }
    }
  //  cout<<fr[50]<<endl;
    for(int i=1;i<=mx ;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(c[j]<=i)ba[i]=min(ba[i],ba[i-c[j]]+1);
        }
    }
//    cout<<ba[50]<<endl;

    int ans=1e9;

    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            int x=b[i]/gcd(b[i],c[j]);
            int y=c[j]/gcd(b[i],c[j]);
            ans=min(ans,x+y);
        }
    }

  // cout<<l1<<" "<<l2<<endl;
    for(int i=1;i<=mx;i++)
    {
        ans=min(ans,fr[i]+ba[i]);
       // cout<<fr[i]<<" "<<ba[i]<<endl;
    }
    if(ans>=1e9)PI(-1),NL;
    else
    PI(ans),NL;




    return 0;
}
