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
int n;
int a[mx+4];
double cum[mx+2];
double his(ll mid,ll ko) {
    double x=cum[n]-cum[n-ko];
    x+=cum[mid]-cum[mid-1-ko];
  // cout<<x<<endl;
    x=x/(double)(2*(double)ko+1);
    x-=(double)a[mid];

    return x;

}
int main() {
    I(n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);

    cum[0]=0;
    for(ll i=1; i<=n; i++) {
        cum[i]=(cum[i-1]+(double)a[i]);
    }
  //;
    double  res=0;
    int in=1;
    int num=0;
    for(int i=1; i<=n; i++) {
        int x1=min(i-1,n-i);
        int lo=1;
        int hi=x1;
        for(int j=1; j<=200; j++) {
            int x=(hi-lo)/3;
            int mid=(lo+x);
            int mid1=(hi-x);
            double val=his(i,mid);
            double val1=his(i,mid1);
            if(val<val1)lo=mid;
            else hi=mid1;

        }
        lo=max(0,lo-10);
        hi=min(x1,hi+10);
        assert(hi-lo<=100);
       // cout<<i<<" "<<lo<<" "<<hi<<x1<<endl;

        for(int j=lo; j<=hi; j++) {
            double ho=his(i,j);
           // cout<<" "<<ho<<endl;
            if(ho>res) {
                res=ho;
                in=i;
                num=j;
            }
        }
//          if(n==194321&&i==4277){
//                cout<<lo<<" "<<hi<<endl;
//            cout<<in<<endl;
//          cout<<num<<endl;
//        printf("%.10lf\n",his(in,num));
//      printf("%.10lf\n",his(in,num-1));
//    }
       // if(n==194321&&num*2+1==8529)cout<<lo<<" "<<hi<<endl;

    }
    // cout<<in<<" "<<num<<endl;

    int lo=in-num;
    int hi=in+num;
    cout<<hi-lo+1<<endl;
    int ar[hi-lo+2];
    int sz1=0;
    for(int i=lo; i<=in; i++) {

        ar[++sz1]=a[i];
    }
    for(int j=n; j>n-num; j--)ar[++sz1]=a[j];
    for(int i=1; i<=sz1; i++) {
        if(i==1)printf("%d",ar[i]);
        else printf(" %d",ar[i]);
    }
    NL;



    return 0;
}
