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
#define mx 100000
#define md 1000000007
#define maxp 2050180000

typedef pair<int,int> P;

////////define value/////
ll tr[mx*3];
ll a[mx*2];
void update(int no,int s,int e) {
    if(s==e) {
      tr[no]=s;
      return ;
    }
    int mid=(s+e)/2;
    update(no*2,s,mid);
    update(no*2+1,mid+1,e);
    if(a[tr[no*2]]>a[tr[no*2+1]])tr[no]=tr[no*2];
    else tr[no]=tr[no*2+1];
   // cout<<s<<" "<<e<<tr[no]<<endl;
}

ll query(int no,int s,int e,int st,int en)
{
    if(s>=st&&e<=en)return tr[no];
    int mid=(s+e)>>1;
    if(mid>=en)return query(no*2,s,mid,st,en);
    else if(mid<st)return query(no*2+1,mid+1,e,st,en);
    else {
            int x=query(no*2,s,mid,st,mid);
           int  y=query(no*2+1,mid+1,e,mid+1,en);
            if(a[x]>a[y])return x;
            else return y;
    }



}
int main() {

    int n;
    I(n);

    for(ll i=1; i<n; i++)L(a[i]);
    a[n]=n;


    ll res=0;
    update(1,1,n);

    ll dp[n+2];
    dp[n]=0;
    for(int j=n-1;j>=1;j--)
    {
       // cout<<j+1<<" "<<a[j]<<" ";
        ll x=query(1,1,n,j+1,a[j]);
       // cout<<x<<" ";
dp[j]=dp[x]-(a[j]-x)+(n-j);
        res+=dp[j];
          //cout<<dp[j]<<endl;
    }
    PL(res);




    return 0;
}