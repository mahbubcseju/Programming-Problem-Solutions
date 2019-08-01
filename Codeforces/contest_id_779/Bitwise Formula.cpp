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
#define mx 2000000
#define md 23377788ll
#define md1 1000000007ll
#define maxp 2050180000
#define LO(X) X[p][k]
#define base 29

typedef pair<string,string>P;
//////////////////////////
/////////////////////////
int main() {

    int n,m;
    I2(n,m);

    int re[2][m+2];
    SET(re);
    map<string ,int>mp;
    string a,b,c,x;
    int  ara[2][n+2][m+2];
    for(int i=1; i<=n; i++) {

        do {
            getline(cin,x);
        } while(x.size()==0);

        istringstream is(x);

        vector<string>v;

        while(is>>a) {
            v.PB(a);
        }

        int l=v.size();
        if(l==3) {
            if(v[2][0]=='0'||v[2][0]=='1') {
                mp[v[0]]=i;

                fr(j,0,m-1)ara[0][i][j]=ara[1][i][j]=v[2][j]-'0';
                // ara[i]=mk(v[2],v[2]);
            } else {
                mp[v[0]]=i;
              //  ara[i]=ara[mp[v[2]]];
                fr(j,0,m-1) {
                    ara[0][i][j]=ara[0][mp[v[2]]][j];
                    ara[1][i][j]=ara[1][mp[v[2]]][j];
                }

//                fr(j,0,m-1) {
//                    if(mp[v[0]].x[j]=='1')re[0][j]++;
//                    if(mp[v[0]].y[j]=='1')re[1][j]++;
//                }
            }
        } else {
            string y=v[2];
            string z=v[4];

            fr(j,0,m-1) {
                int b1=0;
                int c1=0;
                if(y[0]!='?')b1=ara[0][mp[y]][j];
                if(z[0]!='?')c1=ara[0][mp[z]][j];
                int res=0;
                if(v[3][0]=='A')res=b1&c1;
                else if(v[3][0]=='O')res=b1|c1;
                else res=b1^c1;
                re[0][j]+=res;
                ara[0][i][j]=res;

                res=0;
                b1=1;
                c1=1;
                if(y[0]!='?')b1=ara[1][mp[y]][j];
                if(z[0]!='?')c1=ara[1][mp[z]][j];
                if(v[3][0]=='A')res=b1&c1;
                else if(v[3][0]=='O')res=b1|c1;
                else res=b1^c1;
                re[1][j]+=res;
                ara[1][i][j]=res;

                mp[v[0]]=i;
              //  ara[i]=mk(h,h1);
                //  cout<<h<<" "<<h1<<endl;
            }

        }
    }

    fr(i,0,m-1) {
        if(re[0][i]<=re[1][i])PC("0");
        else PC("1");
    }
    NL;
    fr(i,0,m-1) {
        if(re[0][i]>=re[1][i])PC("0");
        else PC("1");
    }
    NL;
    return 0;
}
