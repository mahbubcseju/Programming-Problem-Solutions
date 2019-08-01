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
#define mx 10003
#define md 1000000007
#define maxp 2050180000

typedef pair<int,int> P;

////////define value/////

int cnt1[mx+3];
int cnt2[mx+3];
char a[mx+3];
int  z[mx+3];
void zalgo() {
    ll l,r;
    l=r=0;
    z[0]=strlen(a);
    for(ll i=1; i<z[0]; i++) {
        if(i>r) {
            l=r=i;
            for(ll j=i; j<z[0]; j++) {
                if(a[j-i]!=a[j])break;
                else r=j;
            }
            if(a[i]!=a[0])z[i]=0;
            else z[i]=r-l+1;
        } else {
            ll k=i-l;
            if(z[k]<r-i+1) {
                z[i]=z[k];
            } else {
                l=i;
                for(ll j=r+1; j<z[0]; j++) {
                    if(a[j-l]!=a[j])break;
                    else r=j;
                }
                z[i]=r-l+1;
            }

        }
    }
}
char ch[mx+3];
char b[mx+3];

int main() {

    SC("%s",ch);
    SC("%s",b);
    int len=strlen(ch);
    int len1=strlen(b);

    int res=mx;
    for(int i=0; i<len; i++) {
            //if(i!=5)continue;
        int sz=-1;
        for(int j=i; j<len; j++) {
            a[++sz]=ch[j];
        }
        a[++sz]='#';
        int ho=sz+1;
        for(int j=0; j<len; j++)a[++sz]=ch[j];

        a[++sz]='\0';
        SET(z);
        zalgo();
        SET(cnt1);
        for(int j=ho; j<sz; j++) {
               // cout<<z[j]
            cnt1[z[j]]++;
        }
        int ma=0;
        for(int j=mx; j>=1; j--) {
            ma=ma+cnt1[j];
            cnt1[j]=ma;
        }

        // for(int j=1;j<=5;j++)cout<<cnt1[j]<<" "<<endl;
        sz=ho-1;

        for(int j=0; j<len1; j++)a[++sz]=b[j];
        a[++sz]='\0';
        SET(z);
        zalgo();
        SET(cnt2);
        for(int j=ho; j<sz; j++) {
            cnt2[z[j]]++;
            //cout<<z[i]<<endl;
          //  if(z[j]==23)cout<<"lol"<<endl;
        }

        ma=0;

        for(int j=mx; j>=1; j--) {
          ma=ma+cnt2[j];
            cnt2[j]=ma;
            //if(j<=24&&j==23&&cnt2[j]>0)cout<<i<<" "<<j<<endl;

        }
        for(int j=1; j<=mx; j++) {
                //cout<<cnt1[j]<<" "<<cnt2[j]<<endl;
            if(cnt1[j]==1&&cnt2[j]==1)res=min(res,j);
        }
       // if(res==1)cout<<i<<endl;

    }
    if(res==mx)res=-1;
    PI(res);
    return 0;
}
