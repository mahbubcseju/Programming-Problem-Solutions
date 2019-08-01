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

typedef pair<pair<int,int>,char> P;

////////define value/////
int n,a[100004],m;
vector<int>v[mx+2];
int ans=0;
void dfs(int i,int p,int cnt,bool fl) {
    if(a[i]==1&&a[p]==1)cnt++;
    else if(a[i]==1)cnt=1;
    if(cnt>m)fl=1;
    bool fl1=0;
    for(int j=0; j<v[i].size(); j++) {
        int x=v[i][j];
        if(x==p)continue;
        fl1=1;
        dfs(x,i,cnt,fl);

    }
    if(fl1==0&&fl==0)ans++;

}
pair<int,int>change(int x,int y,int op) {
    if(op==0)return make_pair(x,y);
    else {
        swap(x,y);
        return make_pair(x,y);
    }
}
int main() {

    P a,b,c;
    I2(a.xx,a.xy);
    I2(b.xx,b.xy);
    I2(c.xx,c.xy);
    if(a.xx>a.xy)swap(a.xx,a.xy);
    if(b.xx>b.xy)swap(b.xx,b.xy);
    if(c.xx>c.xy)swap(c.xx,c.xy);
    int res=a.xx*a.xy+b.xx*b.xy+c.xx*c.xy;
    a.y='A';
    b.y='B';
    c.y='C';
    int sq=sqrt(res);

    if(sq*sq==res) {

        if(b.xy==sq)swap(a,b);
        if(c.xy==sq)swap(a,c);


        int x=sq-a.xx;
        int y=sq;

        for(int i=0; i<=1; i++) {
            for(int j=0; j<=1; j++) {
                pair<int,int>x1=change(b.xx,b.xy,i);
                pair<int,int>x2=change(c.xx,c.xy,j);
                if(x1.y+x2.y==y&&x1.x==x&&x2.x==x) {
                    cout<<sq<<endl;
                    for(int i=1; i<=a.xx; i++) {
                        for(int j=1; j<=sq; j++)PC("%c",a.y);
                        NL;
                    }
                    for(int l=1; l<=x; l++) {
                        for(ll k=1; k<=y; k++) {
                            if(k<=x1.y)PC("%c",b.y);
                            else PC("%c",c.y);
                        }
                        NL;
                    }
                    return 0;
                } else if(x1.y==y&&x2.y==y&&x1.x+x2.x==x) {
                    cout<<sq<<endl;
                    for(int i=1; i<=a.xx; i++) {
                        for(int j=1; j<=sq; j++)PC("%c",a.y);
                        NL;
                    }
                    for(int l=1; l<=x; l++) {
                        for(ll k=1; k<=y; k++) {
                            if(l<=x1.x)PC("%c",b.y);
                            else PC("%c",c.y);
                        }
                        NL;
                    }
                    return 0;

                }

            }
        }
    }


    PI(-1);


    return 0;
}
